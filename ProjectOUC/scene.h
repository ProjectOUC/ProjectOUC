#pragma once
#include "tile.h"
#include "utils/PCG.h"
#include "utils/position.h"

#include <ctime>
#include <fstream>

#pragma execution_character_set("utf-8")

class Scene
{
public:
	Scene(std::vector < std::vector<int> > scene, int _scene_type, int stage);
	Scene(std::string path, int given_stage = -1);

	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_scene_type() const { return scene_type; }
	Position get_startPos() const { return startPos; }
	Position get_endPos() const { return endPos; }
	Tile* get_tiles(int x, int y) const {return tiles[x][y]; }
	int get_refresh(int x, int y) const { return refresh[x][y]; }
	int get_dist(int x, int y) const { return dist[x][y]; }

	void refreshMonsters();
	void allVisited();

	~Scene();

	const static int TOWN = 0;
	const static int CAVE = 1;
	const static int MAZE = 2;

	static float lmin, lmax;
	std::vector<std::vector<int>> visited;
	std::vector<std::vector<float>> light;
private:
	int width;
	int height;

	int scene_type;

	const static int boundary = 1;
	std::vector<std::vector<Tile*> > tiles;
	std::vector<std::vector<int>> refresh;
	std::vector<std::vector<int>> dist;

	
	Position startPos, endPos;
};

enum window_type
{
	BAG_WINDOW,
	BATTLE_WINDOW,
	MAIN_WINDOW,
	MAP_WINDOW
};

void SwitchToWindow(window_type t);
void SwitchToBagWindow();
void SwitchToBattleWindow();
void SwitchToMainWindow();
void SwitchToMapWindow();