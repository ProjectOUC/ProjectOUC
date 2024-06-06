#pragma once
#include "monster.h"

class Slime : public Monster
{
public:
<<<<<<< HEAD
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
=======
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
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
		set_attr(attr);

	};
};

