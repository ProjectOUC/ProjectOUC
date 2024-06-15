#define _CRT_SECURE_NO_WARNINGS
#include "gaming.h"

extern std::vector<Event*> trapList;

void checkTile(std::vector<Scene*>& scenes, Player* player)
{
	SetConsoleOutputCP(CP_UTF8);
	Position pos = player->get_pos();
	if (player->get_attr().teleport)
	{
		player->moveTo(scenes[0]->get_startPos());
		player->set_teleport(false);
		return;
	}
	if (pos.stage < 0 || pos.stage >= scenes.size())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(player->get_pos().stage);
		return;
	}
	Scene* scene = scenes[pos.stage];
	if (pos.x <= 0 || pos.y <= 0 || pos.x >= scene->get_height() || pos.y >= scene->get_width())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(pos.stage);
		return;
	}

	Tile* tile = scene->get_tiles(pos.x, pos.y);
	if (tile->get_unreachable())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(pos.stage);
		return;
	}

	
	if (tile->get_type() == WALL_TILE)
	{
		player->modify_moved(false);
	}

	else if (tile->get_type() == BATTLE_TILE)
	{
		player->modify_moved(true);
		for (int i = 0; i < tile->monsters.size(); ++i)
		{
			std::cout << "遭遇" << tile->monsters[i]->get_name() << "\n";
			std::cout << "HP: " << tile->monsters[i]->get_health() << "\natk: " << tile->monsters[i]->calc_min_attack()
				<< "-" << tile->monsters[i]->calc_max_attack()
				<<"\ndef: " << tile->monsters[i]->get_defense() << "\n";
			Battle battle((Character*)tile->monsters[i], (Character*)player);

			if (!battle.battle())
			{
				return;
			}
			std::cout << "战胜" << tile->monsters[i]->get_name() << "\n" <<
				"最大生命: " << player->calc_maxHealth() <<
				"\n剩余生命: " << player->get_health() <<
				"\n防御: " << player->get_defense() <<
				"\n攻击: " << player->calc_min_attack() << "-" << player->calc_max_attack() <<
				"\n速度: " << player->get_speed() <<
				"\n力量: " << player->get_strength() <<
				"\n敏捷: " << player->get_agility() <<
				"\n智力: " << player->get_wisdom() <<
				"\n命中: " << player->get_hitRate() <<
				"\n闪避: " << player->get_missRate() <<
				"\n格挡: " << player->calc_block() <<
				"\n\n当前经验: " << player->get_exp() <<
				"\n升级经验: " << player->get_levelUpExp() <<
				"\n等级: " << player->get_level() <<
				"\n\n当前食物: " << player->get_food() <<
				"\n最大食物: " << player->calc_food_capacity() << "\n\n";
		}
		tile->monsters.clear();
		tile->modify_type(EMPTY_TILE);
	}

	else if (tile->get_type() == EMPTY_TILE)
	{
		player->modify_moved(true);
	}

	else if (tile->get_type() == CHEST_TILE)
	{
		if (player->gadgets[findGadget("Key")] > 0)
		{
			std::cout << player->gadgets[findGadget("Key")] << "key\n";
			player->gadgets[findGadget("Key")]--;
			player->modify_moved(true);
			for (int i = 0; i < tile->chests.size(); ++i)
			{

				std::cout << "打开" << tile->chests[i]->get_name() << "\n";
				Battle battle((Character*)tile->chests[i], (Character*)player);
				if (!battle.battle())
				{
					return;
				}
				std::cout << "获得" << tile->chests[i]->get_coin() << "铜币\n";
				std::cout << "当前金钱: " << player->get_coin() << "\n\n";
			}
			tile->chests.clear();
			tile->modify_type(EMPTY_TILE);
		}
		else
		{
			player->modify_moved(false);
			player->moveTo(player->get_lastPos());
			player->modify_food(pos.stage);
			std::cout << "没有钥匙，无法打开宝箱\n";
		}
	}

	else if (tile->get_type() == START_TILE)
	{
		if (player->get_moved() && pos.stage > 0)
		{
			player->moveTo(scenes[pos.stage - 1]->get_endPos());
			pos = player->get_pos();
			scenes[pos.stage]->refreshMonsters();
		}
		player->modify_moved(false);
		
	}
	else if (tile->get_type() == END_TILE)
	{
		if (player->get_moved() && pos.stage < scenes.size() - 1)
		{
			player->moveTo(scenes[pos.stage + 1]->get_startPos());
			pos = player->get_pos();
			scenes[pos.stage]->refreshMonsters();
		}
		player->modify_moved(false);
	}

	else if (tile->get_type() == EVENT_TILE)
	{
		player->modify_moved(false);
		player->moveTo(player->get_lastPos());
		player->modify_food(pos.stage);
		tile->event->occurEvent((Character**)(&player));
		if (tile->event->isDisappear()) tile->initEmptyTile();
	}

	return;
}

