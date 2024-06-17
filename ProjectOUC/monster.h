#pragma once
#ifndef _MONSTER_H
#define _MONSTER_H
#endif

#include "character.h"

#include <iostream>

class Monster : public Character
{
public:
	Monster(Attr _attr, std::string _name = "", int _coin = 0) :
		Character(_attr, _name, MONSTER, _coin) {};

	Monster(const Monster& monster);
};

Monster getMonster(int level);
