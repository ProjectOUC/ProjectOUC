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
	Scene(int w, int h, int b, std::vector<int> num) :
		player(10000, 10, 0, "Nyan Nyan")
	{
		width = w;
		height = h;
		boundary = b;
		player_pos_x = player_pos_y = b;
		tiles.resize(height + 2 * boundary);
		for (int i = 0; i < height + 2 * boundary; ++i)
			tiles[i].resize(width + 2 * boundary);
		initSceneByNum(num);
	};


	int get_width() const { return width; }
	int get_height() const { return height; }

	Player get_player() { return player; }
	int get_player_pos_x() const { return player_pos_x; }
	int get_player_pos_y() const { return player_pos_y; }

	void move(direction dir);

	bool checkTile();

	void initSceneByNum(std::vector<int> num);
	void initScene();

	~Scene() {};
private:
	int width;
	int height;
	int boundary;
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