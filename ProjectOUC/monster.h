#pragma once
#ifndef _MONSTER_H
#define _MONSTER_H
#endif

#include "character.h"

#include <iostream>

class Monster : public Character
{
public:
	Monster(int _health = 0, int _attack = 0, int _defense = 0,
		std::string _name = "", int _coin = 0) :
		Character(_health, _attack, _defense, _name, MONSTER, _coin) {};

};

Monster getMonster(int level);
