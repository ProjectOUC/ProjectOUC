#pragma once
#include "monster.h"

class Goblin : public Monster
{
public:
	Goblin(int level = 0, Attr _attr = Attr(), std::string _name = "Goblin", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Monster(_attr, _name, _coin, _pos, _moved)
	{
		Attr attr;
		attr.maxHealth = 50 + 20 * level + roll(5, 6);
		attr.health = attr.maxHealth;
		attr.attack = 15 + 5 * level + roll(1, 3);
		attr.diceNum = 5;
		attr.facet = 2;
		attr.defense = 4 + 2 * level + roll(2, 2);
		attr.block = level + 1;
		attr.attackFirstLevel = 5 + 2 * level + roll(5, 2);
		attr.criticalAttackRate = (float)(10 + 2 * level + roll(2, 2));
		attr.missRate = (float)(10 - level + random(-1, 1));
		set_attr(attr);
		set_food_capacity(7 + level * 5 + roll(3, 2));
		set_food(get_food_capacity());
		set_coin(10 * level + roll(5, 2));
		if (oneIn(10))
		{
			static std::vector<int> weights{5, 3, 3, 1, 2, 1, 3};
			this->take_gadget(gadgetList[randIndByWeights(weights)]);
		}
	};
};

