#include "scene.h"

#include <conio.h>
#include <iostream>

#pragma execution_character_set("utf-8")

const int GAME_WIDTH = 1024, GAME_HEIGHT = 768;
extern const int EMPTY;
extern const int WALL;
extern const int BIRTH;

Scene::Scene(int h, int w)
{
	player = getPlayer(1);
	player_pos_x = player_pos_y = boundary;
	width = w;
	height = h;

	tiles.resize(height + 2 * boundary);
	for (int i = 0; i < height + 2 * boundary; ++i)
	{
		tiles[i].resize(width + 2 * boundary);
		for (int j = 0; j < width + 2 * boundary; ++j)
		{
			tiles[i][j] = new Tile;
		}
	}

	initSceneByNum({ 20, 20, 0, 0 });
}

Scene::Scene(std::vector < std::vector<int> >& scene)
{
	player = getPlayer(1);


	height = (int)scene.size()-2;
	width = (int)scene[0].size() - 2;
	tiles.resize(height + 2 * boundary);
	for (int i = 0; i < height + 2 * boundary; ++i)
	{
		tiles[i].resize(width + 2 * boundary);
		for (int j = 0; j < width + 2 * boundary; ++j)
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
}

void Scene::move(direction dir)
{
	// Todo: 向四个方向移动，使用button/键盘交互
	tiles[player_pos_x][player_pos_y]->modify_visited();
	switch (dir)
	{
	case LEFT: player_pos_x = max(player_pos_x - 1, boundary);  break;
	case RIGHT: player_pos_x = min(player_pos_x + 1, height + boundary - 1); break;
	case UP: player_pos_y = max(player_pos_y -1, boundary); break;
	case DOWN: player_pos_y = min(player_pos_y +1, width + boundary - 1);  break;
	}
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
	for (int h = 0; h < height + 2 * boundary; ++h)
	{
		for (int w = 0; w < width + 2 * boundary; ++w)
		{
			if (h < boundary ||
				h >= height + boundary ||
				w < boundary ||
				w >= width + boundary)
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
	for (int h = 0; h < height + 2 * boundary; ++h)
	{
		for (int w = 0; w < width + 2 * boundary; ++w)
		{
			if (h < boundary ||
				h >= height + boundary ||
				w < boundary ||
				w >= width + boundary)
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
	for (int i = 0; i < height + 2 * boundary; ++i)
		for (int j = 0; j < width + 2 * boundary; ++j)
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
