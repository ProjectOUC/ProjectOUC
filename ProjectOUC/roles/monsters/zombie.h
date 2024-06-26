#pragma once
#pragma once
#include "monster.h"

class Zombie : public Monster
{
public:
    Zombie(int _level = 0, Attr _attr = Attr(), std::string _name = "Zombie", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved,ZOMBIE)
    {
		Attr attr;
		attr.strength = 8 + 3 * _level + roll(2, 3);
		attr.agility = 6 + 2 * _level + roll(2, 3);
		attr.wisdom = 1 * (_level + 1);
		attr.maxHealth = roll(2, 20);

		attr.health = attr.get_maxHealth();
		attr.diceNum = 2;
		attr.facet = _level + 4;
		attr.block = _level + 1;

		attr.speed = 15 + 5 * _level + roll(2, 2);

		attr.hitRate = 90;
		attr.criticalAttackRate = (float)(10 + 2 * _level + roll(2, 2));
		attr.missRate = (float)(10 + 2 * _level);

		set_attr(attr);
		set_food(attr.strength / 2);
		set_coin(5 + 3 * _level + roll(1, 3));
		if (oneIn(5))
		{
			static std::vector<int> weights{ 5, 3, 3, 1, 2, 1, 3 };
			this->take_gadget(gadgetList[randIndByWeights(weights)]);
		}
    }
};

