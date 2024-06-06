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
	int attack = owner->calc_attack();
	int defense = enemy->get_defense();
<<<<<<< HEAD
<<<<<<< HEAD
	int block = enemy->get_block();
	int damage = 0;
	damage = calc_damage(attack, defense, block);
=======
	int damage = 0;
	damage = calc_damage(attack, defense);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	int block = enemy->get_block();
	int damage = 0;
	damage = calc_damage(attack, defense, block);
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	enemy->modify_health(-damage);
	if (damage) std::cout << "¹­Ôì³É" << damage << "µãÉËº¦\n";
}