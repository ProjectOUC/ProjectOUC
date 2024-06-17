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
	case DOOR_TILE: initDoorTile(level); break;
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
	if (event) delete event;
	event = nullptr;
	for (int i = 0; i < monsters.size(); ++i) delete monsters[i];
	for (int i = 0; i < chests.size(); ++i) delete chests[i];
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
	if (level < 0)
	{
		return;
	}
	else
	{
	 Monster* monster;
	 static std::vector<int> weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
		 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	 int ind = randIndByWeights(weights);
	 monster_type m_type = static_cast<monster_type>(ind);
	 monsters.push_back(getMonster(level, m_type).release());
	}
}


void Tile::initChestTile(int level)
{
	type = CHEST_TILE;
	unreachable = false;
	if (level < 0)
	{
		return;
	}
	else
	{
		Chest* chest = new Chest();
		chest->set_coin(50 + 10 * level + roll(2, 5));
		chest->set_food_capacity(10 + 3 * level);
		chest->set_food(5 + 3 * level + roll(2, 2));
		level = max(level, 20);
		int treasure_count = level / 4 + 1;
		for (int i = 0; i < treasure_count; ++i)
		{
			int ind = random(0, max_gadget_index-1);
			chest->gadgets[ind]++;
		}
		chests.push_back(chest);
	}
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

void Tile::initDoorTile(int level)
{
	type = EVENT_TILE;
	event = new Event("event/NPC/event-door.txt");
	unreachable = false;
}

void Tile::initEventTile(int level)
{
	type = EVENT_TILE;
	unreachable = false;
}