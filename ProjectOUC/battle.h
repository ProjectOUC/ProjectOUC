#pragma once
#include "character.h"
#include "chest.h"
#include "player.h"
#include "monster.h"
#include "scene.h"

class Battle
{
public:
	Battle(Character* _attacker, Character* _defenser);

	bool battle();
	bool battleStep();
	void winnerGetGadgets(Character* winner, Character* loser);
	~Battle() {};
private:
	int turn;
	Character* attacker, *defenser;
};

