#pragma once
#include "character.h"
class Player: public Character
{
public:
	Player(int _health = 0, int _attack = 0, int _defense = 0,
		std::string _name = "", int _coin = 0) :
		Character(_health, _attack, _defense, _name, PLAYER, _coin) {};

	Player(const Player& player) :
		Character(player) {};
};

namespace Players
{
	Player StrongTestPlayer();
	Player MediumTestPlayer();
	Player WeakTestPlayer();
}