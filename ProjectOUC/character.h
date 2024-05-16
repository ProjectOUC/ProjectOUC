#pragma once

#include <string>
#include <vector>

#include "gadgets/gadget.h"
#include "attribute.h"

class Gadget;

enum char_type
{
	MONSTER,
	PLAYER,
	CHEST,
	NPC
};

class Character
{
public:

	Character(Attr _attr, std::string _name = "", char_type _character_type = MONSTER, int _coin = 0);

	Character(const Character& c);


	Attr get_attr() const { return attr; }
	int get_health() const { return attr.health; }
	int get_attack() const { return attr.attack; }
	int get_defense() const { return attr.defense; }
	char_type get_type() const { return character_type; }
	std::string get_name() const { return name; }
	int get_coin() const { return coin; }



	void modify_attr(Attr x) { attr = attr + x; }
	void modify_health(int x) { attr.health += x; }
	void modify_attack(int x) { attr.attack += x; }
	void modify_defense(int x) { attr.defense += x; }
	void modify_type(char_type new_type) { character_type = new_type; }
	void modify_coin(int x) { coin += x; }

	void take_gadget(const Gadget* g, int num = 1);
	void lose_gadget(const Gadget* g, int num = 1);
	void use_gadget();

	bool dead() const { return attr.health <= 0; }
	
	std::vector<int> gadgets;

	~Character() {};
private:
	Attr attr;

	int coin;

	std::string name;

	char_type character_type;
};

