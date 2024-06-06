#include "equipment.h"

int Equipment::upgrade()
{
	this->setLevel(this->getLevel() + 1);
	return this->getLevel();
}

int Equipment::fix(int addDurability)
{
	this->setDurability(this->getDurability() + addDurability >= 100 ? 100 : this->getDurability() + addDurability);
	return this->getDurability();
}
