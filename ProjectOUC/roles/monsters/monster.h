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
<<<<<<< HEAD
	Monster(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Character(_attr, _name, MONSTER, _coin, _pos, _moved) {};

<<<<<<< HEAD
=======
	Monster(int _level = 0, Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Character(_attr, _name, MONSTER, _coin, _pos, _moved)
	{
		set_level(_level);
		set_exp(10 * _level + roll(2, 4));
	};

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	Monster(const Monster& monster) :
		Character(monster) {};

	Monster(std::string path) :
		Character(path) {};
<<<<<<< HEAD
=======
	Monster(const Monster& monster);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
};

Monster getMonster(int level);
