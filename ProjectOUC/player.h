#pragma once
#include "character.h"
class Player: public Character
{
public:
	Player(Attr _attr, std::string _name = "", int _coin = 0) :
		Character(_attr, _name, PLAYER, _coin) {};

	Player(const Player& player) :
		Character(player) {};
};

Player* getPlayer(int level);