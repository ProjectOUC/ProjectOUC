#define _CRT_SECURE_NO_WARNINGS

#include "scene.h"

#include <conio.h>
#include <iostream>
#include <queue>
#include <string>


#pragma execution_character_set("utf-8")


const int GAME_WIDTH = 1024, GAME_HEIGHT = 768;
extern const int EMPTY;
extern const int WALL;
extern const int BIRTH;
extern const int FILLED;
extern const int MONST;
extern const int TREASURE;
extern const int CLOSEDOOR;

Scene::Scene(std::string path)
{
	FILE* fp;
	if (!(fp = fopen(path.c_str(), "r")))
	{
		std::cout << "File doesn't exist.\n";
		exit(0);
	}

	char buffer[1024];
	fscanf(fp, "%s\n", buffer);
	if (strncmp(buffer, "TOWN", 4) == 0) scene_type = TOWN;
	else if (strncmp(buffer, "CAVE", 4) == 0) scene_type = CAVE;
	else if (strncmp(buffer, "MAZE", 4) == 0) scene_type = MAZE;
	else 
	{
		printf("Unknown scene type %s", buffer);
		exit(0);
	}

	int stage = 0;
	fscanf(fp, "height: %d\n", &height);
	fscanf(fp, "width: %d\n", &width);
	fscanf(fp, "stage: %d\n", &stage);
	startPos.stage = endPos.stage = stage;
	tiles.resize(height); refresh.resize(height); dist.resize(height);
	for (int i = 0; i < height; ++i)
	{
		tiles[i].resize(width);
		refresh[i].resize(width);
		dist[i].resize(width);
		for (int j = 0; j < width; ++j) tiles[i][j] = new Tile;
	}
	fscanf(fp, "%s\n", buffer);
	if (strncmp(buffer, "parameter", 9) == 0)
	{
		if (scene_type == TOWN)
		{
			std::cout << "TOWN can't be initialized with parameters.\n";
			exit(0);
		}
		else if (scene_type == CAVE)
		{
			int maxIter, wallWeight;
			double fillIter;
			fscanf(fp, "maxIter: %d\n", &maxIter);
			fscanf(fp, "wallWeight: %d\n", &wallWeight);
			fscanf(fp, "fillIter: %lf\n", &fillIter);
			this->Scene::Scene(caveGenerate(height, width, maxIter, wallWeight, fillIter, false), CAVE, stage);
		}
		else if (scene_type == MAZE)
		{
			int maxRoomNum, minRoomSize, maxRoomSize, maxIter, windingPercent;
			double keepDeadEndRate;
			fscanf(fp, "maxRoomNum: %d\n", &maxRoomNum);
			fscanf(fp, "minRoomSize: %d\n", &minRoomSize);
			fscanf(fp, "maxRoomSize: %d\n", &maxRoomSize);
			fscanf(fp, "maxIter: %d\n", &maxIter);
			fscanf(fp, "windingPercent: %d\n", &windingPercent);
			fscanf(fp, "keepDeadEndRate: %lf\n", &keepDeadEndRate);
			this->Scene::Scene(mazeGenerate(height, width, maxRoomNum, minRoomSize, maxRoomSize, maxIter, windingPercent, keepDeadEndRate, false), MAZE, stage);
		}
	}
	else if (strncmp(buffer, "storage", 7) == 0)
	{
		fscanf(fp, "startPos: %d %d\n", &startPos.x, &startPos.y);
		fscanf(fp, "endPos: %d %d\n", &endPos.x, &endPos.y);
		fscanf(fp, "refresh: \n");
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
				fscanf(fp, "%d", &refresh[i][j]);
		
		fgetc(fp);
		fscanf(fp, "dist: \n");
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
				fscanf(fp, "%d", &dist[i][j]);
		fgetc(fp);

		fscanf(fp, "tiles: \n");
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				int level = (dist[i][j] - 5) / 10;
				static std::vector<int> weights = { 1, 5, 10, 10, 5, 1 };
				level = max(0, level - 5 + randIndByWeights(weights));
				level += 10 * (scene_type - 1);
				Tile* tile = tiles[i][j];
				tile_type ttype;
				fscanf(fp, "%d", &ttype);
				tile->initTile(ttype, level);
			}
		}
	}
	else
	{
		std::cout << "Unknown archive type ";
		printf("%s", buffer);
		exit(0);
	}


	fclose(fp);
}

Scene::Scene(std::vector < std::vector<int> > scene, int _scene_type, int stage) :
	scene_type(_scene_type)
{
	startPos = Position();
	endPos = Position();



	height = (int)scene.size();
	width = (int)scene[0].size();
	tiles.resize(height);
	refresh.resize(height);
	dist.resize(height);
	for (int i = 0; i < height; ++i)
	{
		refresh[i].resize(width);
		tiles[i].resize(width);
		dist[i].resize(width);
		for (int j = 0; j < width; ++j)
		{
			tiles[i][j] = new Tile;
			if (scene[i][j] == WALL) tiles[i][j]->initWallTile();
			else if (scene[i][j] == BIRTH)
			{
				startPos = Position(stage, i, j);
				tiles[i][j]->initStartTile();
			} 
			else
			{
				tiles[i][j]->initEmptyTile();
			}
		}
	}

	dist[startPos.x][startPos.y] = 1;
	std::queue<int> qx, qy, qdist;
	const static int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
	int fx = 0, fy = 0, fdis = 0;
	
	qx.push(startPos.x), qy.push(startPos.y), qdist.push(1);
	while (!qx.empty())
	{
		int x = qx.front(), y = qy.front(), dis = qdist.front();
		qx.pop(), qy.pop(), qdist.pop();

		if (dis > fdis) fx = x, fy = y, fdis = dis;
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
			else if (i == fx && j == fy) tiles[i][j]->initEndTile(), endPos = Position(stage, i, j);
			else if (dist[i][j] <= 5) tiles[i][j]->initEmptyTile();
			else
			{
				int level = (dist[i][j] - 5) / 10;
				static std::vector<int> weights = { 1, 5, 10, 10, 5, 1 };
				level = max(0, level - 5 + randIndByWeights(weights));
				level += 10 * (scene_type-1);

				if (scene[i][j] == MONST) tiles[i][j]->initBattleTile(level);
				else if (scene[i][j] == TREASURE) tiles[i][j]->initChestTile(level);
				else if (scene[i][j] == CLOSEDOOR) tiles[i][j]->initDoorTile(level);
				else if (scene[i][j] == FILLED || scene[i][j] == EMPTY)
				{
					refresh[i][j] = 1;

					if (!oneIn(8)) tiles[i][j]->initEmptyTile(level);
					else if (oneIn(10)) tiles[i][j]->initChestTile(level);
					else tiles[i][j]->initBattleTile(level);
				}
			}
		}
	}

}

void Scene::refreshMonsters()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (refresh[i][j] != 1) continue;
			tiles[i][j]->initEmptyTile();
			if (!oneIn(8)) continue;
			if (dist[i][j] <= 5) continue;
			int level = (dist[i][j] - 5) / 10;
			static std::vector<int> weights = { 1, 5, 10, 10, 5, 1 };
			int rd = level - 3 + randIndByWeights(weights);
			level = max(0, rd);
			level = level + 10 * (scene_type - 1);
			if (oneIn(10)) tiles[i][j]->initChestTile(level);
			else tiles[i][j]->initBattleTile(level);
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
