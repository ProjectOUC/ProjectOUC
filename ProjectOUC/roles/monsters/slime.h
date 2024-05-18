#pragma once
#include "monster.h"

class Slime : public Monster
{
public:
	Slime(int level = 0, Attr _attr = Attr(), std::string _name = "Slime", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Monster(_attr, _name, _coin, _pos, _moved)
	{
		Attr attr;
		attr.maxHealth = 40 + 15 * level + roll(3, 4);
		attr.health = attr.maxHealth;
		attr.attack = 10 + 20 * level;
		attr.diceNum = 5;
		attr.facet = 20;
		attr.defense = 40 + 15 * level + roll(3, 4);
		attr.attackFirstLevel = 4;
		attr.criticalAttackRate = 0.0f;
		attr.missRate = 50.0f;
		set_coin(3 * level + roll(1, 2));
		set_attr(attr);

	};
};

