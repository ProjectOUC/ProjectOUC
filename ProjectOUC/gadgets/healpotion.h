#pragma once
#include "gadget.h"
class Gadget;
class HealPotion : public Gadget
{
public:
	HealPotion(int _gadgetIndex = 2, std::string _name = "HealPotion") :
		Gadget(_gadgetIndex, _name)
	{
		set_stackable(true);
		set_useful(true);
	};

	HealPotion(const HealPotion& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
	void before_battle(Character* owner, Character* enemy, int count);
};
