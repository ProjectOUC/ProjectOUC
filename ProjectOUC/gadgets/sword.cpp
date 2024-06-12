#include "sword.h"
Attr Sword::get_gadget() const
{
	static Attr attr;
	attr.strength = 5;
	attr.facet = 2;
	return attr;
}
Attr Sword::lose_gadget() const
{
	static Attr attr;
	attr.strength = -5;
	attr.facet = -2;
	return attr;
}
Attr Sword::use_gadget() const
{
	static Attr attr;
	return attr;
}
