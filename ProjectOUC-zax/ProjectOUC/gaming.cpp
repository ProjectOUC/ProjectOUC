#include "gaming.h"


void checkTile(std::vector<Scene*>& scenes, Player* player)
{
	SetConsoleOutputCP(CP_UTF8);
	Position pos = player->get_pos();
	if (player->get_attr().teleport)
	{
		player->moveTo(scenes[0]->get_startPos());
		player->set_teleport(false);
		return;
	}
	if (pos.stage < 0 || pos.stage >= scenes.size())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(player->get_pos().stage);
		return;
	}
	Scene* scene = scenes[pos.stage];
	if (pos.x <= 0 || pos.y <= 0 || pos.x >= scene->get_height() || pos.y >= scene->get_width())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(pos.stage);
		return;
	}

	Tile* tile = scene->get_tiles(pos.x, pos.y);
	if (tile->get_unreachable())
	{
		player->modify_pos(player->get_lastPos());
		player->modify_food(pos.stage);
		return;
	}

	
	if (tile->get_type() == WALL_TILE)
	{
		player->modify_moved(false);
	}

	else if (tile->get_type() == BATTLE_TILE)
	{
		player->modify_moved(true);
		for (int i = 0; i < tile->monsters.size(); ++i)
		{
			std::cout << "遭遇" << tile->monsters[i]->get_name() << "\n";
			std::cout << "HP: " << tile->monsters[i]->get_health() << "\natk: " << tile->monsters[i]->calc_min_attack()
				<< "-" << tile->monsters[i]->calc_max_attack()
				<<"\ndef: " << tile->monsters[i]->get_defense() << "\n";
			Battle battle((Character*)tile->monsters[i], (Character*)player);

			if (!battle.battle())
			{
				return;
			}
			std::cout << "战胜" << tile->monsters[i]->get_name() << "\n" <<
				"最大生命: " << player->get_maxHealth() <<
				"\n剩余生命: " << player->get_health() <<
				"\n防御: " << player->get_defense() <<
				"\n攻击: " << player->calc_min_attack() << "-" << player->calc_max_attack() <<
				"\n速度: " << player->get_attackFirstLevel() <<
				"\n力量: " << player->get_strength() <<
				"\n敏捷: " << player->get_agility() <<
				"\n智力: " << player->get_wisdom() <<
				"\n命中: " << player->get_hitRate() <<
				"\n闪避: " << player->get_missRate() << "\n\n";
		}
		tile->monsters.clear();
		tile->modify_type(EMPTY_TILE);
	}

	else if (tile->get_type() == EMPTY_TILE)
	{
		player->modify_moved(true);
	}

	else if (tile->get_type() == CHEST_TILE)
	{
		player->modify_moved(true);
		for (int i = 0; i < tile->chests.size(); ++i)
		{
			std::cout << "打开" << tile->chests[i]->get_name() << "\n";
			Battle battle((Character*)tile->chests[i], (Character*)player);
			if (!battle.battle())
			{
				return;
			}
			std::cout << "获得" << tile->chests[i]->get_coin() << "铜币\n";
			std::cout << "当前金钱: " << player->get_coin() << "\n\n";
		}
		tile->chests.clear();
		tile->modify_type(EMPTY_TILE);
	}

	else if (tile->get_type() == START_TILE)
	{
		if (player->get_moved() && pos.stage > 0)
		{
			player->moveTo(scenes[pos.stage - 1]->get_endPos());
			scenes[pos.stage - 1]->refreshMonsters();
		}
		player->modify_moved(false);
		
	}
	else if (tile->get_type() == END_TILE)
	{
		if (player->get_moved() && pos.stage < scenes.size() - 1)
		{
			player->moveTo(scenes[pos.stage + 1]->get_startPos());
			scenes[pos.stage + 1]->refreshMonsters();
		}
		player->modify_moved(false);
	}

	return;
}
