#include "scene.h"

#include <conio.h>
#include <iostream>
#include <queue>

#pragma execution_character_set("utf-8")

const int GAME_WIDTH = 1024, GAME_HEIGHT = 768;
extern const int EMPTY;
extern const int WALL;
extern const int BIRTH;
extern const int FILLED;

Scene::Scene(int h, int w)
{
	player = getPlayer(1);
	player_pos_x = player_pos_y = boundary;
	
	width = w;
	height = h;

	tiles.resize(height);
	for (int i = 0; i < height; ++i)
	{
		tiles[i].resize(width);
		for (int j = 0; j < width; ++j)
		{
			tiles[i][j] = new Tile;
		}
	}

	initSceneByNum({ 20, 20, 0, 0 });
}

Scene::Scene(std::vector < std::vector<int> > scene, int _scene_type) :
	scene_type(_scene_type)
{
	player = getPlayer(1);
	player_pos_x = player_pos_y = last_x = last_y = 0;


	height = (int)scene.size();
	width = (int)scene[0].size();
	tiles.resize(height);
	for (int i = 0; i < height; ++i)
	{
		tiles[i].resize(width);
		for (int j = 0; j < width; ++j)
		{
			tiles[i][j] = new Tile;
			if (scene[i][j] == WALL) tiles[i][j]->initWallTile();
			else if (scene[i][j] == EMPTY) tiles[i][j]->initEmptyTile();
			else if (scene[i][j] == BIRTH)
			{
				player_pos_x = i;
				player_pos_y = j;
				tiles[i][j]->initEmptyTile();
			}
		}
	}

	std::vector<std::vector<int>> dist(height, std::vector<int>(width, 0));
	dist[player_pos_x][player_pos_y] = 1;
	std::queue<int> qx, qy, qdist;
	qx.push(player_pos_x), qy.push(player_pos_y), qdist.push(1);
	const static int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
	while (!qx.empty())
	{
		int x = qx.front(), y = qy.front(), dis = qdist.front();
		qx.pop(), qy.pop(), qdist.pop();
		for (int d = 0; d < 4; ++d)
		{
			if (scene[x + dx[d]][y + dy[d]] == WALL || dist[x+dx[d]][y+dy[d]] != 0) continue;
			qx.push(x + dx[d]), qy.push(y + dy[d]), qdist.push(dis+1);
			dist[x + dx[d]][y + dy[d]] = dis + 1;
		}
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (scene[i][j] == WALL) continue;
			else if (dist[i][j] <= 5) tiles[i][j]->initEmptyTile();
			else
			{
				if (scene[i][j] == MONSTER) tiles[i][j]->initBattleTile();
				else if (scene[i][j] == FILLED)
				{
					if (oneIn(2)) tiles[i][j]->initEmptyTile();
					else if (oneIn(2)) tiles[i][j]->initChestTile();
					else tiles[i][j]->initBattleTile();
				}
			}
		}
	}

}

void Scene::move(direction dir)
{
	// Todo: 向四个方向移动，使用button/键盘交互
	tiles[player_pos_x][player_pos_y]->modify_visited();
	last_x = player_pos_x, last_y = player_pos_y;
	switch (dir)
	{
	case LEFT: player_pos_x = player_pos_x - 1;  break;
	case RIGHT: player_pos_x = player_pos_x + 1; break;
	case UP: player_pos_y = player_pos_y -1; break;
	case DOWN: player_pos_y = player_pos_y +1;  break;
	}
	if (tiles[player_pos_x][player_pos_y]->get_unreachable())
	{
		player_pos_x = last_x;
		player_pos_y = last_y;
	}
	std::cout << "生命值: " << get_player()->get_health() << " 攻击: "
		<< get_player()->get_attack() << " 防御: " << get_player()->get_defense() << "\n";

}

void Scene::moveTo(int x, int y)
{
	last_x = player_pos_x, last_y = player_pos_y;
	if (tiles[x][y]->get_unreachable()) return;
	player_pos_x = x, player_pos_y = y;
}

