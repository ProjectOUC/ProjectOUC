#pragma once

struct Attr
{
	Attr();

	Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
		int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
		int visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport);

	Attr(const Attr& other);

	Attr& operator=(const Attr& other);
	Attr operator+(const Attr& other);
	Attr operator-(const Attr& other);
	// 重载负号运算符
	Attr operator-() const;
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();
	
	
	int attackFirstLevel;

	// 力量、敏捷、智慧
	int strength;
	int agility;
	int wisdom;

	// 最大生命值、当前生命值
	int maxHealth;
	int health;

	// 攻击力、骰子数量、面数、防御力、格挡值、
	int attack;
	int diceNum;
	int facet;
	int defense;
	int block;

	// 可见半径
	int visibleRadius;

	// 暴击率
	float criticalAttackRate;
	float hitRate;
	float missRate;

	bool teleport; // 是否能够传送

	// 背包容量
	int capacity;
	// 装备耐久度
	int durability;
};
