#pragma once

struct Attr
{
	Attr();

	Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
		int _health, int _attack, int _diceNum, int _facet, int _defense, 
		int visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport);

	Attr(const Attr& other);

	Attr& operator=(const Attr& other);
	Attr operator+(const Attr& other);
	Attr operator-(const Attr& other);
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();

	int attackFirstLevel;

	int strength;
	int agility;
	int wisdom;

	int maxHealth;
	int health;

	int attack;
	int diceNum;
	int facet;
	int defense;

	int visibleRadius;

	float criticalAttackRate;
	float hitRate;
	float missRate;

	bool teleport;
};