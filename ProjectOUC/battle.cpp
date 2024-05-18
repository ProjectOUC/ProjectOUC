#include "battle.h"
#include <iostream>

extern const int MAX_BATTLE_TURN = 1000;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;

Battle::Battle(Character* _attacker, Character* _defenser)
{
	tA = tB = spA = spB = 0;
	attacker = _attacker;
	defenser = _defenser;
	if (_attacker->get_attr().attackFirstLevel < _defenser->get_attr().attackFirstLevel)
	{
		attacker = _defenser;
		defenser = _attacker;
	}
	turn = 0;
}

void Battle::winnerGetGadgets(Character* winner, Character* loser)
{
	for (int i = 0; i < max_gadget_index; ++i)
	{
		winner->take_gadget(gadgetList[i], loser->gadgets[i]);
	}
	winner->modify_coin(loser->get_coin());
	if (loser->get_coin()) std::cout << "�����" << loser->get_coin() << "��ͭ��\n";
	winner->modify_food(loser->get_food());
	if (loser->get_food()) std::cout << "�����" << loser->get_food() << "��ʳ��\n";
}

void Battle::useAllGadgets(Character* owner, Character* enemy, int cond)
{
	/*
	cond:
		1: ս����ʼ
		2: ս������
		3: ս����
	*/
	for (int i = 0; i < max_gadget_index; ++i)
	{
		if (owner->gadgets[i] == 0) continue;
		switch (cond)
		{
		case 1:gadgetList[i]->before_battle(owner, enemy, owner->gadgets[i]); break;
		case 2:gadgetList[i]->after_battle(owner, enemy, owner->gadgets[i]); break;
		case 3:gadgetList[i]->during_battle(owner, enemy, owner->gadgets[i]); break;
		}
	}
}


int Battle::checkEnd(Character* c1, Character* c2)
{
	/*
	return:
		0: ��Ϸ����
		1: ��ʤ
		2: ��Ϸδ����
	*/
	if (c1->get_type() == PLAYER && c1->dead()) return 0;
	if (c2->get_type() == PLAYER && c2->dead()) return 0;
	if (c1->get_type() != PLAYER && c1->dead())
	{
		useAllGadgets(c2, c1, 2);
		winnerGetGadgets(c2, c1);
		return 1;
	}
	if (c2->get_type() != PLAYER && c2->dead())
	{
		useAllGadgets(c1, c2, 2);
		winnerGetGadgets(c1, c2);
		return 1;
	}
	return 2;
}

bool Battle::battle()
{
	/* Todo
	* while(!battleStep());
	*
	* if player dead:
	*     return false;
	* winner takes loser's gadgets
	* return true;
	*/
	useAllGadgets(attacker, defenser, 1);
	int ending = checkEnd(attacker, defenser);
	if (ending == 0) return false;
	else if (ending == 1) return true;

	useAllGadgets(defenser, attacker, 1);
	ending = checkEnd(defenser, attacker);
	if (ending == 0) return false;
	else if (ending == 1) return true;

	spA = 0;
	spB = 0;
	while (!battleStep())
	{
		if (turn >= MAX_BATTLE_TURN)
		{
			return false;
		}
	}

	ending = checkEnd(attacker, defenser);
	if (ending == 0) return false;
	else if (ending == 1) return true;
	return false;
}

bool Battle::battleStep()
{
	//std::cout << defenser->get_health() << " " << attacker->get_health() << "\n";
	// �غϿ�ʼ����
	// �ж����ȵ���attackInterval���ж�
	int afl1 = attacker->get_attr().attackFirstLevel, afl2 = defenser->get_attr().attackFirstLevel;
	if (afl1 <= 0) afl1 = 1;
	if (afl2 <= 0) afl2 = 1;
	int t = min((attackInterval - spA + afl1 - 1) / afl1, (attackInterval - spB + afl2 - 1) / afl2);
	spA = spA + afl1 * t; spB = spB + afl2 * t;
	if (spA > spB)
	{
		if (spA >= attackInterval)
		{
			tA++;
			if (attack(0)) return true;
		}
		if (spB >= attackInterval)
		{
			tB++;
			if (attack(1)) return true;
		}
	}
	else
	{
		if (spB >= attackInterval)
		{
			tB++;
			if (attack(1)) return true;
		}
		if (spA >= attackInterval)
		{
			tA++;
			if (attack(0)) return true;
		}
	}
	spA = spA % attackInterval;
	spB = spB % attackInterval;

	// �غϽ�������
	
	return false;
}

bool Battle::attack(int player)
{
	Character* c1, *c2;
	if (player == 0)
	{
		c1 = attacker;
		c2 = defenser;
	}
	else
	{
		c1 = defenser;
		c2 = attacker;
	}

	int damage = 0;
	bool miss = false;
	bool critical = 0;
	int attack = c1->calc_attack();
	int defense = c2->get_defense();

	if (random(0, 10000) < (int)(100 * c1->get_attr().criticalAttackRate)) critical = true;
	if (random(0, 10000) < (int)(100 * c2->get_attr().missRate)) miss = true;

	if (critical) attack = attack * 2;
	damage = attack - defense;
	damage = max(damage, 0);
	if (miss) damage = 0;

	if (miss) std::cout << c2->get_name() << "������" << c1->get_name() << "�Ĺ���\n\n";
	else if (critical) std::cout << c1->get_name() << "����˱���\n";
	c2->modify_health(-damage);
	if (!miss) std::cout << c1->get_name() << "��" << c2->get_name() << "���" << damage << "���˺�\n\n";


	if (c1->dead() || c2->dead()) return true;
	return false;
}