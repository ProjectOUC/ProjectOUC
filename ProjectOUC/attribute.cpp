#include "attribute.h"

Attr::Attr()
{
	attackFirstLevel = 0;

	strength = 0;
	agility = 0;
	wisdom = 0;

	maxHealth = 0;
	health = 0;
	attack = 0;
	defense = 0;

	visibleRadius = 0;

	criticalAttackRate = 0;
	missRate = 0;
}

Attr::Attr(int _attackFirstLevel=0, int _strength=0, int _agility=0, int _wisdom=0, int _maxHealth=0,
	int _health=0, int _attack=0, int _defense=0, int _visibleRadius = 0, float _criticalAttackRate=0,
	float _missRate=0):
	attackFirstLevel(_attackFirstLevel),
	strength(_strength),
	agility(_agility),
	wisdom(_wisdom),
	maxHealth(_maxHealth),
	health(_health),
	attack(_attack),
	defense(_defense),
	visibleRadius(_visibleRadius),
	criticalAttackRate(_criticalAttackRate),
	missRate(_missRate)
{}


Attr::Attr(const Attr& other)
{
	this->attackFirstLevel = other.attackFirstLevel;
	this->strength = other.strength;
	this->agility = other.agility;
	this->wisdom = other.wisdom;
	this->maxHealth = other.maxHealth;
	this->health = other.health;
	this->attack = other.attack;
	this->defense = other.defense;
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->missRate = other.missRate;
}

Attr& Attr::operator=(const Attr& other)
{
	this->attackFirstLevel = other.attackFirstLevel;
	this->strength = other.strength;
	this->agility = other.agility;
	this->wisdom = other.wisdom;
	this->maxHealth = other.maxHealth;
	this->health = other.health;
	this->attack = other.attack;
	this->defense = other.defense;
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->missRate = other.missRate;

	return *this;
}

Attr Attr::operator+(const Attr& other)
{
	Attr attr(
		this->attackFirstLevel + other.attackFirstLevel,
		this->strength + other.strength,
		this->agility + other.agility,
		this->wisdom + other.wisdom,
		this->maxHealth + other.maxHealth,
		this->health + other.health,
		this->attack + other.attack,
		this->defense + other.defense,
		this->visibleRadius + other.visibleRadius,
		this->criticalAttackRate + other.criticalAttackRate,
		this->missRate + other.missRate
	);
	if (attr.health > attr.maxHealth) attr.health = attr.maxHealth;
	return attr;
}

Attr Attr::operator-(const Attr& other)
{
	Attr attr(
		this->attackFirstLevel - other.attackFirstLevel,
		this->strength - other.strength,
		this->agility - other.agility,
		this->wisdom - other.wisdom,
		this->maxHealth - other.maxHealth,
		this->health - other.health,
		this->attack - other.attack,
		this->defense - other.defense,
		this->visibleRadius - other.visibleRadius,
		this->criticalAttackRate - other.criticalAttackRate,
		this->missRate - other.missRate
	);
	if (attr.health > attr.maxHealth) attr.health = attr.maxHealth;
	return attr;
}

Attr Attr::operator*(const int mul)
{
	return Attr(
		mul * this->attackFirstLevel,
		mul * this->strength,
		mul * this->agility,
		mul * this->wisdom,
		mul * this->maxHealth,
		mul * this->health,
		mul * this->attack,
		mul * this->defense,
		mul * this->visibleRadius,
		mul * this->criticalAttackRate,
		mul * this->missRate
	);
}

Attr operator*(const int mul, const Attr& other)
{
	return Attr(
		mul * other.attackFirstLevel,
		mul * other.strength,
		mul * other.agility,
		mul * other.wisdom,
		mul * other.maxHealth,
		mul * other.health,
		mul * other.attack,
		mul * other.defense,
		mul * other.visibleRadius,
		mul * other.criticalAttackRate,
		mul * other.missRate
	);
}