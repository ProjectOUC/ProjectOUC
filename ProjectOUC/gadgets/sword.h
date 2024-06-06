#pragma once
#include "gadget.h"

class Gadget;
class Sword : public Gadget
{
public:
	Sword(int _gadgetIndex = 0, std::string _name = "Sword") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(false);
		set_useful(false);
	};

	Sword(const Sword& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