bool Scene::checkTile()
{
	SetConsoleOutputCP(CP_UTF8);
	Tile* tile = tiles[player_pos_x][player_pos_y];
	if (tile->get_type() == WALL_TILE)
	{
		return false;
	}

	else if (tile->get_type() == BATTLE_TILE)
	{
		
		for (int i = 0; i < tile->monsters.size(); ++i)
		{
			//std::cout << i+1 <<  " " << tile->monsters[i].get_health() << " "
			//	<< tile->monsters[i].get_attack() << " " << tile->monsters[i].get_defense() << "\n";
			std::cout << "遭遇" << tile->monsters[i]->get_name() << "\n";
			std::cout << "HP: " << tile->monsters[i]->get_health() << "\natk: " << tile->monsters[i]->get_attack();
			std::cout << "\ndef: " << tile->monsters[i]->get_defense() << "\n";
			Battle battle((Character*)tile->monsters[i], (Character*)player);

			if (!battle.battle())
			{
				return false;
			}
			std::cout << "战胜" << tile->monsters[i]->get_name() << "\n";
			std::cout << "剩余生命: " << player->get_health() << 
				"\n防御: " << player->get_defense() << 
				"\n攻击: " << player->get_attack() << "\n\n";
		}
		tile->monsters.clear();
		tile->modify_type(EMPTY_TILE);
		return true;
	}

	else if (tile->get_type() == EMPTY_TILE)
	{
		return true;
	}

	else if (tile->get_type() == CHEST_TILE)
	{
		for (int i = 0; i < tile->chests.size(); ++i)
		{
			//std::cout << i+1 <<  " " << tile->monsters[i].get_health() << " "
			//	<< tile->monsters[i].get_attack() << " " << tile->monsters[i].get_defense() << "\n";
			std::cout << "打开" << tile->chests[i]->get_name() << "\n";
			Battle battle((Character*)tile->chests[i], (Character*)player);
			if (!battle.battle())
			{
				return false;
			}
			std::cout << "获得" << tile->chests[i]->get_coin() << "铜币\n";
			std::cout << "当前金钱: " << player->get_coin() << "\n\n";
			//std::cout << player.get_health() << "\n";
		}
		tile->chests.clear();
		tile->modify_type(EMPTY_TILE);
		return true;
	}
	return false;
}

void Scene::initScene()
{
	for (int h = 0; h < height; ++h)
	{
		for (int w = 0; w < width; ++w)
		{
			if (h < boundary ||
				h + boundary >= height ||
				w < boundary ||
				w + boundary >= width)
			{
				tiles[h][w]->initWallTile();
			}
			else
			{
				// Todo: 添加更多种类的Tile
				tiles[h][w]->initEmptyTile();
			}
		}
	}

	// 以下均用于测试

	tiles[2][2]->initBattleTile();
	tiles[1][4]->initBattleTile();
	tiles[3][1]->initBattleTile();
	tiles[6][1]->initBattleTile();
	tiles[2][1]->initBattleTile();
	tiles[4][4]->initBattleTile();
	tiles[2][3]->initChestTile();
	tiles[3][3]->initChestTile();
}

void Scene::initSceneByNum(std::vector<int> num)
{
	static std::vector<tile_type> types
	{
		BATTLE_TILE,
		CHEST_TILE,
		EVENT_TILE,
		WALL_TILE,
		EMPTY_TILE
	};

	int k = 0;
	for (int n : num) k += n;
	num.push_back(height * width - k);

	srand((unsigned int)time(0));
	int pivot = 0;
	int rem = height * width;
	srand((unsigned int)time(0));
	for (int h = 0; h < height; ++h)
	{
		for (int w = 0; w < width; ++w)
		{
			if (h < boundary ||
				h + boundary >= height ||
				w < boundary ||
				w + boundary >= width)
			{
				tiles[h][w]->initWallTile();
			}
			else if (h == player_pos_x && w == player_pos_y)
			{
				num[num.size() - 1]--;
				rem--;
				tiles[h][w]->initEmptyTile();
			}
			else
			{
				
				pivot = 0;
				int rd = rand() % rem;
				int su = 0;
				while (su <= rd)
				{
					su = su + num[pivot];
					if (su > rd)
					{
						num[pivot]--;
						tiles[h][w]->initTile(types[pivot]);
						rem--;
						break;
					}
					pivot++;
				}
			}
		}
	}
}

Scene::~Scene()
{
	delete player;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			delete tiles[i][j];
};

void SwitchToWindow(window_type t)
{
	cleardevice();
	switch (t)
	{
	case BAG_WINDOW: SwitchToBagWindow(); break;
	case MAIN_WINDOW: SwitchToMainWindow(); break;
	case MAP_WINDOW: SwitchToMapWindow(); break;
	default: break;
	}
}

void SwitchToBagWindow()
{
	//Todo
	;
}

void SwitchToBattleWindow()
{
	//Todo
	;
}

void SwitchToMainWindow()
{
	line(0, 100, GAME_WIDTH, 100);
	line(100, 0, 100, GAME_HEIGHT);
	outtextxy(105, 0, _T("你好"));
}

void SwitchToMapWindow()
{
	//Todo
	;
}
