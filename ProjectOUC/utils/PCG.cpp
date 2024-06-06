#include "PCG.h"
#include <queue>


extern const int EMPTY = 0;
extern const int WALL = 1;
extern const int BIRTH = 2;
extern const int FILLED = 3;
extern const int MONST = 4;
extern const int CLOSEDOOR = 5;
extern const int TREASURE = 6;

Room::Room()
{
	x1 = x2 = y1 = y2 = 0;
}

Room::Room(int _x1, int _y1, int _x2, int _y2)
{
	x1 = min(_x1, _x2);
	x2 = max(_x1, _x2);
	y1 = min(_y1, _y2);
	y2 = max(_y1, _y2);
}

Room& Room::operator=(const Room& other)
{
	x1 = other.x1;
	y1 = other.y1;
	x2 = other.x2;
	y2 = other.y2;
	return *this;
}

Room::Room(const Room& other)
{
	x1 = other.x1;
	y1 = other.y1;
	x2 = other.x2;
	y2 = other.y2;
}

bool Room::intersect(const Room& other) const
{
	if (x1 > other.x2 || x2 < other.x1 || y1 > other.y2 || y2 < other.y1) return false;
	return true;
}

bool Room::include(const Room& other) const
{
	if (x1 <= other.x1 && x2 >= other.x2 && y1 <= other.y1 && y2 >= other.y2) return true;
	return false;
}

void scenePaint(std::vector<std::vector<int>>& scene, int height, int width)
{
	initgraph(1600, 900);
	for (int x = 0; x < height; ++x)
	{
		for (int y = 0; y < width; ++y)
		{
			if (scene[x][y] == WALL)
			{
				fillrectangle(10 * x + 1, 10 * y + 1, 10 * x + 9, 10 * y + 9);
			}
			else if (scene[x][y] == BIRTH)
			{
				fillcircle(10 * x + 5, 10 * y + 5, 4);
			}
		}
	}
	getchar();
	cleardevice();
	closegraph();
}

std::vector<std::vector<int>> mazeGenerate(
	int height,
	int width,
	int maxRoomNum,
	int minRoomSize,
	int maxRoomSize,
	int maxIter,
	int windingPercent,
	double keepDeadEndRate,
	bool paint)
{
	//1. 随机生成一些房间
	//2. 使用flood fill生成道路
	//3. 连接房间和道路
	//4. 删除一些死胡同
	//5. 生成出生点
	//6. 生成怪物、NPC、宝箱

	// Step 1
	std::vector < std::vector<int> > maze(2*height+1);
	std::vector <Room*> rooms;
	for (int i = 0; i < 2 * height + 1; ++i) maze[i].resize(2*width+1);
	for (int i = 0; i < 2 * height + 1; ++i) maze[i][0] = maze[i][2 * width] = WALL;
	for (int i = 0; i < 2 * width + 1; ++i) maze[0][i] = maze[2*height][i] = WALL;
	//put room
	for (int i = 0; i < maxRoomNum; ++i)
	{
		for (int iter = 0; iter < maxIter; ++iter)
		{
			int x1 = random(0, height);
			int y1 = random(0, width);
			int x2 = x1 + random(minRoomSize+1, maxRoomSize);
			int y2 = y1 + random(minRoomSize+1, min(maxRoomSize, 2*(x2-x1)));
			if (x2 > height || y2 > width) continue;
			Room* room = new Room(x1, y1, x2, y2);
			bool overlap = false;
			for (Room* r : rooms)
			{
				if (room->intersect(*r)) overlap = true;
				if (overlap) break;
			}
			if (overlap) delete room;
			else
			{
				rooms.push_back(room);
				break;
			}
		}
	}

	for (Room* r : rooms)
		for (int x = 2 * (r->x1); x <= 2 * (r->x2); ++x)
			for (int y = 2 * (r->y1); y <= 2 * (r->y2); ++y)
				maze[x][y] = (x == 2 * (r->x1) || x == 2 * (r->x2) || y == 2 * (r->y1) || y == 2 * (r->y2)) ? WALL : FILLED;
	
	// Step2
	generatePath(maze, 2*height+1, 2*width+1, windingPercent);
	// Step3
	connectPath(maze, rooms, 2*height+1, 2*width+1);
	// Step4
	eraseDeadEnd(maze, 2*height+1, 2*width+1, keepDeadEndRate);
	// Step5
	initBirthPoint(maze);
	// Step6
	if (paint) scenePaint(maze, 2 * height + 1, 2 * width + 1);

	for (int i = 0; i < rooms.size(); ++i) delete rooms[i];
	return maze;
}

