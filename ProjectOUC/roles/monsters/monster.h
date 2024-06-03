#pragma once
#ifndef _MONSTER_H
#define _MONSTER_H
#endif

#include "../character.h"

#include <iostream>

extern std::vector<Gadget*> gadgetList;

class Monster : public Character
{
public:
	Monster(int _level = 0, Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Character(_attr, _name, MONSTER, _coin, _pos, _moved)
	{
		set_level(_level);
		set_exp(10 * _level + roll(2, 4));
	};

	Monster(const Monster& monster) :
		Character(monster) {};

	Monster(std::string path) :
		Character(path) {};
};

Monster getMonster(int level);
