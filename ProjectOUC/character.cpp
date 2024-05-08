#pragma once
#include "character.h"

#include <iostream>

Character::Character(int _health, int _attack, int _defense, std::string _name, char_type _character_type, int _coin) :
	health(_health),
	attack(_attack),
	defense(_defense),
	name(_name),
	character_type(_character_type),
	coin(_coin)
{
	gadgets.resize(max_gadget_index);
	gadgets_visited.resize(max_gadget_index);
};

Character::Character(const Character& c) :
	health(c.health),
	attack(c.attack),
	defense(c.defense),
	name(c.name),
	character_type(c.character_type),
	coin(c.coin)
{
	gadgets.resize(max_gadget_index);
	gadgets_visited.resize(max_gadget_index);
};

void Character::take_gadget(const Gadget& g, int num)
{
	this->modify_attack(num * g.get_attack());
	this->modify_defense(num * g.get_defense());
	this->modify_health(num * g.get_health());
	this->gadgets[g.get_gadgetIndex()] += num;
	this->gadgets_visited[g.get_gadgetIndex()] = 1;

	if (num > 0)
	{
		std::cout << "Get " << num << " gadget " << g.get_name() << "\n";
		//std::cout << this->health << " " << this->attack << " " << this->defense << "\n";
	}
}