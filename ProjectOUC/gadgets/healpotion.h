#pragma once
#include "gadget.h"
class Gadget;
class HealPotion : public Gadget
{
public:
	HealPotion(int _gadgetIndex = 2, std::string _name = "HealPotion") :
		Gadget(_gadgetIndex, _name)
	{  };

	HealPotion(const HealPotion& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};
