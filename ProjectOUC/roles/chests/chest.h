#pragma once
#include "../character.h"

class Chest: public Character
{
public:
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	Chest(Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest) :
		Character(chest) {};

	Chest(std::string path) :
		Character(path) {};
<<<<<<< HEAD
=======
	Chest(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false);

	Chest(const Chest& chest);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
private:
};

Chest getChest(int level);
