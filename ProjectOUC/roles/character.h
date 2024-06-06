#pragma once

#include <string>
#include <vector>

#include "graphics.h"
#include "../attribute.h"
#include "../gadgets/gadget.h"
#include "../utils/position.h"
#include "../utils/random.h"

enum char_type
{
	MONSTER,
	PLAYER,
	CHEST,
	NPC
};

enum direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Gadget;

class Character
{
public:
	Character();

	Character(Attr _attr, std::string _name, char_type _character_type, int _coin, Position _pos, bool _moved);

	Character(const Character& c);

<<<<<<< HEAD
<<<<<<< HEAD
	Character(std::string path);

=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d

=======
	Character(std::string path);

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	Position get_pos() const { return pos; }
	Position get_lastPos() const { return lastPos; }
	bool get_moved() const { return moved; }
	bool get_teleport() const { return attr.teleport; }
	int get_agility() const { return attr.agility; }
	int get_strength() const { return attr.strength; }
	int get_wisdom() const { return attr.wisdom; }
	int get_essentialAttributeType() const{ return essentialAttribute; }
	int get_essentialAttributeValue() const
	{
<<<<<<< HEAD
		if (essentialAttribute == 0) return 0;
		else if (essentialAttribute == 1) return get_strength();
=======
		if (essentialAttribute == 1) return get_strength();
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
		else if (essentialAttribute == 2) return get_agility();
		else if (essentialAttribute == 3) return get_wisdom();
		return 0;
	}

	void modify_attr(Attr x) { attr = attr + x; }
	void modify_health(int x) { attr.health += x; }
<<<<<<< HEAD
=======
	void modify_maxHealth(int x) { attr.maxHealth += x; }
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	void modify_attack(int x) { attr.attack += x; }
	void modify_defense(int x) { attr.defense += x; }
	void modify_type(char_type new_type) { character_type = new_type; }
	void modify_coin(int x) { coin += x; }
	void modify_pos(const Position& other) { pos.set(other); }
	void modify_lastPos(const Position& other) { lastPos.set(other); }
	void modify_moved(const bool other) { moved = other; }
<<<<<<< HEAD
	void modify_food(const int other) { food += other; if (food > food_capacity) food = food_capacity; }
	void modify_food_capacity(const int other) { food_capacity += other; }
=======
	void modify_food(const int other) { food += other; if (food > calc_food_capacity()) food = calc_food_capacity(); }
	void modify_food_capacity(const int other) { food_capacity += other; }
	void modify_exp(const int other) { exp += other; }
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c

	void set_health(int x) { attr.health = x; }
	void set_teleport(const bool other) { attr.teleport = other; }
	void set_attr(const Attr other) { attr = other; }
<<<<<<< HEAD
	void set_food(const int other) { food = min(other, food_capacity); }
	void set_food_capacity(const int other) { food_capacity = other; }
	void set_coin(const int other) { coin = other; }
	void set_essentialAttributeType(const int other) { essentialAttribute = other; }

	Attr get_attr() const { return attr; }
	int get_maxHealth() const { return attr.maxHealth + 10 * attr.strength; }
	int get_health() const { return attr.health; }
	int get_attack() const { return attr.attack + get_essentialAttributeValue() + get_strength(); }
	int get_defense() const { return attr.defense + 1 * get_agility(); }
	int get_attackFirstLevel() const { return attr.attackFirstLevel + get_agility() * 2 - get_strength(); }
<<<<<<< HEAD
	int get_visibleRadius() const { return attr.visibleRadius; }
	int get_block() const { return attr.block + (int)(0.2 * get_strength()); }
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	float get_criticalAttackRate() const { return (float)(attr.criticalAttackRate + 2 * get_agility()); }
	float get_hitRate() const { return (float)(attr.hitRate - 0.5 * get_strength() + 1 * get_agility()); }
	float get_missRate() const { return (float)(attr.missRate + 0.5 * get_strength() - 1 * get_agility()); }

=======
	void set_food(const int other) { food = min(other, calc_food_capacity()); }
	void set_food_capacity(const int other) { food_capacity = other; }
	void set_coin(const int other) { coin = other; }
	void set_essentialAttributeType(const int other) { essentialAttribute = other; }
	void set_attack(const int other) { attr.attack = other; }
	void set_defense(const int other) { attr.defense = other; }
	void set_maxHealth(const int other) { attr.maxHealth = other; }
	void set_level(const int other) { level = other; }
	void set_exp(const int other) { exp = other; }
	void set_levelUpExp(const int other) { levelUpExp = other; }
	void set_strengthGen(const int other) { strengthGen = other; }
	void set_agilityGen(const int other) { agilityGen = other; }
	void set_wisdomGen(const int other) { wisdomGen = other; }


