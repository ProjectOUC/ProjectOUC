#pragma once
#include "roles/character.h"
#include "scene.h"
#include "utils/random.h"

#pragma execution_character_set("utf-8")

class Battle
{
public:
	Battle(Character* _attacker, Character* _defenser);

	bool battle();
	bool battleStep();
	bool attack(int player);
	void winnerGetGadgets(Character* winner, Character* loser);
	int checkEnd(Character* c1, Character* c2);
	void useAllGadgets(Character* onwer, Character* enemy, int cond);
	~Battle() {};
private:
	int turn;
	int spA, spB, tA, tB;
	const static int attackInterval = 10000;
	Character* attacker, *defenser;
};

