#include "tile.h"
#include "utils/random.h"

extern const int max_gadget_index;

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
	int level = random(1, 5);
	Attr attr;
	attr.maxHealth = attr.health = random(level * 11, level * 11 + 5);
	attr.attack = random(level * 5, level * 5 + 2);
	attr.defense = random(level * 3, level * 3 + 1);
	attr.missRate = 10.0 - 2 * level;
	attr.criticalAttackRate = 2.0 * level;
	std::string name = "Goblin";
	Monster* monster = new Monster(attr, name);
	monster->gadgets[random(0, max_gadget_index-1)]++;
	monsters.push_back(monster);
}

void Tile::initChestTile()
{
	type = CHEST_TILE;
	unreachable = false;

	for (int i = 2; i >= -1; --i) chests.push_back(new Chest(getChest(i)));
	chests[3]->gadgets[2] = 2;
}