#include "battle.h"
#include <iostream>

extern const int MAX_BATTLE_TURN = 1000;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;

Battle::Battle(Character* _attacker, Character* _defenser)
{
	attacker = _attacker;
	defenser = _defenser;
	if (_attacker->get_attr().attackFirstLevel < _defenser->get_attr().attackFirstLevel)
	{
		attacker = _defenser;
		defenser = _attacker;
	}
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
		std::cout << "战斗进行中，当前回合: " << turn << "\n";
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
	turn = turn + 1;

	// 回合开始道具

	if (attack(0)) return true;
	if (attack(1)) return true;

	// 回合结束道具
	
	return false;
}

bool Battle::attack(int player)
{
	Character* c1, *c2;
	if (player == 0)
	{
		c1 = attacker;
		c2 = defenser;
	}
	else
	{
		c1 = defenser;
		c2 = attacker;
	}

	int damage = 0;
	bool miss = false;
	bool critical = 0;
	int attack = c1->get_attack();
	int defense = c2->get_defense();

	if (random(0, 100) < c1->get_attr().criticalAttackRate) critical = true;
	if (random(0, 100) < c1->get_attr().missRate) miss = true;

	if (miss) damage = 0;
	if (critical) attack = attack * 2;
	damage = attack - defense;
	damage = max(damage, 0);

	if (miss) std::cout << c2->get_name() << "闪避了" << c1->get_name() << "的攻击\n";
	else if (critical) std::cout << c1->get_name() << "造成了暴击\n";
	c2->modify_health(-damage);
	std::cout << c1->get_name() << "对" << c2->get_name() << "造成" << damage << "点伤害\n\n";


	if (c1->dead() || c2->dead()) return true;
	return false;
}