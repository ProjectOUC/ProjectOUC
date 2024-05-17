#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "../attribute.h"
#include "../roles/character.h"

class Character;

class Gadget
{
public:
	// Todo: 添加主动使用的道具

	// Todo: 添加条件(如移动，回合后)触发的道具
	Gadget(int _gadgetIndex = 0, std::string _name = "");

	Gadget(const Gadget& g);

	int get_gadgetIndex() const { return gadgetIndex; };
	std::string get_name() const { return name; }

	virtual void before_battle(Character* owner, Character* enemy, int count) { return; }
	virtual void after_battle(Character* owner, Character* enemy, int count) { return; }
	virtual void during_battle(Character* owner, Character* enemy, int count) { return; }

	virtual Attr get_gadget() const { return Attr(); };
	virtual Attr lose_gadget() const { return Attr(); };
	virtual Attr use_gadget() const { return Attr(); };

private:
	int gadgetIndex;

	std::string name;
};

