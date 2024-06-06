
#pragma once
#include "gadget.h"


class Dagger : public Gadget
{
public:
	Dagger(int _gadgetIndex = 7, std::string _name = "Dagger") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(false);
		set_useful(false);
	};

	Dagger(const Dagger& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

