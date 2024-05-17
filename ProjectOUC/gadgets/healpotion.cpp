#include "healpotion.h"
Attr HealPotion::get_gadget() const
{
	Attr attr;
	return attr;
}
Attr HealPotion::lose_gadget() const
{
	Attr attr;
	return attr;
}
Attr HealPotion::use_gadget() const
{
	Attr attr;
	attr.health = 50;
	return attr;
}

void HealPotion::before_battle(Character* owner, Character* enemy, int count)
{
	owner->modify_health(5 * count);
	std::cout << owner->get_name() << "»Ö¸´ÁË" << 5 * count << "µãÉúÃü\n";
}