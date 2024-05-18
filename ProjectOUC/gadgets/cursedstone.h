#pragma once
#include "gadget.h"

class Gadget;
class CursedStone : public Gadget
{
public:
	CursedStone(int _gadgetIndex = 2, std::string _name = "CursedStone") :
		Gadget(_gadgetIndex, _name) 
	{
		set_stackable(true);
		set_useful(false);
	};

	CursedStone(const CursedStone& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};
