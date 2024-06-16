#pragma once
#include "rect.h"
#include "../roles/characters.h"
#include "../gadgets/gadgets.h"
#include "../battle.h"

enum buttonType
{
	BUTTON_UNDEFINED,
	BUTTON_QUIT,
	BUTTON_TRADE,
	BUTTON_FOOD,
	BUTTON_BATTLE
};


struct Button
{
	Button();

	static int quitButton();
	int tradeButton(Character** player);
	static int foodButton(Character** player);
	int battleButton(Character** player);

	bool isQuit() const;
	bool isTrade() const;
	bool isFood() const;
	bool isBattle() const;

	buttonType getType() const;
	std::string getDescription() const;

	int onClick(int x, int y, Character** player);
	bool checkCondition(Character* player);


	Rect pos;
	buttonType type;
	std::string description;
	static int isShown;

	Monster* monster;

	int gainCoin;
	int gainFood;
	int gainFoodCapacity;
	int gainExp;
	Attr gainAttr;
	std::vector<int> gadgetsGain;

	int minCoin;
	int minFood;
	int minFoodCapacity;
	int minLevel;
	Attr minAttr;
	std::vector<int> minGadgets;

	~Button();
};
