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
	diceNum = 0;
	facet = 0;
	defense = 0;
<<<<<<< HEAD
	block = 0;
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d

	visibleRadius = 0;

	criticalAttackRate = 0;
	hitRate = 0;
	missRate = 0;

	teleport = false;
}

Attr::Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
<<<<<<< HEAD
	int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
=======
	int _health, int _attack, int _diceNum, int _facet, int _defense,
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	int _visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport)
{
	this->attackFirstLevel = _attackFirstLevel;
	this->strength = _strength;
	this->agility = _agility;
	this->wisdom = _wisdom;
	this->maxHealth = _maxHealth;
	this->health = _health;
	this->attack = _attack;
	this->diceNum = _diceNum;
	this->facet = _facet;
	this->defense = _defense;
<<<<<<< HEAD
	this->block = _block;
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	this->visibleRadius = _visibleRadius;
	this->criticalAttackRate = _criticalAttackRate;
	this->hitRate = _hitRate;
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
	this->diceNum = other.diceNum;
	this->facet = other.facet;
	this->defense = other.defense;
<<<<<<< HEAD
	this->block = other.block;
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->hitRate = other.hitRate;
	this->missRate = other.missRate;
	this->teleport = other.teleport;
}

Attr& Attr::operator=(const Attr& other)
<<<<<<< HEAD
{	
	Attr attr(other);
	return attr;
=======
{
	this->attackFirstLevel = other.attackFirstLevel;
	this->strength = other.strength;
	this->agility = other.agility;
	this->wisdom = other.wisdom;
	this->maxHealth = other.maxHealth;
	this->health = other.health;
	this->attack = other.attack;
	this->diceNum = other.diceNum;
	this->facet = other.facet;
	this->defense = other.defense;
	this->visibleRadius = other.visibleRadius;
	this->criticalAttackRate = other.criticalAttackRate;
	this->hitRate = other.hitRate;
	this->missRate = other.missRate;
	this->teleport = other.teleport;

	return *this;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
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
		this->diceNum + other.diceNum,
		this->facet + other.facet,
		this->defense + other.defense,
<<<<<<< HEAD
		this->block + other.block,
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
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
		this->attackFirstLevel - other.attackFirstLevel,
		this->strength - other.strength,
		this->agility - other.agility,
		this->wisdom - other.wisdom,
		this->maxHealth - other.maxHealth,
		this->health - other.health,
		this->attack - other.attack,
		this->diceNum - other.diceNum,		
		this->facet - other.facet,
		this->defense - other.defense,
<<<<<<< HEAD
		this->block - other.block,
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
		this->visibleRadius - other.visibleRadius,
		this->criticalAttackRate - other.criticalAttackRate,
		this->hitRate - other.hitRate,
		this->missRate - other.missRate,
		this->teleport 
	);
	if (attr.health > attr.get_maxHealth()) attr.health = attr.get_maxHealth();
	return attr;
}

<<<<<<< HEAD
// ÖØÔØ¸ººÅÔËËã·û
Attr  Attr::operator-() const {
	return Attr(
		-this->attackFirstLevel,
		-this->strength,
		-this->agility,
		-this->wisdom,
		-this->maxHealth,
		-this->health,
		-this->attack,
		-this->diceNum,
		-this->facet,
		-this->defense,
		-this->block,
		-this->visibleRadius,
		-this->criticalAttackRate,
		-this->hitRate,
		-this->missRate,
		this->teleport
	);
}


=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
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
		mul * this->diceNum,
		mul * this->facet,
		mul * this->defense,
<<<<<<< HEAD
		mul * this->block,
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
		mul * this->visibleRadius,
		mul * this->criticalAttackRate,
		mul * this->hitRate,
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
		mul * other.diceNum,
		mul * other.facet,
		mul * other.defense,
<<<<<<< HEAD
		mul * other.block,
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
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