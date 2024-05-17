#include "cursedstone.h"
Attr CursedStone::get_gadget() const
{
	static Attr attr;
	attr.health = attr.maxHealth = -5;
	return attr;
}
Attr CursedStone::lose_gadget() const
{
	static Attr attr;
	return attr;
}
Attr CursedStone::use_gadget() const
{
	static Attr attr;
	return attr;
}

