#include "attribute.h"


Attr::Attr()
{
	speed = 0;

	strength = 0;
	agility = 0;
	wisdom = 0;

	maxHealth = 0;
	health = 0;
	attack = 0;
	diceNum = 0;
	facet = 0;
	defense = 0;
	block = 0;

	visibleRadius = 0;

	criticalAttackRate = 0;
	hitRate = 0;
	missRate = 0;

	teleport = false;
}

Attr::Attr(int _all)
{
	this->speed = _all;
	this->strength = _all;
	this->agility = _all;
	this->wisdom = _all;
	this->maxHealth = _all;
	this->health = _all;
	this->attack = _all;
	this->diceNum = _all;
	this->facet = _all;
	this->defense = _all;
	this->block = _all;
	this->visibleRadius = _all;
	this->criticalAttackRate = _all;
	this->hitRate = _all;
	this->missRate = _all;
	this->teleport = 0;
}

Attr::Attr(int _speed, int _strength, int _agility, int _wisdom, int _maxHealth,
	int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
	int _visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport)
{
	this->speed = _speed;
	this->strength = _strength;
	this->agility = _agility;
	this->wisdom = _wisdom;
	this->maxHealth = _maxHealth;
	this->health = _health;
	this->attack = _attack;
	this->diceNum = _diceNum;
	this->facet = _facet;
	this->defense = _defense;
	this->block = _block;
	this->visibleRadius = _visibleRadius;
	this->criticalAttackRate = _criticalAttackRate;
	this->hitRate = _hitRate;
	this->missRate = _missRate;
	this->teleport = _teleport;
}

Attr::Attr(const Attr& other)
{
	this->speed = other.speed;
	this->strength = other.strength;
	this->agility = other.agility;
	this->wisdom = other.wisdom;
	this->maxHealth = other.maxHealth;
	this->health = other.health;
	this->attack = other.attack;
	this->diceNum = other.diceNum;
	this->facet = other.facet;
	this->defense = other.defense;
	this->block = other.block;
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->hitRate = other.hitRate;
	this->missRate = other.missRate;
	this->teleport = other.teleport;
}

Attr& Attr::operator=(const Attr& other)
{
	if (this == &other) return *this;
	this->speed = other.speed;

	this->strength = other.strength;
	this->agility = other.agility;
	this->wisdom = other.wisdom;
	this->maxHealth = other.maxHealth;
	this->health = other.health;
	this->attack = other.attack;
	this->diceNum = other.diceNum;
	this->facet = other.facet;
	this->defense = other.defense;
	this->block = other.block;
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->hitRate = other.hitRate;
	this->missRate = other.missRate;
	this->teleport = other.teleport;

	return *this;
}

Attr Attr::operator+(const Attr& other)
{
	Attr attr(
		this->speed + other.speed,
		this->strength + other.strength,
		this->agility + other.agility,
		this->wisdom + other.wisdom,
		this->maxHealth + other.maxHealth,
		this->health + other.health,
		this->attack + other.attack,
		this->diceNum + other.diceNum,
		this->facet + other.facet,
		this->defense + other.defense,
		this->block + other.block,
		this->visibleRadius + other.visibleRadius,
		this->criticalAttackRate + other.criticalAttackRate,
		this->hitRate + other.hitRate,
		this->missRate + other.missRate,
		this->teleport + other.teleport
	);
	if (attr.health > attr.get_maxHealth()) attr.health = attr.get_maxHealth();
	return attr;
}

Attr Attr::operator-(const Attr& other)
{
	Attr attr(
		this->speed - other.speed,
		this->strength - other.strength,
		this->agility - other.agility,
		this->wisdom - other.wisdom,
		this->maxHealth - other.maxHealth,
		this->health - other.health,
		this->attack - other.attack,
		this->diceNum - other.diceNum,		
		this->facet - other.facet,
		this->defense - other.defense,
		this->block - other.block,
		this->visibleRadius - other.visibleRadius,
		this->criticalAttackRate - other.criticalAttackRate,
		this->hitRate - other.hitRate,
		this->missRate - other.missRate,
		this->teleport 
	);
	if (attr.health > attr.get_maxHealth()) attr.health = attr.get_maxHealth();
	return attr;
}

Attr Attr::operator*(const int mul)
{
	return Attr(
		mul * this->speed,
		mul * this->strength,
		mul * this->agility,
		mul * this->wisdom,
		mul * this->maxHealth,
		mul * this->health,
		mul * this->attack,
		mul * this->diceNum,
		mul * this->facet,
		mul * this->defense,
		mul * this->block,
		mul * this->visibleRadius,
		mul * this->criticalAttackRate,
		mul * this->hitRate,
		mul * this->missRate,
		this->teleport
	);
}

bool Attr::operator<(const Attr& other)
{
	return
		this->speed < other.speed ||
		this->agility < other.agility ||
		this->attack < other.attack ||
		this->block < other.block ||
		this->criticalAttackRate < other.criticalAttackRate ||
		this->defense < other.defense ||
		this->diceNum < other.diceNum ||
		this->facet < other.facet ||
		this->get_maxHealth() < other.maxHealth ||
		this->health < other.health ||
		this->hitRate < other.hitRate ||
		this->missRate < other.missRate ||
		this->strength < other.strength ||
		this->visibleRadius < other.visibleRadius ||
		this->wisdom < other.wisdom;
}

Attr operator*(const int mul, const Attr& other)
{
	return Attr(
		mul * other.speed,
		mul * other.strength,
		mul * other.agility,
		mul * other.wisdom,
		mul * other.maxHealth,
		mul * other.health,
		mul * other.attack,
		mul * other.diceNum,
		mul * other.facet,
		mul * other.defense,
		mul * other.block,
		mul * other.visibleRadius,
		mul * other.criticalAttackRate,
		mul * other.hitRate,
		mul * other.missRate,
		other.teleport
	);
}

int Attr::get_maxHealth()
{
	return maxHealth + 10 * strength;
}