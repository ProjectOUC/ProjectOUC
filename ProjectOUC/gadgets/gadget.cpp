#pragma once
#include "gadget.h"
Gadget::Gadget(int _gadgetIndex, std::string _name) :
	gadgetIndex(_gadgetIndex),
	name(_name)
{
	stackable = false;
	useful = false;
};

Gadget::Gadget(const Gadget& g) :
	gadgetIndex(g.gadgetIndex),
	name(g.name),
	stackable(g.stackable),
	useful(g.useful)
{};




