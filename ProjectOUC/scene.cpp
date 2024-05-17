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
extern const int MONST;

Scene::Scene(std::vector < std::vector<int> > scene, int _scene_type, int stage) :
	scene_type(_scene_type)
{
	startPos = Position();
	endPos = Position();



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
			else if (endPos == Position())
			{
				tiles[i][j]->initEndTile();
				endPos = Position(stage, i, j);
			}
			else if (scene[i][j] == FILLED || scene[i][j] == EMPTY) tiles[i][j]->initEmptyTile();
			else if (scene[i][j] == BIRTH)
			{
				startPos = Position(stage, i, j);
				tiles[i][j]->initStartTile();
			}
		}
	}

	std::vector<std::vector<int>> dist(height, std::vector<int>(width, 0));
	dist[startPos.x][startPos.y] = 1;
	std::queue<int> qx, qy, qdist;
	qx.push(startPos.x), qy.push(startPos.y), qdist.push(1);
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
			if (tiles[i][j]->get_type() != EMPTY_TILE) continue;
			else if (dist[i][j] <= 5) tiles[i][j]->initEmptyTile();
			else
			{
				if (scene[i][j] == MONST) tiles[i][j]->initBattleTile();
				else if (scene[i][j] == FILLED || scene[i][j] == EMPTY)
				{
					if (aInb(4, 5)) tiles[i][j]->initEmptyTile();
					else if (oneIn(4)) tiles[i][j]->initChestTile();
					else tiles[i][j]->initBattleTile();
				}
			}
		}
	}

}

/*
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
*/
/*
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
*/

Scene::~Scene()
{
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
