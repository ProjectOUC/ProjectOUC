#pragma once
#include "graphics.h"
#include "tile.h"
#include "battle.h"
#include "PCG.h"
#include "utils/random.h"
#include "utils/position.h"

#include <vector>
#include <ctime>

#pragma execution_character_set("utf-8")

class Scene
{
public:
	Scene(std::vector < std::vector<int> > scene, int _scene_type, int stage);

	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_scene_type() const { return scene_type; }
	Position get_startPos() const { return startPos; }
	Position get_endPos() const { return endPos; }
	Tile* get_tiles(int x, int y) const {return tiles[x][y]; }

	//bool checkTile();

	//void initScene();
	//void initSceneByNum(std::vector<int> num);

	~Scene();

	const static int TOWN = 0;
	const static int CAVE = 1;
	const static int MAZE = 2;
private:
	int width;
	int height;

	int scene_type;

	const static int boundary = 1;
	std::vector<std::vector<Tile*> > tiles;

	
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