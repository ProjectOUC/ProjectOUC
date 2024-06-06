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
<<<<<<< HEAD
<<<<<<< HEAD
	case DOOR_TILE: initDoorTile(level); break;
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	case DOOR_TILE: initDoorTile(level); break;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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
<<<<<<< HEAD
<<<<<<< HEAD
	for (int i = 0; i < monsters.size(); ++i) delete monsters[i];
	for (int i = 0; i < chests.size(); ++i) delete chests[i];
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	for (int i = 0; i < monsters.size(); ++i) delete monsters[i];
	for (int i = 0; i < chests.size(); ++i) delete chests[i];
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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
<<<<<<< HEAD
	// Todo:  改为随机生成Monster
	// 已完成
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
<<<<<<< HEAD
		//std::cout << level << "\n";
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	if (level < 0)
	{
		return;
	}
	else
	{
		//std::cout << level << "\n";
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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
<<<<<<< HEAD
<<<<<<< HEAD
	if (level == -1)
	{
		for (int i = 2; i >= -1; --i) chests.push_back(new Chest(getChest(i)));
		chests[3]->gadgets[2] = 2;
=======
	if (level < 0)
	{
		return;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	}
	else
	{
		Chest* chest = new Chest();
<<<<<<< HEAD
		chest->set_coin(50 + 20 * level + roll(5, 3));
		chest->set_food_capacity(10 * 5 * level);
		chest->set_food(5 + 5 * level + roll(2, 2));
		int treasure_count = -level / 2 + roll(level, 2);
=======
		chest->set_coin(50 + 10 * level + roll(2, 5));
		chest->set_food_capacity(10 + 5 * level);
		chest->set_food(5 + 5 * level + roll(2, 2));
		int treasure_count = level / 4 + 1;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
		for (int i = 0; i < treasure_count; ++i)
		{
			int ind = random(0, max_gadget_index-1);
			chest->gadgets[ind]++;
		}
		chests.push_back(chest);
	}
<<<<<<< HEAD
=======

	for (int i = 2; i >= -1; --i) chests.push_back(new Chest(getChest(i)));
	chests[3]->gadgets[2] = 2;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
}

void Tile::initDoorTile(int level)
{
	type = DOOR_TILE;
	unreachable = false;
<<<<<<< HEAD
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
}

void Tile::initEventTile(int level)
{
	type = EVENT_TILE;
	unreachable = false;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
}