#pragma once
#include "monster.h"
#include "character.h"
#include "chest.h"

#include <list>
#include <vector>

enum tile_type
{
	BATTLE_TILE,
	CHEST_TILE,
	EVENT_TILE,
	WALL_TILE,
	EMPTY_TILE
};

class Tile
{
public:
	void randomInitTile(std::vector<int> weights);
	void initTile(tile_type type);
	void initWallTile();
	void initEmptyTile();
	void initBattleTile();
	void initChestTile();

	void modify_visited() { visited = true; }
	void modify_type(tile_type new_type) { type = new_type; }

	tile_type get_type() const { return type; }
	bool get_visited() const { return visited; }
	bool get_unreachable() const { return unreachable; }

	std::vector<Monster> monsters;
	std::vector<Chest> chests;
private:
	tile_type type;
	bool visited = false;
	bool unreachable;


};