void saveGame(std::vector<Scene*>& scenes, Player* player, bool autoSave)
{
	FILE* fp;
	std::string pathPrefix = autoSave ? "init/autoSave-" : "init/";
	for (int i = 0; i < 5; ++i)
	{
		std::string path = pathPrefix + "scene" + std::to_string(i);
		Scene* scene = scenes[i];
		if ((fp = fopen(path.c_str(), "w")) != nullptr)
		{
			switch (scene->get_scene_type())
			{
			case Scene::TOWN: fprintf(fp, "TOWN\n"); break;
			case Scene::CAVE: fprintf(fp, "CAVE\n"); break;
			case Scene::MAZE: fprintf(fp, "MAZE\n"); break;
			}

			fprintf(fp, "height: %d\n", scene->get_height());
			fprintf(fp, "width: %d\n", scene->get_width());
			fprintf(fp, "stage: %d\n", scene->get_startPos().stage);
			fprintf(fp, "storage\n");
			fprintf(fp, "startPos: %d %d\n", scene->get_startPos().x, scene->get_startPos().y);
			fprintf(fp, "endPos: %d %d\n", scene->get_endPos().x, scene->get_endPos().y);
			
			fprintf(fp, "refresh: \n");
			int h = scene->get_height(), w = scene->get_width();
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					if (j != 0) fprintf(fp, " ");
					fprintf(fp, "%d", scene->get_refresh(i, j));
				}
				fprintf(fp, "\n");
			}

			fprintf(fp, "dist: \n");
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					if (j != 0) fprintf(fp, " ");
					fprintf(fp, "%d", scene->get_dist(i, j));
				}
				fprintf(fp, "\n");
			}

			int eventCount = 0;
			fprintf(fp, "tiles: \n");
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					if (j != 0) fprintf(fp, " ");
					fprintf(fp, "%d", scene->get_tiles(i, j)->get_type());
					if (scene->get_tiles(i, j)->get_type() == EVENT_TILE)
						eventCount++;
				}
				fprintf(fp, "\n");
			}

			fprintf(fp, "visited: \n");
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					if (j != 0) fprintf(fp, " ");
					fprintf(fp, "%d", scene->visited[i][j]);
				}
				fprintf(fp, "\n");
			}

			fprintf(fp, "Event:%d\n", eventCount);
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					Tile* tile = scene->get_tiles(i, j);
					if (tile->get_type() != EVENT_TILE) continue;
					fprintf(fp, "Event:\n");
					fprintf(fp, "%d %d\n", i, j);
					fprintf(fp, "%s\n", (tile->event->getEventPath()).c_str());
				}

			}
		}
		fclose(fp);
	}

	std::string path = pathPrefix + "player";
	player->saveCharacter(path);
}

