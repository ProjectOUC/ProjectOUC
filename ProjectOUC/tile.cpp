#include "tile.h"
#include <iostream>

void Tile::initTile(tile_type type)
{
	switch (type)
	{
	case WALL_TILE: initWallTile(); break;
	case EMPTY_TILE: initEmptyTile(); break;
	case BATTLE_TILE: initBattleTile(); break;
	case CHEST_TILE: initChestTile(); break;
	default: break;
	}
}

void Tile::initWallTile()
{
	type = WALL_TILE;
	unreachable = true;
}

void Tile::initEmptyTile()
{
	type = EMPTY_TILE;
	unreachable = false;
}

void Tile::initBattleTile()
{
	type = BATTLE_TILE;
	unreachable = false;
	// Todo:  ��Ϊ�������Monster
	monsters.push_back(new Monster(getMonster(0)));
	monsters.push_back(new Monster(getMonster(1)));
	monsters.push_back(new Monster(getMonster(2)));
	monsters[1]->gadgets[1] = 1;
	monsters[2]->gadgets[0] = 1;
}

void Tile::initChestTile()
{
	type = CHEST_TILE;
	unreachable = false;

	for (int i = 2; i >= -1; --i) chests.push_back(new Chest(getChest(i)));
	chests[3]->gadgets[2] = 2;
}