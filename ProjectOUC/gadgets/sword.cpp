#include "sword.h"
Attr Sword::get_gadget() const
{
	static Attr attr;
	attr.attack = 5;
	return attr;
}
Attr Sword::lose_gadget() const
{
	static Attr attr;
	attr.attack = -5;
	return attr;
}
Attr Sword::use_gadget() const
{
	static Attr attr;
	return attr;
}
