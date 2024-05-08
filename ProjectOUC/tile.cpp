#include "tile.h"
#include <iostream>

void Tile::randomInitTile(std::vector<int> weights)
{
	static std::vector<tile_type> types
	{
		BATTLE_TILE,
		CHEST_TILE,
		EVENT_TILE,
		WALL_TILE,
		EMPTY_TILE
	};
	int sum = 0;
	for (int weight : weights) sum += weight;
	int psum = rand() % sum; 
	for (int i = 0; i < weights.size(); ++i)
	{
		if (psum < weights[i])
		{
			initTile(types[i]);
			return;
		}
		psum -= weights[i];
	}
}

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