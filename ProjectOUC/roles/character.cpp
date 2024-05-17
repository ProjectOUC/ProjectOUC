#pragma once
#include "character.h"

#include <iostream>

extern const int max_gadget_index;
extern int gadgetInHand;
extern std::set<int> usefulGadgetSet;
extern std::vector<Gadget*> gadgetList;
extern std::vector<int> gadgetVisited;

Character::Character() :
	attr(Attr()),
	name(""),
	character_type(MONSTER),
	coin(0),
	pos(Position()),
	lastPos(Position()),
	moved(false)
{}


Character::Character(Attr _attr, std::string _name, char_type _character_type, int _coin, Position _pos, bool _moved):
	attr(_attr),
	name(_name),
	character_type(_character_type),
	coin(_coin),
	pos(_pos),
	lastPos(_pos),
	moved(_moved)
{
	gadgets.resize(max_gadget_index);
};

Character::Character(const Character& c) :
	attr(c.attr),
	name(c.name),
	character_type(c.character_type),
	coin(c.coin),
	pos(c.pos),
	lastPos(c.lastPos),
	moved(c.moved)
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

void Character::moveTo(const Position& somewhere)
{
	lastPos = pos;
	pos = somewhere;
}

void Character::move(direction dir)
{
	lastPos = pos;
	switch (dir)
	{
	case UP: pos = pos + Position(0, 0, -1); break;
	case DOWN: pos = pos + Position(0, 0, 1); break;
	case LEFT: pos = pos + Position(0, -1, 0); break;
	case RIGHT: pos = pos + Position(0, 1, 0); break;
	}
}