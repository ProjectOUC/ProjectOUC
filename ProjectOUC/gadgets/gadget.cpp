#pragma once
#include "gadget.h";
Gadget::Gadget(int _gadgetIndex, std::string _name) :
	gadgetIndex(_gadgetIndex),
	name(_name)
{};

Gadget::Gadget(const Gadget& g) :
	gadgetIndex(g.gadgetIndex),
	name(g.name)
{};




