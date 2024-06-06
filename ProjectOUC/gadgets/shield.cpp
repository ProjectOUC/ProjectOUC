#include "shield.h"
Attr Shield::get_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
	attr.defense = 3;
=======
	attr.defense = 5;
	attr.block = 2;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	return attr;
}
Attr Shield::lose_gadget() const
{
	static Attr attr;
<<<<<<< HEAD
	attr.defense = -3;
=======
	attr.defense = -5;
	attr.block = -2;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	return attr;
}
Attr Shield::use_gadget() const
{
	static Attr attr;
	return attr;
}