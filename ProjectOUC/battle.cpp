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

void Battle::useAllGadgets(Character* owner, Character* enemy, int cond)
{
	/*
	cond:
		1: 战斗开始
		2: 战斗结束
		3: 战斗中
	*/
	for (int i = 0; i < max_gadget_index; ++i)
	{
		if (owner->gadgets[i] == 0) continue;
		switch (cond)
		{
		case 1:gadgetList[i]->before_battle(owner, enemy, owner->gadgets[i]); break;
		case 2:gadgetList[i]->after_battle(owner, enemy, owner->gadgets[i]); break;
		case 3:gadgetList[i]->during_battle(owner, enemy, owner->gadgets[i]); break;
		}
	}
}


int Battle::checkEnd(Character* c1, Character* c2)
{
	/*
	return:
		0: 游戏结束
		1: 获胜
		2: 游戏未结束
	*/
	if (c1->get_type() == PLAYER && c1->dead()) return 0;
	if (c2->get_type() == PLAYER && c2->dead()) return 0;
	if (c1->get_type() != PLAYER && c1->dead())
	{
		useAllGadgets(c2, c1, 2);
		winnerGetGadgets(c2, c1);
		return 1;
	}
	if (c2->get_type() != PLAYER && c2->dead())
	{
		useAllGadgets(c1, c2, 2);
		winnerGetGadgets(c1, c2);
		return 1;
	}
	return 2;
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
	useAllGadgets(attacker, defenser, 1);
	int ending = checkEnd(attacker, defenser);
	if (ending == 0) return false;
	else if (ending == 1) return true;

	useAllGadgets(defenser, attacker, 1);
	ending = checkEnd(defenser, attacker);
	if (ending == 0) return false;
	else if (ending == 1) return true;

	while (!battleStep())
	{
		std::cout << "战斗进行中，当前回合: " << turn << "\n";
		if (turn >= MAX_BATTLE_TURN)
		{
			return false;
		}
	}

	ending = checkEnd(attacker, defenser);
	if (ending == 0) return false;
	else if (ending == 1) return true;
	return false;
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

	if (random(0, 10000) < (int)(100 * c1->get_attr().criticalAttackRate)) critical = true;
	if (random(0, 10000) < (int)(100 * c1->get_attr().missRate)) miss = true;

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