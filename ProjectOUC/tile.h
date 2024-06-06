#pragma once
#include "roles/characters.h"
<<<<<<< HEAD
=======
#include "utils/button.h"
#include "event/event.h"
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c

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
<<<<<<< HEAD
<<<<<<< HEAD
	END_TILE,
	DOOR_TILE
=======
	END_TILE
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	END_TILE,
	DOOR_TILE,
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
};

class Tile
{
public:
	void initWallTile(int level=-1);
	void initEmptyTile(int level = -1);
	void initBattleTile(int level = -1);
	void initChestTile(int level = -1);
	void initStartTile(int level = -1);
	void initEndTile(int level = -1);
<<<<<<< HEAD
<<<<<<< HEAD
	void initDoorTile(int level = -1);
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	void initDoorTile(int level = -1);
	void initEventTile(int level = -1);
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c

	void modify_visited() { visited = true; }
	void modify_type(tile_type new_type) { type = new_type; }


	tile_type get_type() const { return type; }
	bool get_visited() const { return visited; }
	bool get_unreachable() const { return unreachable; }

	void initTile(tile_type type, int level=-1);

	std::vector<Monster*> monsters;
	std::vector<Chest*> chests;
<<<<<<< HEAD

	~Tile()
	{
		for (int i = 0; i < monsters.size(); ++i) delete monsters[i];
		for (int i = 0; i < chests.size(); ++i) delete chests[i];
=======
	Event* event;

	~Tile()
	{
		for (int i = 0; i < monsters.size(); ++i) if (monsters[i]) delete monsters[i];
		for (int i = 0; i < chests.size(); ++i) if (chests[i]) delete chests[i];
		if (event) delete event;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	}
private:
	tile_type type;
	bool visited = false;
	bool unreachable;
};

