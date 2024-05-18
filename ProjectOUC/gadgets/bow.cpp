#include "bow.h"
Attr Bow::get_gadget() const
{
	Attr attr;
	attr.strength = 1;
	attr.agility = 1;
	attr.criticalAttackRate = 5;
	attr.attack = 5;
	return attr;
}
Attr Bow::lose_gadget() const
{
	Attr attr;
	attr.strength = -1;
	attr.agility = -1;
	attr.criticalAttackRate = -10;
	attr.attack = -5;
	return attr;
}
void Bow::before_battle(Character* owner, Character* enemy, int count)
{
	int attack = owner->get_attack();
	int defense = enemy->get_defense();
	int damage = 0;
	if (attack - defense > 0) damage = (attack - defense);
	enemy->modify_health(-damage);
	if (damage) std::cout << "�����" << damage << "���˺�\n";
}