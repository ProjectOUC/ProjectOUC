#define _CRT_SECURE_NO_WARNINGS
#include "gaming.h"

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
			std::cout << "����" << tile->monsters[i]->get_name() << "\n";
			std::cout << "HP: " << tile->monsters[i]->get_health() << "\natk: " << tile->monsters[i]->calc_min_attack()
				<< "-" << tile->monsters[i]->calc_max_attack()
				<<"\ndef: " << tile->monsters[i]->get_defense() << "\n";
			Battle battle((Character*)tile->monsters[i], (Character*)player);

			if (!battle.battle())
			{
				return;
			}
			std::cout << "սʤ" << tile->monsters[i]->get_name() << "\n" <<
				"�������: " << player->calc_maxHealth() <<
				"\nʣ������: " << player->get_health() <<
				"\n����: " << player->get_defense() <<
				"\n����: " << player->calc_min_attack() << "-" << player->calc_max_attack() <<
				"\n�ٶ�: " << player->get_speed() <<
				"\n����: " << player->get_strength() <<
				"\n����: " << player->get_agility() <<
				"\n����: " << player->get_wisdom() <<
				"\n����: " << player->get_hitRate() <<
				"\n����: " << player->get_missRate() <<
				"\n��: " << player->calc_block() <<
				"\n\n��ǰ����: " << player->get_exp() <<
				"\n��������: " << player->get_levelUpExp() <<
				"\n�ȼ�: " << player->get_level() <<
				"\n\n��ǰʳ��: " << player->get_food() <<
				"\n���ʳ��: " << player->calc_food_capacity() << "\n\n";
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
			player->gadgets[findGadget("Key")]--;
			player->modify_moved(true);
			for (int i = 0; i < tile->chests.size(); ++i)
			{

				std::cout << "��" << tile->chests[i]->get_name() << "\n";
				Battle battle((Character*)tile->chests[i], (Character*)player);
				if (!battle.battle())
				{
					return;
				}
				std::cout << "���" << tile->chests[i]->get_coin() << "ͭ��\n";
				std::cout << "��ǰ��Ǯ: " << player->get_coin() << "\n\n";
			}
			tile->chests.clear();
			tile->modify_type(EMPTY_TILE);
		}
		else
		{
			player->modify_moved(false);
			player->moveTo(player->get_lastPos());
			player->modify_food(pos.stage);
			std::cout << "û��Կ�ף��޷��򿪱���\n";
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

	else if (tile->get_type() == DOOR_TILE)
	{
		if (player->gadgets[findGadget("Key")] > 0)
		{
			player->modify_moved(true);
			player->gadgets[findGadget("Key")]--;
			tile->modify_type(EMPTY_TILE);
		}
		else
		{
			std::cout << "�޷�����\n";
			player->modify_moved(false);
			player->moveTo(player->get_lastPos());
			player->modify_food(pos.stage);
		}
	}

	else if (tile->get_type() == EVENT_TILE)
	{
		player->modify_moved(false);
		player->moveTo(player->get_lastPos());
		player->modify_food(pos.stage);
		tile->event->occurEvent((Character**)(&player));
		std::cout << tile->event->getEventDescription() << "\n";
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
			
			fprintf(fp, "refresh\n");
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

			fprintf(fp, "dist\n");
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
			fprintf(fp, "tiles\n");
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
	����: ���ش浵
	����: 
	- saveIndex: ѡ��Ĵ浵
		- 0: �Զ��浵
		- k: �浵k, ·��Ϊinit/scene<k>, ��<k>�滻Ϊ�ַ�k����

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