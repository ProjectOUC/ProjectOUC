#pragma once
#include "../character.h"

class Chest: public Character
{
public:
	Chest(Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest) :
		Character(chest) {};

	Chest(std::string path) :
		Character(path) {};
private:
};

Chest getChest(int level);
