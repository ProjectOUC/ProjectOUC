#pragma once
#include "gadget.h"

class Key : public Gadget
{
public:
	Key(int _gadgetIndex = 6, std::string _name = "Key") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(true);
		set_useful(false);
	};

	Key(const Key& other) :
		Gadget(other)
	{};
};