	Attr get_attr() const { return attr; }
	int get_maxHealth() const { return attr.maxHealth + 10 * get_strength(); }
	int get_health() const { return attr.health; }

	int get_attack() const { return attr.attack + get_essentialAttributeValue() + get_strength(); }

	int get_defense() const { return attr.defense + 1 * get_agility(); }

	int get_speed() const { return attr.speed + get_agility() - (int)(0.5f * get_strength()); }

	int get_visibleRadius() const { return attr.visibleRadius; }

	int get_block() const { return attr.block + (int)(0.2 * get_strength()); }

	float get_criticalAttackRate() const { return (float)(attr.criticalAttackRate + 2 * get_agility()); }

	float get_hitRate() const { return (float)(attr.hitRate - 0.5f * get_strength() + 1 * get_agility()); }

	float get_missRate() const { return (float)(attr.missRate - 0.5f * get_strength() + 1 * get_agility()); }

	int get_level() const { return level; }
	int get_exp() const { return exp; }
	int get_levelUpExp() const{ return levelUpExp; }
	int get_strengthGen() const { return strengthGen; }
	int get_agilityGen() const { return agilityGen;}
	int get_wisdomGen() const { return wisdomGen; }
 
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	char_type get_type() const { return character_type; }
	std::string get_name() const { return name; }
	int get_coin() const { return coin; }
	int get_food() const { return food; }
<<<<<<< HEAD
	int get_food_capacity() const { return food_capacity + 2 * get_strength(); }
	
	int calc_maxHealth() const { return attr.maxHealth + 10 * attr.strength; }
<<<<<<< HEAD
	int calc_attack() { return get_attack() + roll(attr.diceNum, attr.facet); }
=======
	int calc_attack() const { return get_attack() + roll(attr.diceNum, attr.facet); }
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	int calc_defense() const { return attr.defense + 1 * get_agility(); }
	int calc_min_attack() const { return get_attack() + attr.diceNum; }
	int calc_max_attack() const { return get_attack() + attr.diceNum * attr.facet; }
	int calc_attackFirstLevel() const { return attr.attackFirstLevel + get_agility() * 2 - get_strength(); }
	float calc_hitRate() const { return (float)(attr.hitRate - 0.5 * get_strength() + 1 * get_agility()); }
	float calc_missRate() const { return (float)(attr.missRate + 0.5 * get_strength() - 1 * get_agility()); }
=======
	int get_food_capacity() const { return food_capacity; }
	
	int calc_block() const { return attr.block + (int)(0.2f * attr.strength); }
	int calc_maxHealth() const { return attr.maxHealth + 10 * attr.strength; }
	int calc_attack() { return get_attack() + roll(attr.diceNum, attr.facet); }
	int calc_defense() const { return attr.defense + 1 * get_agility(); }
	int calc_min_attack() const { return get_attack() + attr.diceNum; }
	int calc_max_attack() const { return get_attack() + attr.diceNum * attr.facet; }
	int calc_food_capacity() const { return food_capacity + 2 * get_strength(); }
	int calc_speed() const { return (int)(attr.speed * min(4.0f, max(0.25f, 1.0f * attr.agility / attr.strength))); }
	float calc_hitRate() const { return (float)(attr.hitRate - get_strength() + get_agility()); }
	float calc_missRate() const { return (float)(attr.missRate + get_strength() - get_agility()); }
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c

	void take_gadget(const Gadget* g, int num = 1);
	void lose_gadget(const Gadget* g, int num = 1);
	void use_gadget();

	bool dead() const { return attr.health <= 0 || (character_type == PLAYER && food < 0); }

	void moveTo(const Position& somewhere);
	void move(direction dir);
<<<<<<< HEAD
<<<<<<< HEAD

	void saveCharacter(std::string path);
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	
	std::vector<int> gadgets;

	IMAGE img;

=======
	void levelUp();

	void saveCharacter(std::string path);
	
	std::vector<int> gadgets;

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	~Character() {};
private:
	Attr attr;

	int coin;
	int food;
	int food_capacity;
	int essentialAttribute;

<<<<<<< HEAD
=======
	int level;
	int exp;
	int levelUpExp;
	int strengthGen;
	int agilityGen;
	int wisdomGen;

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	std::string name;

	char_type character_type;

	Position pos, lastPos;

	bool moved;
};

<<<<<<< HEAD
<<<<<<< HEAD
int calc_damage(int attack, int defense, int block);
=======
int calc_damage(int attack, int defense);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
int calc_damage(int attack, int defense, int block);
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