void loadGame(int saveIndex, std::vector<Scene*>& scenes, Player** player)
{
	/*
	功能: 加载存档
	参数: 
	- saveIndex: 选择的存档
		- 0: 自动存档
		- k: 存档k, 路径为init/scene<k>, 将<k>替换为字符k即可

	*/

	FILE* fp;
	std::string pathPrefix = saveIndex ? "init/" : "init/autoSave-";
	for (int i = 0; i < 5; ++i)
	{
		std::string path = pathPrefix + "scene" + std::to_string(i);
		Scene* scene = scenes[i];
		if ((fp = fopen(path.c_str(), "r")) == nullptr)
		{
			std::cout << "save file doesn't exist.\n";
			exit(0);
		}
		fclose(fp);

		scenes[i] = new Scene(path);
	}
	std::string path = pathPrefix + "player";
	if ((fp = fopen(path.c_str(), "r")) == nullptr)
	{
		std::cout << "save file doesn't exist.\n";
		exit(0);
	}
	*player = new Player(path);
}

bool canSee(int x1, int y1, int x2, int y2, Scene* scene)
{
		float dx = x2 - x1;
		float dy = y2 - y1;
		float cx = x1 + 0.5f, cy = y1 + 0.5f;
		float cpx = x2 + 0.5f, cpy = y2 + 0.5f;
		float step = 8.0f * max(fabs(dx), fabs(dy));
		dx = dx / step;
		dy = dy / step;
		for (int i = 0; i < step; ++i)
		{
			cx = cx + dx;
			cy = cy + dy;
			if ((int)floor(cx) == x2 && (int)floor(cy) == y2) return true;
			if (scene->get_tiles((int)floor(cx), (int)floor(cy))->get_type() == WALL_TILE) return false;
		} 
		return true;
}

void updateLight(std::vector<Scene*>& scenes, Player* player)
{
	static Position lastPos;
	static Position curPos;
	if (curPos == player->get_pos()) return;
	curPos = player->get_pos();
	lastPos = player->get_lastPos();
	int vr = player->get_visibleRadius();

	int stage;
	Scene* scene;
	stage = lastPos.stage;
	scene = scenes[stage];
	if (curPos.stage != lastPos.stage) lastPos = curPos;
	for (int x = lastPos.x - vr; x <= lastPos.x + vr; ++x)
		for (int y = lastPos.y - vr; y <= lastPos.y + vr; ++y)
			if (x >= 0 && y >= 0 && x < scene->get_width() && y < scene->get_height())
				scene->light[x][y] = scene->visited[x][y] ? Scene::lmin : 0.0f;

	float cpx = curPos.x + 0.5f, cpy = curPos.y + 0.5f;
	for (int x = curPos.x - vr; x <= curPos.x + vr; ++x)
	{
		for (int y = curPos.y - vr; y <= curPos.y + vr; ++y)
		{
			if (x >= 0 && y >= 0 && x < scene->get_width() && y < scene->get_height())
			{
				if (scene->visited[x][y]) continue;
				float dis = pow(x - curPos.x, 2) + pow(y - curPos.y, 2);
				dis = sqrt(dis);
				if (dis > vr) continue;

				if (canSee(curPos.x, curPos.y, x, y, scene))
				{
					scene->visited[x][y] = 1;
					scene->light[x][y] = Scene::lmin + (1.0f - Scene::lmin) * dis / vr;
				}
				else
				{
					scene->light[x][y] = scene->visited[x][y] ? Scene::lmin : 0;
				}
			}
		}
	}

	scene->light[curPos.x][curPos.y] = 1;
}

void randomEvent(Player** player)
{
	Player* p = *player;
	static int lastTime = 1;
	const static int C = 38; //5%
	const int maxNum = 10000;
	static Position pos;
	if (pos == p->get_pos()) return;
	pos = p->get_pos();
	if (pos.stage == 0) return;
	if (!p->get_moved()) return;
	if (aInb(C * lastTime, maxNum))
	{
		//Todo
		//	放一个事件
		int rd = random(1, trapList.size()) - 1;
		trapList[rd]->occurEvent((Character**)player);
		lastTime = 1;
	}
	else
	{
		lastTime++;
	}
}