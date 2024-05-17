#include "bow.h"
Attr Bow::get_gadget() const
{
	Attr attr;
	attr.attackFirstLevel = 1;
	attr.criticalAttackRate = 5;
	attr.attack = 2;
	return attr;
}
Attr Bow::lose_gadget() const
{
	Attr attr;
	attr.attackFirstLevel = -1;
	attr.criticalAttackRate = -5;
	attr.attack = -2;
	return attr;
}
Attr Bow::use_gadget() const { return Attr(); }
void Bow::before_battle(Character* owner, Character* enemy, int count)
{
	int attack = owner->get_attack();
	int defense = enemy->get_defense();
	int damage = 0;
	if (attack - defense > 0) damage = (attack - defense);
	damage *= count;
	enemy->modify_health(-damage);
	if (damage) std::cout << "¹­Ôì³É" << damage << "µãÉËº¦\n";
}