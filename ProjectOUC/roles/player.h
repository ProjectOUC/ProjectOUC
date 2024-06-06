#pragma once
#include "character.h"
class Player: public Character
{
public:
	Player(Attr _attr, std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false) :
		Character(_attr, _name, PLAYER, _coin, _pos, _moved) {};

	Player(const Player& player) :
		Character(player) {};
<<<<<<< HEAD

	Player(std::string path) :
		Character(path) {};
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
};

Player* getPlayer(int level);