#pragma once
#include "gadget.h";

Gadget::Gadget(int _gadgetIndex, int _health, int _attack,
	int _defense, std::string _name) :
	gadgetIndex(_gadgetIndex),
	health(_health),
	attack(_attack),
	defense(_defense),
	name(_name)
{};

Gadget::Gadget(const Gadget& g) :
	gadgetIndex(g.gadgetIndex),
	health(g.health),
	attack(g.attack),
	defense(g.defense),
	name(g.name)
{};