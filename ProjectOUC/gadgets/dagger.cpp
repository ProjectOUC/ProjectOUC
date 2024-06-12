#include "dagger.h"
Attr Dagger::get_gadget() const
{
	static Attr attr;
	attr.agility = 3;
	attr.diceNum = 1;
	attr.speed = 5;
	return attr;
}
Attr Dagger::lose_gadget() const
{
	static Attr attr;
	attr.agility = -3;
	attr.diceNum = -1;
	attr.speed= -5;
	return attr;
}
Attr Dagger::use_gadget() const
{
	static Attr attr;
	return attr;
}
