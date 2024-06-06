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
	Monster(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Character(_attr, _name, MONSTER, _coin, _pos, _moved) {};

	Monster(const Monster& monster) :
		Character(monster) {};

	Monster(std::string path) :
		Character(path) {};
};

Monster getMonster(int level);
