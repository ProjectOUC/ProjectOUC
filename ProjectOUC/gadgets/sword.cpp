#include "sword.h"
Attr Sword::get_gadget() const
{
	static Attr attr;
	attr.strength = 2;
	attr.attack = 8;
	attr.diceNum = -1;
<<<<<<< HEAD
	attr.facet = 2;
=======
	attr.facet = -2;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	return attr;
}
Attr Sword::lose_gadget() const
{
	static Attr attr;
	attr.strength = -2;
	attr.attack = -8;
	attr.diceNum = 1;
	attr.facet = -2;
	return attr;
}
Attr Sword::use_gadget() const
{
	static Attr attr;
	return attr;
}
