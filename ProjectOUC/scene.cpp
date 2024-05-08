#include "scene.h"

#include <conio.h>
#include <iostream>

#pragma execution_character_set("utf-8")




void Scene::move(direction dir)
{
	// Todo: 向四个方向移动，使用button/键盘交互
	tiles[player_pos_x][player_pos_y].modify_visited();
	switch (dir)
	{
	case LEFT: player_pos_y = max(player_pos_y - 1, boundary);  break;
	case RIGHT: player_pos_y = min(player_pos_y + 1, width + boundary - 1); break;
	case UP: player_pos_x = min(player_pos_x + 1, height + boundary - 1); break;
	case DOWN: player_pos_x = max(player_pos_x - 1, boundary);  break;
	}
}

bool Scene::checkTile()
{
	SetConsoleOutputCP(CP_UTF8);
	Tile* tile = &tiles[player_pos_x][player_pos_y];
	if (tile->get_type() == WALL_TILE)
	{
		std::cout << "这是一个错误，不应该走到这个格子上\n";
		return false;
	}
	else if (tile->get_type() == BATTLE_TILE)
	{
		
		for (int i = 0; i < tile->monsters.size(); ++i)
		{
			//std::cout << i+1 <<  " " << tile->monsters[i].get_health() << " "
			//	<< tile->monsters[i].get_attack() << " " << tile->monsters[i].get_defense() << "\n";
			std::cout << "遭遇" << tile->monsters[i].get_name() << "\n";
			Battle battle(tile->monsters[i], player);
			if (!battle.battle())
			{
				return false;
			}
			std::cout << "战胜" << tile->monsters[i].get_name() << "\n";
			std::cout << "剩余生命: " << player.get_health() << " 防御: " << player.get_defense() << " 攻击: " << player.get_attack() << "\n\n";
		}
		tile->monsters.clear();
		tile->modify_type(EMPTY_TILE);
		return true;
	}
	else if (tile->get_type() == EMPTY_TILE)
	{
		std::cout << "Nothing there\n";
		return true;
	}
	else if (tile->get_type() == CHEST_TILE)
	{
		for (int i = 0; i < tile->chests.size(); ++i)
		{
			//std::cout << i+1 <<  " " << tile->monsters[i].get_health() << " "
			//	<< tile->monsters[i].get_attack() << " " << tile->monsters[i].get_defense() << "\n";
			std::cout << "打开" << tile->chests[i].get_name() << "\n";
			Battle battle(tile->chests[i], player);
			if (!battle.battle())
			{
				return false;
			}
			std::cout << "获得" << tile->chests[i].get_coin() << "铜币\n";
			std::cout << "当前金钱: " << player.get_coin() << "\n\n";
			//std::cout << player.get_health() << "\n";
		}
		tile->chests.clear();
		tile->modify_type(EMPTY_TILE);
		return true;
	}
	return false;
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

	srand(time(0));
	int pivot = 0;
	for (int i = boundary; i < height + boundary; ++i)
	{
		for (int j = boundary; j < width + boundary; ++j)
		{
			while (k && num[pivot] == 0) pivot++;
			int rd = rand() % (height * width);
			if (rd < k)
			{
				tiles[i][j].initTile(types[pivot]);
				num[pivot]--;
				k--;
			}
		}
	}
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
				tiles[h][w].initWallTile();
			}
			else if (h != boundary || w != boundary)
			{
				// Todo: 添加更多种类的Tile
				tiles[h][w].randomInitTile({5, 5, 0, 0, 10, 0});
			}
			else
			{
				tiles[h][w].initEmptyTile();
			}
		}
	}

	// 以下均用于测试

	player_pos_x = boundary;
	player_pos_y = boundary;

	tiles[1][1].initEmptyTile();
	tiles[2][2].initBattleTile();
	tiles[1][4].initBattleTile();
	tiles[3][1].initBattleTile();
	tiles[1][6].initBattleTile();
	tiles[2][1].initBattleTile();
	tiles[2][3].initChestTile();
	tiles[3][3].initChestTile();
}

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