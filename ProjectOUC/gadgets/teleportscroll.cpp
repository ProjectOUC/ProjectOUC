#include "teleportscroll.h"

Attr TeleportScroll::use_gadget() const
{
	Attr attr;
	attr.teleport = true;
	return attr;
}