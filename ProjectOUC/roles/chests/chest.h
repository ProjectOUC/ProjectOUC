#pragma once
#include "../character.h"

class Chest: public Character
{
public:
<<<<<<< HEAD
	Chest(Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest) :
		Character(chest) {};

	Chest(std::string path) :
		Character(path) {};
=======
	Chest(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
private:
};

Chest getChest(int level);
