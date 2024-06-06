#include "cursedstone.h"
Attr CursedStone::get_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
	attr.health = attr.maxHealth = -5;
=======
	attr.health = attr.maxHealth = -20;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	return attr;
}
Attr CursedStone::lose_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
=======
	attr.health = 20;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	return attr;
}
Attr CursedStone::use_gadget() const
{
	static Attr attr;
	return attr;
}

