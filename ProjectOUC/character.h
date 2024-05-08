#pragma once


#include <string>
#include <vector>

#include "gadget.h"


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

	Character(int _health = 0, int _attack = 0, int _defense = 0,
		std::string _name = "", char_type _character_type = MONSTER, int _coin = 0);

	Character(const Character& c);

	int get_health() const { return health; }
	int get_attack() const { return attack; }
	int get_defense() const { return defense; }
	char_type get_type() const { return character_type; }
	std::string get_name() const { return name; }
	int get_coin() const { return coin; }

	void modify_health(int x) { health += x; }
	void modify_attack(int x) { attack += x; }
	void modify_defense(int x) { defense += x; }
	void modify_type(char_type new_type) { character_type = new_type; }
	void modify_coin(int x) { coin += x; }

	void take_gadget(const Gadget& g, int num=1);

	bool dead() const { return health <= 0; }
	
	std::vector<int> gadgets;
	std::vector<int> gadgets_visited;

	~Character() {};
private:
	int health;
	int attack;
	int defense;
	int coin;

	std::string name;

	char_type character_type;
};

