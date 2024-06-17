#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "character.h"

#include <iostream>

extern const int max_gadget_index;
extern int gadgetInHand;
extern std::vector<Gadget*> gadgetList;
extern std::vector<int> gadgetVisited;

Character::Character() :
	attr(Attr()),
	name(""),
	character_type(MONSTER),
	coin(0),
	pos(Position()),
	lastPos(Position()),
	moved(false),
	food(0),
	food_capacity(0),
	essentialAttribute(0),
	level(0),
	exp(0),
	levelUpExp(0),
	strengthGen(0),
	agilityGen(0),
	wisdomGen(0)
{}


Character::Character(Attr _attr, std::string _name, char_type _character_type, int _coin, Position _pos, bool _moved):
	attr(_attr),
	name(_name),
	character_type(_character_type),
	coin(_coin),
	pos(_pos),
	lastPos(_pos),
	moved(_moved)
{
	food = food_capacity = 0;
	essentialAttribute = 0;
	gadgets.resize(max_gadget_index);
	level = exp = levelUpExp = agilityGen = strengthGen = wisdomGen = 0;
};

Character::Character(const Character& c) :
	attr(c.attr),
	name(c.name),
	character_type(c.character_type),
	coin(c.coin),
	pos(c.pos),
	lastPos(c.lastPos),
	moved(c.moved),
	food(c.food),
	food_capacity(c.food_capacity),
	essentialAttribute(c.essentialAttribute),
	level(c.level),
	exp(c.exp),
	levelUpExp(c.levelUpExp),
	strengthGen(c.strengthGen),
	agilityGen(c.agilityGen),
	wisdomGen(c.wisdomGen)
{
	gadgets.resize(max_gadget_index);
};

Character::Character(std::string path)
{
	FILE* fp;
	char buffer[1024];
	if ((fp = fopen(path.c_str(), "r")) == nullptr)
	{
		std::cout << "path " << path << "doesn't exist.\n";
		exit(0);
	}
	fscanf(fp, "character type: %d\n", &character_type);
	fscanf(fp, "name: %s\n", buffer);
	name = buffer;
	fscanf(fp, "pos: %d %d %d\n", &pos.stage, &pos.x, &pos.y);
	fscanf(fp, "lastPos: %d %d %d\n", &lastPos.stage, &lastPos.x, &lastPos.y);
	fscanf(fp, "coin: %d\n", &coin);
	fscanf(fp, "food capacity: %d\n", &food_capacity);
	fscanf(fp, "food: %d\n", &food);
	fscanf(fp, "essentialAttribute: %d\n", &essentialAttribute);
	fscanf(fp, "level: %d\n", &level);
	fscanf(fp, "exp: %d\n", &exp);
	fscanf(fp, "levelUpExp: %d\n", &levelUpExp);
	fscanf(fp, "strengthGen: %d\n", &strengthGen);
	fscanf(fp, "agilityGen: %d\n", &agilityGen);
	fscanf(fp, "wisdomGen: %d\n", &wisdomGen);
 	fscanf(fp, "attribute:\n");
	fscanf(fp, "strength: %d\n", &attr.strength);
	fscanf(fp, "agility: %d\n", &attr.agility);
	fscanf(fp, "wisdom: %d\n", &attr.wisdom);
	fscanf(fp, "maxHealth: %d\n", &attr.maxHealth);
	fscanf(fp, "health: %d\n", &attr.health);
	fscanf(fp, "speed: %d\n", &attr.speed);
	fscanf(fp, "attack: %d\n", &attr.attack);
	fscanf(fp, "diceNum: %d\n", &attr.diceNum);
	fscanf(fp, "facet: %d\n", &attr.facet);
	fscanf(fp, "defense: %d\n", &attr.defense);
	fscanf(fp, "block: %d\n", &attr.block);
	fscanf(fp, "visibleRadius: %d\n", &attr.visibleRadius);
	fscanf(fp, "criticalAttackRate: %f\n", &attr.criticalAttackRate);
	fscanf(fp, "hitRate: %f\n", &attr.hitRate);
	fscanf(fp, "missRate: %f\n", &attr.missRate);
	fscanf(fp, "teleport: %d\n", &attr.teleport);

	int max_gadget_index = 0;
	fscanf(fp, "gadgets: %d\n", &max_gadget_index);
	gadgets.resize(max_gadget_index);
	for (int i = 0; i < max_gadget_index; ++i) fscanf(fp, " %d", &gadgets[i]);
	std::cout << "DEBUG2\n";
	fclose(fp);
}

void Character::take_gadget(const Gadget* g, int num)
{
	Attr attr = g->get_gadget();

	if (this->gadgets[g->get_gadgetIndex()] > 0 && g->get_stackable() == false)
		attr = Attr();
	else if (g->get_stackable() == true)
		attr = num * attr;
	
	this->modify_attr(num * attr);
	this->gadgets[g->get_gadgetIndex()] += num;
	if (this->get_type() == PLAYER) gadgetVisited[g->get_gadgetIndex()] = 1;

	if (num > 0 && this->get_type() == PLAYER)
	{
		std::cout << "Get " << num << " gadget " << g->get_name() << "\n";
		//std::cout << this->health << " " << this->attack << " " << this->defense << "\n";
	}
}