void generatePath(std::vector<std::vector<int>>& maze, int h, int w, int windingPercent)
{
	int bx = 0, by = 0, lastdir = -1;
	const static int dx[4] = { -2, 0, 2, 0 }, dy[4] = { 0, -2, 0, 2 };
	for (int i = 1; i < h; i += 2)
	{
		if (bx != 0) break;
		for (int j = 1; j < w; j += 2)
		{
			if (maze[i][j] != FILLED)
			{
				bx = i;
				by = j;
			}
		}
	}

	std::vector<int> qx, qy, dir;
	qx.push_back(bx);
	qy.push_back(by);
	dir.push_back(-1);
	maze[bx][by] = FILLED;

	while (!qx.empty())
	{
		int newdir = 0;
		bx = qx.back();
		by = qy.back();
		lastdir = dir.back();
		maze[bx][by] = FILLED;
		std::vector<int> unmadeDir;

		for (int d = 0; d < 4; ++d)
		{
			if (bx + dx[d] >= 0 && by + dy[d] >= 0 && bx + dx[d] < h && by + dy[d] < w && maze[bx+dx[d]][by+dy[d]] == EMPTY) 
				unmadeDir.push_back(d);
		}

		if (!unmadeDir.empty())
		{
			if (lastdir != -1 && random(0, 100) > windingPercent && count(unmadeDir.begin(), unmadeDir.end(), lastdir)) 
				newdir = lastdir;
			else 
				newdir = random(unmadeDir);
			dir.push_back(newdir);
			qx.push_back(bx + dx[newdir]);
			qy.push_back(by + dy[newdir]);
			maze[bx + dx[newdir]][by + dy[newdir]] = maze[bx + dx[newdir] / 2][by + dy[newdir] / 2] = FILLED;
		}
		else
		{
			qx.pop_back();
			qy.pop_back();
			dir.pop_back();
		}
	}

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (maze[i][j] == EMPTY) maze[i][j] = WALL;
	
	return;
}

void connectPath(std::vector<std::vector<int>>& maze, std::vector<Room*> rooms, int h, int w)
{
	for (Room* room : rooms)
	{
		for (int x = 2 * room->x1 + 1; x < 2 * room->x2; ++x)
		{
			for (int y = 2 * room->y1 + 1; y < 2 * room->y2; ++y)
			{
				if (oneIn(4)) maze[x][y] = TREASURE;
			}
		}
	}

	for (Room* room : rooms)
	{
		std::vector<int> px, py;
		for (int x = 2 * room->x1 + 1; x < 2 * room->x2; ++x)
		{
			if (2 * room->y1 != 0)
			{
				if (maze[x][2 * room->y1 + 1] != WALL && maze[x][2 * room->y1 - 1] != WALL)
				{

					px.push_back(x);
					py.push_back(2 * room->y1);
				}
			}
			if (2 * room->y2 != w-1) 
			{
				if (maze[x][2 * room->y2 + 1] != WALL && maze[x][2 * room->y2 - 1] != WALL)
				{
					px.push_back(x);
					py.push_back(2 * room->y2);
				}
			}
		}
		for (int y = 2 * room->y1 + 1; y < 2 * room->y2; ++y)
		{
			if (2 * room->x1 != 0)
			{
				if (maze[2 * room->x1 - 1][y] != WALL && maze[2 * room->x1 + 1][y] != WALL)
				{
					px.push_back(2 * room->x1);
					py.push_back(y);
				}
			}
			if (2 * room->x2 != h - 1)
			{
				if (maze[2 * room->x2 - 1][y] != WALL && maze[2 * room->x2 + 1][y] != WALL)
				{
					px.push_back(2 * room->x2);
					py.push_back(y);
				}
			}
		}
		int ind = randInd(px);
		maze[px[ind]][py[ind]] = oneIn(2) ? MONST : CLOSEDOOR;
	}


	std::vector<int> px, py;
	for (int i = 1; i < h - 1; ++i)
	{
		for (int j = 1; j < h - 1; ++j)
		{
			if (maze[i][j] != WALL) continue;
			if ((maze[i][j - 1] != WALL && maze[i][j + 1] != WALL) || (maze[i - 1][j] != WALL && maze[i + 1][j] != WALL))
			{
				if (oneIn(50))
				{
					maze[i][j] = oneIn(2) ? FILLED : (oneIn(3) ? MONST : CLOSEDOOR);
				}
			}
		}
	}
}

