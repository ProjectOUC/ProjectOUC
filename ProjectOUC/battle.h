#pragma once
#include "character.h"
#include "chest.h"
#include "player.h"
#include "monster.h"
#include "scene.h"
#include "utils.h"

#pragma execution_character_set("utf-8")

class Battle
{
public:
	Battle(Character* _attacker, Character* _defenser);

	bool battle();
	bool battleStep();
	bool attack(int player);
	void winnerGetGadgets(Character* winner, Character* loser);
	~Battle() {};
private:
	int turn;
	Character* attacker, *defenser;
};

