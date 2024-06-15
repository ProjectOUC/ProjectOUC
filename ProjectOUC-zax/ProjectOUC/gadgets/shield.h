#pragma once
#include "gadget.h"


class Shield : public Gadget
{
public:
	Shield(int _gadgetIndex = 1, std::string _name = "Shield") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(false);
		set_useful(false);
	};

	Shield(const Shield& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

