#pragma once
#include "monster.h"

class Slime : public Monster
{
public:
	Slime(int _level = 0, Attr _attr = Attr(), std::string _name = "Slime", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Monster(_level, _attr, _name, _coin, _pos, _moved)
	{
		Attr attr;
		attr.agility = 4 + _level + roll(1, 4);
		attr.strength = 10 + 2 * _level + roll(3, 4);
		attr.maxHealth = roll(1, 20);

		attr.health = attr.get_maxHealth();
		attr.diceNum = 2;
		attr.facet = 12;
		attr.defense = 40 + 20 * _level + roll(3, 5);
		attr.speed = 10;
		attr.hitRate = 50.0f;
		attr.missRate = 50.0f;
		attr.criticalAttackRate = 0.0f;

		set_coin(2 * _level + roll(1, 2));
		set_attr(attr);

	};
};

