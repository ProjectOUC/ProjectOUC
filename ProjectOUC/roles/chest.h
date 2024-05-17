#pragma once
#include "character.h"

class Chest: public Character
{
public:
	Chest(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest);
private:
};

Chest getChest(int level);
