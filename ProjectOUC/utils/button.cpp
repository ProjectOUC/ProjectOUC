#include "button.h"

int Button::isShown = 0;

Button::Button()
{
	type = BUTTON_UNDEFINED;
	coinCost = healthCost = minStrength = minStrength = minAgility = 0;
}

void Button::quitButton()
{
	isShown = 0;
}

void Button::tradeButton(Character** player)
{
	Character* p = *player;
	if (checkCondition(p))
	{
		p->modify_coin(coinCost);
		p->modify_health(healthCost);
		p->modify_attr(attrGain);
		Button::isShown = 0;
	}
}

void Button::foodButton(Character** player)
{
	Character* p = *player;
	int num = p->calc_food_capacity() - p->get_food();
	if (num > p->get_coin() / 3) num = p->get_coin() / 3;
	p->modify_coin(num * 3);
	p->modify_food(num);
	Button::isShown = 0;
}

bool Button::isQuit() const
{
	return type == BUTTON_QUIT;
}

bool Button::isTrade() const
{
	return type == BUTTON_TRADE;
}

bool Button::isFood() const
{
	return type == BUTTON_FOOD;
}

buttonType Button::getType() const
{
	return type;
}

std::string Button::getDescription() const
{
	return this->description;
}

void Button::onClick(ExMessage& msg, Character** player)
{
	int x = msg.x, y = msg.y;
	if (pos.include(x, y))
	{
		switch (type)
		{
		case BUTTON_QUIT: quitButton(); break;
		case BUTTON_TRADE: 
		{
			tradeButton(player);
			break;
		}
		case BUTTON_FOOD:
		{
			foodButton(player);
			break;
		}
		default: break;
		}
	}
}

bool Button::checkCondition(Character* player)
{
	if (player->get_coin() < coinCost) return false;
	if (player->get_health() < healthCost) return false;
	if (player->get_strength() < minStrength) return false;
	if (player->get_agility() < minAgility) return false;
}