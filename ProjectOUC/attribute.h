#pragma once

struct Attr
{
	Attr();

	Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
<<<<<<< HEAD
		int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
=======
		int _health, int _attack, int _diceNum, int _facet, int _defense, 
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
		int visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport);

	Attr(const Attr& other);

	Attr& operator=(const Attr& other);
	Attr operator+(const Attr& other);
	Attr operator-(const Attr& other);
<<<<<<< HEAD
	// ���ظ��������
	Attr operator-() const;
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();
	
	
	int attackFirstLevel;

	// ���������ݡ��ǻ�
=======
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();

	int attackFirstLevel;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	int strength;
	int agility;
	int wisdom;

<<<<<<< HEAD
	// �������ֵ����ǰ����ֵ
	int maxHealth;
	int health;

	// ����������������������������������ֵ��
=======
	int maxHealth;
	int health;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	int attack;
	int diceNum;
	int facet;
	int defense;
<<<<<<< HEAD
	int block;

	// �ɼ��뾶
	int visibleRadius;

	// ������
=======

	int visibleRadius;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	float criticalAttackRate;
	float hitRate;
	float missRate;

<<<<<<< HEAD
	bool teleport; // �Ƿ��ܹ�����

	// ��������
	int capacity;
	// װ���;ö�
	int durability;
=======
	bool teleport;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
};
