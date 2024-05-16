#pragma once
#include "graphics.h"
#include "tile.h"
#include "player.h"
#include "battle.h"
#include "PCG.h"
#include "utils/random.h"

#include <vector>
#include <ctime>

#pragma execution_character_set("utf-8")

enum direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Scene
{
public:
	Scene(int w = 10, int h = 10);
	Scene(std::vector < std::vector<int> > scene, int _scene_type);

	int get_width() const { return width; }
	int get_height() const { return height; }

	Player* get_player() { return player; }
	int get_player_pos_x() const { return player_pos_x; }
	int get_player_pos_y() const { return player_pos_y; }
	int get_scene_type() const { return scene_type; }
	Tile* get_tiles(int x, int y) const {return tiles[x][y]; }

	void move(direction dir);
	void moveTo(int x, int y);

	bool checkTile();

	void initScene();
	void initSceneByNum(std::vector<int> num);

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

	Player* player;
	int player_pos_x;
	int player_pos_y;
	int last_x;
	int last_y;
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