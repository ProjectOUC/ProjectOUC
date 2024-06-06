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
	// ���ظ��������
	Attr operator-() const;
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();
	
	
	int attackFirstLevel;

	// ���������ݡ��ǻ�
	int strength;
	int agility;
	int wisdom;

	// �������ֵ����ǰ����ֵ
	int maxHealth;
	int health;

	// ����������������������������������ֵ��
	int attack;
	int diceNum;
	int facet;
	int defense;
	int block;

	// �ɼ��뾶
	int visibleRadius;

	// ������
	float criticalAttackRate;
	float hitRate;
	float missRate;

	bool teleport; // �Ƿ��ܹ�����

	// ��������
	int capacity;
	// װ���;ö�
	int durability;
};