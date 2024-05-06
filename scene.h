#pragma once
#include "graphics.h"
#include "tile.h"
#include "player.h"
#include "battle.h"

#include <vector>

const int GAME_WIDTH = 1024, GAME_HEIGHT = 768;
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
	Scene(int w = 10, int h = 10) :
		player(1000, 10, 0, "Nyan Nyan")
	{
		width = w;
		height = h;
		initScene();
	};

	int get_width() const { return width; }
	int get_height() const { return height; }

	Player get_player() { return player; }
	int get_player_pos_x() const { return player_pos_x; }
	int get_player_pos_y() const { return player_pos_y; }

	void move(direction dir);

	bool checkTile();

	void initScene();

	~Scene() {};
private:
	int width;
	int height;
	const static int boundary = 1;
	std::vector<std::vector<Tile> > tiles;

	Player player;
	int player_pos_x;
	int player_pos_y;

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