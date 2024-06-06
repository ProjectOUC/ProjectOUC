#pragma once
#include "chest.h"

Chest::Chest(Attr _attr, std::string _name, int _coin, Position _pos, bool _moved) :
<<<<<<< HEAD
	Character(_attr, _name, CHEST, _coin, _pos, _moved) {};

Chest getChest(int level)
{
	Attr attr;
	if (level == 2) return Chest(attr, "Large Chest", 100);
	else if (level == 1) return Chest(attr, "Medium Chest", 50);
	else if (level == 0) return Chest(attr, "Small Chest", 10);
	else
	{
		attr.maxHealth = attr.health = 100;
		attr.attack = 15;
		attr.defense = 0;
		attr.attackFirstLevel = 10;
		return Chest(attr, "Chest Monster", 10);
	}
}
=======
	Character(_attr, _name, CHEST, _coin, _pos, _moved) {};
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
