#include "battle.h"
#include <iostream>

const int MAX_BATTLE_TURN = 1000;

Battle::Battle(Character& _attacker, Character& _defenser) :
	attacker(&_attacker),
	defenser(&_defenser)
{
	turn = 0;
}

void Battle::winnerGetGadgets(Character* winner, Character* loser)
{
	for (int i = 0; i < max_gadget_index; ++i)
	{
		winner->take_gadget(gadgetList[i], loser->gadgets[i]);
	}
	winner->modify_coin(loser->get_coin());
}

bool Battle::battle()
{
	/* Todo
	* while(!battleStep());
	* 
	* if player dead:
	*     return false;
	* winner takes loser's gadgets
	* return true;
	*/
	while (!battleStep())
	{
		//
		if (turn >= MAX_BATTLE_TURN)
		{
			return false;
		}
	}
	if (attacker->dead() && attacker->get_type() == PLAYER) return false;
	else if (defenser->dead() && defenser->get_type() == PLAYER) return false;

	if (attacker->get_type() == PLAYER) winnerGetGadgets(attacker, defenser);
	else winnerGetGadgets(defenser, attacker);

	return true;
}

bool Battle::battleStep()
{
	//std::cout << defenser->get_health() << " " << attacker->get_health() << "\n";
	int damage;
	turn = turn + 1;

	//Todo: 加入gadget
	damage = max(1, attacker->get_attack() - defenser->get_defense());
	// 首轮保护，防止玩家秒怪
	if (turn == 1 && defenser->get_type() != PLAYER)
	{
		damage = min(damage, defenser->get_health() + 1);
	}
	defenser->modify_health(-damage);
	if (defenser->dead() || attacker->dead())
	{
		return true;
	}

	damage = max(1, defenser->get_attack() - attacker->get_defense());
	attacker->modify_health(-damage);
	if (defenser->dead() || attacker->dead())
	{
		return true;
	}
	return false;
}