#include "tile.h"
#include <iostream>

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
	// Todo:  改为随机生成Monster
	monsters.push_back(getMonster(0));
	monsters.push_back(getMonster(1));
	monsters.push_back(getMonster(2));
	monsters[1].gadgets[1] = 1;
	monsters[2].gadgets[0] = 1;
}

void Tile::initChestTile()
{
	type = CHEST_TILE;
	unreachable = false;

	for (int i = 2; i >= -1; --i) chests.push_back(getChest(i));
	chests[3].gadgets[2] = 2;
}