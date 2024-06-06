#pragma once
#include "rect.h"
#include <string>
#include "../roles/characters.h"

enum buttonType
{
	BUTTON_UNDEFINED,
	BUTTON_QUIT,
	BUTTON_TRADE,
	BUTTON_FOOD
};

struct Button
{
	Button();

	static void quitButton();
	void tradeButton(Character** player);
	static void foodButton(Character** player);

	bool isQuit() const;
	bool isTrade() const;
	bool isFood() const;

	buttonType getType() const;
	std::string getDescription() const;

	void onClick(ExMessage& msg, Character** player);
	bool checkCondition(Character* player);


	Rect pos;
	buttonType type;
	std::string description;
	static int isShown;


	int coinCost;
	int healthCost;
	int minStrength;
	int minAgility;

	Attr attrGain;
};
