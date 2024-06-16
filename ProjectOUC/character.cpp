#pragma once
#include "character.h"

#include <iostream>

extern const int max_gadget_index;
extern int gadgetInHand;
extern std::set<int> usefulGadgetSet;
extern std::vector<Gadget*> gadgetList;
extern std::vector<int> gadgetVisited;

Character::Character(Attr _attr, std::string _name, char_type _character_type, int _coin) :
	attr(_attr),
	name(_name),
	character_type(_character_type),
	coin(_coin)
{
	gadgets.resize(max_gadget_index);
};

Character::Character(const Character& c) :
	attr(c.attr),
	name(c.name),
	character_type(c.character_type),
	coin(c.coin)
{
	gadgets.resize(max_gadget_index);
};

void Character::take_gadget(const Gadget* g, int num)
{
	Attr attr = g->get_gadget();

	this->modify_attr(num * attr);
	this->gadgets[g->get_gadgetIndex()] += num;
	if (this->get_type() == PLAYER) gadgetVisited[g->get_gadgetIndex()] = 1;

	if (num > 0)
	{
		std::cout << "Get " << num << " gadget " << g->get_name() << "\n";
		//std::cout << this->health << " " << this->attack << " " << this->defense << "\n";
	}
}

void Character::lose_gadget(const Gadget* g, int num)
{
	Attr attr = g->lose_gadget();

	this->modify_attr(-num * attr);
	this->gadgets[g->get_gadgetIndex()] -= num;
}

void Character::use_gadget()
{
	if (!usefulGadgetSet.count(gadgetInHand)) return;
	if (gadgets[gadgetInHand] <= 0) return;
	gadgets[gadgetInHand]--;
	this->modify_attr(gadgetList[gadgetInHand]->lose_gadget());
	this->modify_attr(gadgetList[gadgetInHand]->use_gadget());
}