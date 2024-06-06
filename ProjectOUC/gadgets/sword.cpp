#include "sword.h"
Attr Sword::get_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
	attr.strength = 2;
	attr.attack = 8;
	attr.diceNum = -1;
<<<<<<< HEAD
	attr.facet = 2;
=======
	attr.facet = -2;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	attr.strength = 5;
	attr.facet = 2;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	return attr;
}
Attr Sword::lose_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
	attr.strength = -2;
	attr.attack = -8;
	attr.diceNum = 1;
=======
	attr.strength = -5;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	attr.facet = -2;
	return attr;
}
Attr Sword::use_gadget() const
{
	static Attr attr;
	return attr;
}
