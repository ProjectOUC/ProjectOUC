#include "healpotion.h"
Attr HealPotion::get_gadget() const
{
	static Attr attr;
	return attr;
}
Attr HealPotion::lose_gadget() const
{
	static Attr attr;
	return attr;
}
Attr HealPotion::use_gadget() const
{
	static Attr attr;
	attr.health = 50;
	return attr;
}
