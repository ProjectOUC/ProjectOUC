#include "tile.h"
#include "utils/random.h"

extern const int max_gadget_index;

void Tile::initTile(tile_type type, int level)
{
	switch (type)
	{
	case WALL_TILE: initWallTile(level); break;
	case EMPTY_TILE: initEmptyTile(level); break;
	case BATTLE_TILE: initBattleTile(level); break;
	case CHEST_TILE: initChestTile(level); break;
	case START_TILE: initStartTile(level); break;
	case END_TILE: initEndTile(level); break;
	default: break;
	}
}

void Tile::initWallTile(int level)
{
	type = WALL_TILE;
	unreachable = true;
}

void Tile::initEmptyTile(int level)
{
	monsters.clear();
	monsters.shrink_to_fit();
	chests.clear();
	chests.shrink_to_fit();
	type = EMPTY_TILE;
	unreachable = false;
}

void Tile::initBattleTile(int level)
{
	type = BATTLE_TILE;
	unreachable = false;
	// Todo:  ��Ϊ�������Monster
	// �����
	if (level == -1)
	{
		int level = random(1, 5);
		Attr attr;
		attr.maxHealth = attr.health = random(level * 11, level * 11 + 5);
		attr.attack = random(level * 5, level * 5 + 2);
		attr.defense = random(level * 2, level * 2 + 1);
		attr.missRate = 10.0f - 2 * level;
		attr.criticalAttackRate = 2.0f * level;
		std::string name = "Goblin";
		Monster* monster = new Monster(attr, name);
		monster->gadgets[random(0, max_gadget_index - 1)]++;
		monsters.push_back(monster);
	}
	else
	{
		Monster* monster;
		static std::vector<int> weights = { 10, 10 };
		int ind = randIndByWeights(weights);
		if (ind == 0) monster = (Monster*)new Goblin(level);
		else if (ind == 1) monster = (Monster*)new Slime(level);
		monsters.push_back(monster);
	}
}

void Tile::initChestTile(int level)
{
	type = CHEST_TILE;
	unreachable = false;

	for (int i = 2; i >= -1; --i) chests.push_back(new Chest(getChest(i)));
	chests[3]->gadgets[2] = 2;
}

void Tile::initStartTile(int level)
{
	type = START_TILE;
	unreachable = false;
}

void Tile::initEndTile(int level)
{
	type = END_TILE;
	unreachable = false;
}