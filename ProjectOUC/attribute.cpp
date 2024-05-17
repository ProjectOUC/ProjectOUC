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

	teleport = false;
}

Attr::Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
	int _health, int _attack, int _defense, int _visibleRadius, float _criticalAttackRate,
	float _missRate, bool _teleport)
{
	this->attackFirstLevel = _attackFirstLevel;
	this->strength = _strength;
	this->agility = _agility;
	this->wisdom = _wisdom;
	this->maxHealth = _maxHealth;
	this->health = _health;
	this->attack = _attack;
	this->defense = _defense;
	this->visibleRadius = _visibleRadius;
	this->criticalAttackRate = _criticalAttackRate;
	this->missRate = _missRate;
	this->teleport = _teleport;
}

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
	this->teleport = other.teleport;
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
	this->teleport = other.teleport;

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
		this->missRate + other.missRate,
		this->teleport + other.teleport
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
		this->missRate - other.missRate,
		this->teleport 
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
		mul * this->missRate,
		this->teleport
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
		mul * other.missRate,
		other.teleport
	);
}