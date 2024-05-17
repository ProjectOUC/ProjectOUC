#pragma once
#include "roles/monster.h"
#include "roles/chest.h"

#include <list>

#pragma execution_character_set("utf-8")

enum tile_type
{
	BATTLE_TILE,
	CHEST_TILE,
	EVENT_TILE,
	WALL_TILE,
	EMPTY_TILE,
	START_TILE,
	END_TILE
};

class Tile
{
public:
	void initWallTile();
	void initEmptyTile();
	void initBattleTile();
	void initChestTile();
	void initStartTile();
	void initEndTile();

	void modify_visited() { visited = true; }
	void modify_type(tile_type new_type) { type = new_type; }

	tile_type get_type() const { return type; }
	bool get_visited() const { return visited; }
	bool get_unreachable() const { return unreachable; }

	void initTile(tile_type type);

	std::vector<Monster*> monsters;
	std::vector<Chest*> chests;

	~Tile()
	{
		for (int i = 0; i < monsters.size(); ++i) delete monsters[i];
		for (int i = 0; i < chests.size(); ++i) delete chests[i];
	}
private:
	tile_type type;
	bool visited = false;
	bool unreachable;
};

