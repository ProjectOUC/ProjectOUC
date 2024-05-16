#pragma once
#include "gadget.h"

class Bow : public Gadget
{
public:
	Bow(int _gadgetIndex = 4, std::string _name = "Bow") :
		Gadget(_gadgetIndex, _name)
	{  };

	Bow(const Bow& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
	void before_battle(Character* owner, Character* enemy);
};