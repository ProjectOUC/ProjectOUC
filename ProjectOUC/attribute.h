#pragma once

struct Attr
{
	Attr();

	Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
		int _health, int _attack, int _defense, int visibleRadius, float _criticalAttackRate,
		float _missRate, bool _teleport);

	Attr(const Attr& other);

	Attr& operator=(const Attr& other);
	Attr operator+(const Attr& other);
	Attr operator-(const Attr& other);
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);

	int attackFirstLevel;

	int strength;
	int agility;
	int wisdom;

	int maxHealth;
	int health;

	int attack;
	int defense;

	int visibleRadius;

	float criticalAttackRate;
	float missRate;

	bool teleport;
};
