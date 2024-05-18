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
	moved(false),
	food(0),
	food_capacity(0),
	essentialAttribute(0)
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
	food = food_capacity = 0;
	essentialAttribute = 0;
	gadgets.resize(max_gadget_index);
};

Character::Character(const Character& c) :
	attr(c.attr),
	name(c.name),
	character_type(c.character_type),
	coin(c.coin),
	pos(c.pos),
	lastPos(c.lastPos),
	moved(c.moved),
	food(c.food),
	food_capacity(c.food_capacity),
	essentialAttribute(c.essentialAttribute)
{
	gadgets.resize(max_gadget_index);
};

void Character::take_gadget(const Gadget* g, int num)
{
	Attr attr = g->get_gadget();

	if (this->gadgets[g->get_gadgetIndex()] > 0 && g->get_stackable() == false)
		attr = Attr();
	else if (g->get_stackable() == true)
		attr = num * attr;
	
	this->modify_attr(num * attr);
	this->gadgets[g->get_gadgetIndex()] += num;
	if (this->get_type() == PLAYER) gadgetVisited[g->get_gadgetIndex()] = 1;

	if (num > 0 && this->get_type() == PLAYER)
	{
		std::cout << "Get " << num << " gadget " << g->get_name() << "\n";
		//std::cout << this->health << " " << this->attack << " " << this->defense << "\n";
	}
}

void Character::lose_gadget(const Gadget* g, int num)
{
	Attr attr = g->lose_gadget();
	if (num < 0) return;
	int ind = g->get_gadgetIndex();
	if (this->gadgets[ind] < num) num = this->gadgets[ind];
	if (g->get_stackable() == true)
		attr = attr * num;
	else if (g->get_stackable() == false && this->gadgets[ind] > num)
		attr = Attr();

	this->modify_attr(attr);
	this->gadgets[g->get_gadgetIndex()] -= num;
}

void Character::use_gadget()
{
	if (!gadgetList[gadgetInHand]->get_useful())
	{
		std::cout << gadgetList[gadgetInHand]->get_name() << "无法使用\n";
		return;
	}
	if (gadgets[gadgetInHand] <= 0)
	{
		std::cout << gadgetList[gadgetInHand]->get_name() << "数量不足\n";
		return;
	}
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
	if (pos.stage)
	{
		food -= pos.stage;
		std::cout << "food: " << food << '\n';
	}
}

int calc_damage(int attack, int defense)
{
	return (int)(1.0f * attack / (defense + 50) * 50);
}