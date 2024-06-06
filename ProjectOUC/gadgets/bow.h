#pragma once
#include "gadget.h"

class Bow : public Gadget
{
public:
<<<<<<< HEAD
	Bow(int _gadgetIndex = 4, std::string _name = "Bow") :
=======
	Bow(int _gadgetIndex = 4, std::string _name ="Bow") :
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(false);
		set_useful(false);
	};

	Bow(const Bow& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	void before_battle(Character* owner, Character* enemy, int count);
};