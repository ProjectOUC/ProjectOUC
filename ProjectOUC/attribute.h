#pragma once

struct Attr
{
	Attr();

<<<<<<< HEAD
	Attr(int _attackFirstLevel, int _strength, int _agility, int _wisdom, int _maxHealth,
<<<<<<< HEAD
		int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
=======
		int _health, int _attack, int _diceNum, int _facet, int _defense, 
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	Attr(int _speed, int _strength, int _agility, int _wisdom, int _maxHealth,
		int _health, int _attack, int _diceNum, int _facet, int _defense, int _block,
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
		int visibleRadius, float _criticalAttackRate, float _hitRate, float _missRate, bool _teleport);

	Attr(const Attr& other);

	Attr& operator=(const Attr& other);
	Attr operator+(const Attr& other);
	Attr operator-(const Attr& other);
<<<<<<< HEAD
<<<<<<< HEAD
	// ���ظ��������
	Attr operator-() const;
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();
	
	
	int attackFirstLevel;

	// ���������ݡ��ǻ�
=======
=======
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	Attr operator*(const int mul);
	friend Attr operator*(const int mul, const Attr& other);
	int get_maxHealth();

<<<<<<< HEAD
	int attackFirstLevel;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	int speed;

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	int strength;
	int agility;
	int wisdom;

<<<<<<< HEAD
<<<<<<< HEAD
	// �������ֵ����ǰ����ֵ
	int maxHealth;
	int health;

	// ����������������������������������ֵ��
=======
	int maxHealth;
	int health;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	int maxHealth;
	int health;

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	int attack;
	int diceNum;
	int facet;
	int defense;
<<<<<<< HEAD
<<<<<<< HEAD
	int block;

	// �ɼ��뾶
	int visibleRadius;

	// ������
=======

	int visibleRadius;

>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	int block;

	int visibleRadius;

>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
	float criticalAttackRate;
	float hitRate;
	float missRate;

<<<<<<< HEAD
<<<<<<< HEAD
	bool teleport; // �Ƿ��ܹ�����

	// ��������
	int capacity;
	// װ���;ö�
	int durability;
=======
	bool teleport;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
	bool teleport;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
};
