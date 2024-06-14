#pragma once

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

	Character(std::string path);

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
		if (essentialAttribute == 1) return get_strength();
		else if (essentialAttribute == 2) return get_agility();
		else if (essentialAttribute == 3) return get_wisdom();
		return 0;
	}

	void modify_attr(Attr x) { attr = attr + x; }
	void modify_health(int x) { attr.health += x; }
	void modify_maxHealth(int x) { attr.maxHealth += x; }
	void modify_attack(int x) { attr.attack += x; }
	void modify_defense(int x) { attr.defense += x; }
	void modify_type(char_type new_type) { character_type = new_type; }
	void modify_coin(int x) { coin += x; }
	void modify_pos(const Position& other) { pos.set(other); }
	void modify_lastPos(const Position& other) { lastPos.set(other); }
	void modify_moved(const bool other) { moved = other; }
	void modify_food(const int other) { food += other; if (food > calc_food_capacity()) food = calc_food_capacity(); }
	void modify_food_capacity(const int other) { food_capacity += other; }
	void modify_exp(const int other) { exp += other; }

	void set_health(int x) { attr.health = x; }
	void set_teleport(const bool other) { attr.teleport = other; }
	void set_attr(const Attr other) { attr = other; }
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
 
	char_type get_type() const { return character_type; }
	std::string get_name() const { return name; }
	int get_coin() const { return coin; }
	int get_food() const { return food; }
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

	void take_gadget(const Gadget* g, int num = 1);
	void lose_gadget(const Gadget* g, int num = 1);
	void use_gadget();

	bool dead() const { return attr.health <= 0 || (character_type == PLAYER && food < 0); }

	void moveTo(const Position& somewhere);
	void move(direction dir);
	void levelUp();

	void saveCharacter(std::string path);
	
	std::vector<int> gadgets;

	~Character() {};
private:
	Attr attr;

	int coin;
	int food;
	int food_capacity;
	int essentialAttribute;

	int level;
	int exp;
	int levelUpExp;
	int strengthGen;
	int agilityGen;
	int wisdomGen;

	std::string name;

	char_type character_type;

	Position pos, lastPos;

	bool moved;
};

int calc_damage(int attack, int defense, int block);