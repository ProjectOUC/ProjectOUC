#pragma once
#include "random.h"
#include "graphics.h"

#include <vector>

struct Room
{
	Room();
	Room(int _x1, int _y1, int _x2, int _y2);
	Room(const Room& other);
	int x1, y1, x2, y2;

	Room& operator=(const Room& other);
	bool intersect(const Room& other) const;
	bool include(const Room& other) const;
};

struct Coord
{
	int x, y;
};

void scenePaint(std::vector<std::vector<int>>& scene, int height, int width);

std::vector<std::vector<int>> mazeGenerate(
	int height,
	int width,
	int maxRoomNum,
	int minRoomSize,
	int maxRoomSize,
	int maxIter,
	int windingPercent,
	double keepDeadEndRate,
	bool paint=false);

void generatePath(std::vector<std::vector<int>>& maze, int h, int w, int windingPercent);

void connectPath(std::vector<std::vector<int>>& maze, std::vector<Room*> rooms, int h, int w);

void eraseDeadEnd(std::vector<std::vector<int>>& maze, int h, int w, double keepDeadEndRate);

std::vector<std::vector<int>> caveGenerate(
	int height,
	int width,
	int maxIter,
	int wallWeight,
	double fillIter,
	bool paint=false);

void fillFragments(std::vector<std::vector<int>>& scene);

void initBirthPoint(std::vector<std::vector<int>>& scene);

void getPrefix(const std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& prefix, int padding);
int getSum(const std::vector<std::vector<int>>& prefix, int x1, int y1, int x2, int y2, int padding);