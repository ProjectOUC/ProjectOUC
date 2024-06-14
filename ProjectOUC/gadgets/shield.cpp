#include "shield.h"
Attr Shield::get_gadget() const
{
	static Attr attr;
	attr.defense = 3;
	attr.defense = 5;
	attr.block = 2;

	return attr;
}
Attr Shield::lose_gadget() const
{
	static Attr attr;
	attr.defense = -5;
	attr.block = -2;
	return attr;
}
Attr Shield::use_gadget() const
{
	static Attr attr;
	return attr;
}