void Character::lose_gadget(const Gadget* g, int num)
{
	Attr attr = g->lose_gadget();
	if (num < 0) return;
	int ind = g->get_gadgetIndex();
	if (this->gadgets[ind] < num) num = this->gadgets[ind];
	if (g->get_stackable() == true)
		attr = attr * num;
	else if (g->get_stackable() == false && this->gadgets[ind] > num)
		attr = Attr();

	this->modify_attr(attr);
	this->gadgets[g->get_gadgetIndex()] -= num;
}

void Character::use_gadget()
{
	if (!gadgetList[gadgetInHand]->get_useful())
	{
		std::cout << gadgetList[gadgetInHand]->get_name() << "无法使用\n";
		return;
	}
	if (gadgets[gadgetInHand] <= 0)
	{
		std::cout << gadgetList[gadgetInHand]->get_name() << "数量不足\n";
		return;
	}
	gadgets[gadgetInHand]--;
	this->modify_attr(gadgetList[gadgetInHand]->lose_gadget());
	this->modify_attr(gadgetList[gadgetInHand]->use_gadget());
}

void Character::moveTo(const Position& somewhere)
{
	lastPos = pos;
	pos = somewhere;
}

void Character::move(direction dir)
{
	lastPos = pos;
	switch (dir)
	{
	case UP: pos = pos + Position(0, 0, -1); break;
	case DOWN: pos = pos + Position(0, 0, 1); break;
	case LEFT: pos = pos + Position(0, -1, 0); break;
	case RIGHT: pos = pos + Position(0, 1, 0); break;
	}
	if (pos.stage)
	{
		food -= pos.stage;
		std::cout << "food: " << food << '\n';
	}
}

void Character::saveCharacter(std::string path)
{
	FILE* fp;
	if ((fp = fopen(path.c_str(), "w")) != nullptr)
	{
		fprintf(fp, "character type: %d\n", this->get_type());
		fprintf(fp, "name: %s\n", this->get_name().c_str());
		fprintf(fp, "pos: %d %d %d\n", pos.stage, pos.x, pos.y);
		fprintf(fp, "lastPos: %d %d %d\n", lastPos.stage, lastPos.x, lastPos.y);
		fprintf(fp, "coin: %d\n", coin);
		fprintf(fp, "food capacity: %d\n", food_capacity);
		fprintf(fp, "food: %d\n", food);
		fprintf(fp, "essentialAttribute: %d\n", essentialAttribute);
		fprintf(fp, "level: %d\n", level);
		fprintf(fp, "exp: %d\n", exp);
		fprintf(fp, "levelUpExp: %d\n", levelUpExp);
		fprintf(fp, "strengthGen: %d\n", strengthGen);
		fprintf(fp, "agilityGen: %d\n", agilityGen);
		fprintf(fp, "wisdomGen: %d\n", wisdomGen);
		fprintf(fp, "attribute:\n");
		fprintf(fp, "strength: %d\n", attr.strength);
		fprintf(fp, "agility: %d\n", attr.agility);
		fprintf(fp, "wisdom: %d\n", attr.wisdom);
		fprintf(fp, "maxHealth: %d\n", attr.maxHealth);
		fprintf(fp, "health: %d\n", attr.health);
		fprintf(fp, "speed: %d\n", attr.speed);
		fprintf(fp, "attack: %d\n", attr.attack);
		fprintf(fp, "diceNum: %d\n", attr.diceNum);
		fprintf(fp, "facet: %d\n", attr.facet);
		fprintf(fp, "defense: %d\n", attr.defense);
		fprintf(fp, "block: %d\n", attr.block);
		fprintf(fp, "visibleRadius: %d\n", attr.visibleRadius);
		fprintf(fp, "criticalAttackRate: %f\n", attr.criticalAttackRate);
		fprintf(fp, "hitRate: %f\n", attr.hitRate);
		fprintf(fp, "missRate: %f\n", attr.missRate);
		fprintf(fp, "teleport: %d\n", attr.teleport);

		fprintf(fp, "gadgets: %d\n", max_gadget_index);
		for (int i = 0; i < max_gadget_index; ++i) fprintf(fp, " %d", gadgets[i]);
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void Character::levelUp()
{
	if (character_type != PLAYER) return;
	static Attr attrGen;
	static int maxLevel = 20;
	attrGen.strength = strengthGen;
	attrGen.agility = agilityGen;
	attrGen.wisdom = wisdomGen;
	while (exp >= levelUpExp && level < maxLevel)
	{
		exp = exp - levelUpExp;
		level++;
		levelUpExp = (int)(25 * level + 75);
		attr = attr + attrGen;
		set_health(calc_maxHealth());
	}
}

int calc_damage(int attack, int defense, int block)
{
	return max((int)(1.0f * attack / (defense + 100) * 100) - block, 1);
}