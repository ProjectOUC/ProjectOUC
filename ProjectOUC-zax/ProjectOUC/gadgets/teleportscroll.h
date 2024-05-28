#pragma once
#include "gadget.h"

class TeleportScroll : public Gadget
{
public:
	TeleportScroll(int _gadgetIndex = 5, std::string _name = "TeleportScroll") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(true);
		set_useful(true);
	};

	TeleportScroll(const TeleportScroll& other) :
		Gadget(other)
	{};

	Attr use_gadget() const;
};

