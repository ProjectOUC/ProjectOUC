#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "attribute.h"
#include "character.h"

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

	virtual void before_battle(Character* owner, Character* enemy) { return; }
	virtual void after_battle(Character* owner, Character* enemy) { return; }
	virtual void during_battle(Character* owner, Character* enemy) { return; }

	virtual Attr get_gadget() const { return Attr(); };
	virtual Attr lose_gadget() const { return Attr(); };
	virtual Attr use_gadget() const { return Attr(); };

private:
	int gadgetIndex;

	std::string name;
};

class Sword : public Gadget
{
public:
	Sword(int _gadgetIndex = 0, std::string _name = "Sword") :
		Gadget(_gadgetIndex, _name)
	{  };

	Sword(const Sword& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

class Shield : public Gadget
{
public:
	Shield(int _gadgetIndex = 1, std::string _name = "Shield") :
		Gadget(_gadgetIndex, _name)
	{  };

	Shield(const Shield& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

class HealPotion : public Gadget
{
public:
	HealPotion(int _gadgetIndex = 2, std::string _name = "HealPotion") :
		Gadget(_gadgetIndex, _name)
	{  };

	HealPotion(const HealPotion& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const ;
};

class CursedStone : public Gadget
{
public:
	CursedStone(int _gadgetIndex = 2, std::string _name = "CursedStone") :
		Gadget(_gadgetIndex, _name) {};

	CursedStone(const CursedStone& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
};

class Bow : public Gadget
{
public:
	Bow(int _gadgetIndex = 4, std::string _name = "Bow") :
		Gadget(_gadgetIndex, _name)
	{  };

	Bow(const HealPotion& other) :
		Gadget(other)
	{};

	Attr get_gadget() const;
	Attr lose_gadget() const;
	Attr use_gadget() const;
	void before_battle(Character* owner, Character* enemy);
};

void initGadgetList();
void destroyGadgetList();