void eraseDeadEnd(std::vector<std::vector<int>>& maze, int h, int w, double keepDeadEndRate)
{
	std::vector<int> qx, qy;
	const static int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
	for (int i = 1; i < h - 1; ++i)
	{
		for (int j = 1; j < h - 1; ++j)
		{
			if (maze[i][j] == WALL) continue;
			int unmadeDir = 0;
			for (int d = 0; d < 4; ++d)
				if (maze[i + dx[d]][j + dy[d]] != WALL) unmadeDir++;
			if (unmadeDir == 1) qx.push_back(i), qy.push_back(j);
		}
	}

	int x = 0, y = 0, size = qx.size();
	std::vector<int> vecx, vecy, rd(random(0, size - 1, (int)(size * keepDeadEndRate), false));
	for (int ind : rd)
	{
		x = qx[ind], y = qy[ind];
		while (1)
		{
			int unmadeDir = 0;
			for (int d = 0; d < 4; ++d)
			{
				int nx = x + dx[d], ny = y + dy[d];
				if (maze[nx][ny] == WALL) continue;
				unmadeDir++;
			}
			if (unmadeDir != 1) break;
			else
			{
				maze[x][y] = WALL;
				for (int d = 0; d < 4; ++d)
				{
					int nx = x + dx[d], ny = y + dy[d];
					if (maze[nx][ny] == WALL) continue;
					x = nx, y = ny;
					break;
				}
			}
		}
	}
}

std::vector<std::vector<int>> caveGenerate(
	int height,
	int width,
	int maxIter,
	int wallWeight,
	double fillIter,
	bool paint)
{
	/*	1. 生成cave, 随机初始化
		2. 迭代maxIter次
		3. 填补空缺
		4. 生成出生点
		5. 生成怪物、宝箱、NPC
	*/

	// Step 1
	std::vector<std::vector<int>> cave(2*height+1);
	std::vector<std::vector<int>> new_cave;
	for (int i = 0; i < cave.size(); ++i)
	{
		cave[i].resize(2 * width + 1);
	}

	for (int i = 0; i < 1 + 2 * height; ++i)
	{
		for (int j = 0; j < 1 + 2 * width; ++j)
		{
			if (i == 0 || j == 0 || i == 2 * height || j == 2 * width) 
			{
				cave[i][j] = WALL;
			}
			else cave[i][j] = (random(0, 100) < wallWeight) ? WALL : EMPTY;
		}
	}

	// Step 2
	for (int iter = 0; iter < maxIter; ++iter)
	{
		getPrefix(cave, new_cave, 2);

		for (int h = 1; h < 2 * height; ++h)
		{
			for (int w = 1; w < 2 * width; ++w)
			{
				int wallCount1 = getSum(new_cave, h - 1, w - 1, h + 1, w + 1, 2);
				int wallCount2 = getSum(new_cave, h - 2, w - 2, h + 2, w + 2, 2);
				if (wallCount1 >= 5 || (iter < fillIter * maxIter && wallCount2 <= 2)) cave[h][w] = WALL;
				else cave[h][w] = EMPTY;
			}
		}
	}

	// Step 3
	fillFragments(cave);

	// Step 4
	initBirthPoint(cave);

	// Step 5: Todo
	if (paint) scenePaint(cave, 2 * height + 1, 2 * width + 1);

	return cave;
}

