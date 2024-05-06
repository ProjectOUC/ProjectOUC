#pragma once

#include <string>
#include <vector>

const int max_gadget_index = 3;
class Gadget
{
public:
	// Todo: 添加主动使用的道具

	// Todo: 添加条件(如移动，回合后)触发的道具
	Gadget(int _gadgetIndex = 0, int _health = 0, int _attack = 0,
		int _defense = 0, std::string _name = "");

	Gadget(const Gadget& g);

	int get_gadgetIndex() const { return gadgetIndex; };
	int get_health() const { return health; }
	int get_attack() const { return attack; }
	int get_defense() const { return defense; }
	std::string get_name() const { return name; }

private:
	int gadgetIndex;
	int health;
	int	attack;
	int defense;

	std::string name;
};


const std::vector<Gadget> gadgetList({ {0, 0, 10, 1, "Sword"}, {1, 10, 0, 5, "Shield"}, {2, 100, 0, 0, "heal potion"} });