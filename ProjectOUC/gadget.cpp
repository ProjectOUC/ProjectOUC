#pragma once
#include "gadget.h";

extern const int max_gadget_index = 5;
std::vector<Gadget*> gadgetList;
std::set<int> usefulGadgetSet;
std::vector<int> gadgetVisited;

Gadget::Gadget(int _gadgetIndex, std::string _name) :
	gadgetIndex(_gadgetIndex),
	name(_name)
{};

Gadget::Gadget(const Gadget& g) :
	gadgetIndex(g.gadgetIndex),
	name(g.name)
{};

Attr Sword::get_gadget() const
{
	static Attr attr;
	attr.attack = 5;
	return attr;
}
Attr Sword::lose_gadget() const
{
	static Attr attr;
	attr.attack = -5;
	return attr;
}
Attr Sword::use_gadget() const
{
	static Attr attr;
	return attr;
}

Attr Shield::get_gadget() const
{
	static Attr attr;
	attr.defense = 3;
	return attr;
}
Attr Shield::lose_gadget() const
{
	static Attr attr;
	attr.defense = -3;
	return attr;
}
Attr Shield::use_gadget() const
{
	static Attr attr;
	return attr;
}

Attr HealPotion::get_gadget() const
{
	static Attr attr;
	return attr;
}
Attr HealPotion::lose_gadget() const
{
	static Attr attr;
	return attr;
}
Attr HealPotion::use_gadget() const
{
	static Attr attr;
	attr.health = 50;
	return attr;
}

Attr CursedStone::get_gadget() const
{
	static Attr attr;
	attr.health = attr.maxHealth = -30;
	return attr;
}
Attr CursedStone::lose_gadget() const
{
	static Attr attr;
	return attr;
}
Attr CursedStone::use_gadget() const
{
	static Attr attr;
	return attr;
}

Attr Bow::get_gadget() const
{
	Attr attr;
	attr.attackFirstLevel = 1;
	attr.criticalAttackRate = 5;
	attr.attack = 2;
	return attr;
}
Attr Bow::lose_gadget() const
{
	Attr attr;
	attr.attackFirstLevel = -1;
	attr.criticalAttackRate = -5;
	attr.attack = -2;
	return attr;
}
Attr Bow::use_gadget() const { return Attr(); }


void initGadgetList()
{
	gadgetList.resize(max_gadget_index);
	gadgetVisited.resize(max_gadget_index);

	gadgetList[0] = new Sword;

	gadgetList[1] = new Shield;

	gadgetList[2] = new HealPotion;
	usefulGadgetSet.insert(2);

	gadgetList[3] = new CursedStone;

	gadgetList[4] = new Bow;


}

void destroyGadgetList()
{
	for (int i = 0; i < max_gadget_index; ++i)
	{
		delete gadgetList[i];
	}
}