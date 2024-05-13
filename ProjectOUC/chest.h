#pragma once
#include "character.h"

class Chest: public Character
{
public:
	Chest(int _health = 0, int _attack = 0, int _defense = 0,
		std::string _name = "", int _coin = 0) :
		Character(_health, _attack, _defense, _name, CHEST, _coin) {};

	Chest(const Chest& chest);
private:
};

Chest getChest(int level);
