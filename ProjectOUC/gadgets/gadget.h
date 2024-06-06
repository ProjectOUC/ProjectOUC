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
	// Todo: 添加条件(如移动，回合后)触发的道具
	Gadget(int _gadgetIndex = 0, std::string _name = "");

	Gadget(const Gadget& g);

	int get_gadgetIndex() const { return gadgetIndex; };
	std::string get_name() const { return name; }
	bool get_stackable() const { return stackable; }
	bool get_useful() const { return useful; }

	void set_stackable(const bool& other) { stackable = other; }
	void set_useful(const bool& other) { useful = other; }

	virtual void before_battle(Character* owner, Character* enemy, int count) { return; }
	virtual void after_battle(Character* owner, Character* enemy, int count) { return; }
	virtual void during_battle(Character* owner, Character* enemy, int count) { return; }

	virtual Attr get_gadget() const { return Attr(); };
	virtual Attr lose_gadget() const { return Attr(); };
	virtual Attr use_gadget() const { return Attr(); };

	IMAGE img;

private:
	bool stackable;
	bool useful;
	int gadgetIndex;

	std::string name;
};