void fillFragments(std::vector<std::vector<int>>& scene)
{
	int h = (int)scene.size(), w = (int)scene[0].size();
	std::vector<std::vector<int>> visited(h, std::vector<int>(w, 0));
	std::vector<std::vector<int>> belong(h, std::vector<int>(w, -1));
	std::vector<int> chunkSize;
	std::vector<int> px, py;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (scene[i][j] == WALL || visited[i][j])
			{
				visited[i][j] = true;
				continue;
			}
			else
			{
				px.push_back(i);
				py.push_back(j);
				visited[i][j] = true;
				belong[i][j] = (int)chunkSize.size();
				chunkSize.push_back(0);
				while (!px.empty())
				{
					int x = px.back(), y = py.back();
					px.pop_back(); py.pop_back();
					chunkSize[(int)chunkSize.size()-1]++;
					if (scene[x - 1][y] != WALL && !visited[x - 1][y]) px.push_back(x-1), py.push_back(y), visited[x-1][y] = true, belong[x-1][y] = belong[x][y];
					if (scene[x + 1][y] != WALL && !visited[x + 1][y]) px.push_back(x+1), py.push_back(y), visited[x + 1][y] = true, belong[x + 1][y] = belong[x][y];
					if (scene[x][y-1] != WALL && !visited[x][y-1]) px.push_back(x), py.push_back(y-1), visited[x][y-1] = true, belong[x][y-1] = belong[x][y];
					if (scene[x][y+1] != WALL && !visited[x][y+1]) px.push_back(x), py.push_back(y+1), visited[x][y+1] = true, belong[x][y+1] = belong[x][y];
				}
			}
		}
	}

	int ind = 0;
	for (int i = 0; i < chunkSize.size(); ++i)
	{
		if (chunkSize[i] > chunkSize[ind]) ind = i;
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (belong[i][j] != ind) scene[i][j] = WALL;
			else scene[i][j] = EMPTY;
		}
	}
}

void initBirthPoint(std::vector<std::vector<int>>& scene)
{
	// 随机选取以下四个点之一作为出生点
	// x+y最大/最小的点
	// x-y最大/最小的点
	int rd = random(0,3);
	const int INF = 0x3f3f3f3f;
	int h = (int)scene.size();
	int w = (int)scene[0].size();
	int x[4] = { 0, INF, INF, 0 }, y[4] = { 0, INF, 0, INF };
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (scene[i][j] == WALL) continue;
			if (i + j > x[0] + y[0]) x[0] = i, y[0] = j;
			if (i + j < x[1] + y[1]) x[1] = i, y[1] = j;
			if (i - j < x[2] - y[2]) x[2] = i, y[2] = j;
			if (i - j > x[3] - y[3]) x[3] = i, y[3] = j;
		}
	}

	while (1)
	{
		int bx = random(x[rd] - 5, x[rd] + 5), by = random(y[rd] - 5, y[rd] + 5);
		if (bx > 0 && bx < h && by > 0 && by < w && scene[bx][by] != WALL)
		{
			scene[bx][by] = BIRTH;
			return;
		}
	}
}

void getPrefix(const std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& prefix, int padding)
{
	int h = (int)mat.size();
	int w = (int)mat[0].size();
	padding = max(padding, 1);

	prefix.clear();
	prefix.resize(h + padding);
	for (int i = 0; i < h + padding; ++i)
	{
		prefix[i].clear();
		prefix[i].resize(w + padding);
	}
	for (int i = 0; i < h + padding; ++i)
		for (int j = 0; j < w + padding; ++j)
			if (i < padding || j < padding) prefix[i][j] = 0;
			else prefix[i][j] = mat[i-padding][j-padding] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
}

int getSum(const std::vector<std::vector<int>>& prefix, int x1, int y1, int x2, int y2, int padding)
{
	x1--;
	y1--;
	x1 += padding;
	y1 += padding;
	x2 += padding;
	y2 += padding;
	x2 = min(x2, (int)prefix.size()-1);
	y2 = min(y2, (int)prefix[0].size() - 1);
	
	return prefix[x2][y2] + prefix[x1][y1] - prefix[x1][y2] - prefix[x2][y1];
}