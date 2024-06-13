#include "button.h"

extern const int max_gadget_index;
int Button::isShown = 0;

Button::Button()
{
	type = BUTTON_UNDEFINED;
	gainCoin = gainFood = gainFoodCapacity = gainExp = 0;
	minCoin = minFood = minFoodCapacity = minLevel = -9999;
	minAttr = Attr(-9999);
	monster = NULL;
	gadgetsGain.resize(max_gadget_index, 0);
	minGadgets.resize(max_gadget_index, -9999);
}

void Button::quitButton()
{
	isShown = 0;
}

void Button::tradeButton(Character** player)
{
	Character* p = *player;
	std::cout << gadgetsGain[findGadget("key")];
	if (checkCondition(p))
	{
		p->modify_coin(gainCoin);
		p->modify_food(gainFood);
		p->modify_exp(gainExp);
		p->modify_food_capacity(gainFoodCapacity);
		p->modify_attr(gainAttr);
		for (int i = 0; i < max_gadget_index; ++i)
		{
			if (gadgetsGain[i] > 0) p->take_gadget(gadgetList[i], gadgetsGain[i]);
			else if (gadgetsGain[i] < 0) p->lose_gadget(gadgetList[i], -gadgetsGain[i]);
		}
		Button::isShown = 0;
	}
}

void Button::foodButton(Character** player)
{
	Character* p = *player;
	int num = p->calc_food_capacity() - p->get_food();
	if (num > p->get_coin() / 3) num = p->get_coin() / 3;
	p->modify_coin(-num * 3);
	p->modify_food(num);
	Button::isShown = 0;
}

void Button::battleButton(Character** player)
{
	//Todo
	Battle battle((Character*)(*player), (Character*)monster);
	battle.battle();
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

bool Button::isBattle() const
{
	return type == BUTTON_BATTLE;
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
		case BUTTON_BATTLE:
		{
			battleButton(player);
			break;
		}
		default: break;
		}
	}
}

bool Button::checkCondition(Character* player)
{
	if (player->get_coin() < minCoin) return false;
	if (player->get_food() < minFood) return false;
	if (player->get_food_capacity() < minFoodCapacity) return false;
	if (player->get_level() < minLevel) return false;
	Attr attr = player->get_attr();
	attr.maxHealth = player->calc_maxHealth();
	if (attr < minAttr) return false;
	if (gainCoin < 0 && player->get_coin() < -gainCoin) return false;
	if (gainFood < 0 && player->get_food() < -gainFood) return false;
	if (gainFoodCapacity < 0 && player->calc_food_capacity() < -gainFoodCapacity) return false;
	if (gainExp < 0 && player->get_exp() < -gainExp) return false;
	if (gainAttr.agility < 0 && player->get_agility() < -gainAttr.agility) return false;
	if (gainAttr.attack < 0 && player->get_attack() < -gainAttr.attack) return false;
	if (gainAttr.block < 0 && player->get_block() < -gainAttr.block) return false;
	if (gainAttr.criticalAttackRate < 0 && player->get_criticalAttackRate() < -gainAttr.criticalAttackRate) return false;
	if (gainAttr.defense < 0 && player->get_defense() < -gainAttr.defense) return false;
	if (gainAttr.diceNum < 0 && player->get_attr().diceNum < -gainAttr.diceNum) return false;
	if (gainAttr.facet < 0 && player->get_attr().facet < -gainAttr.facet) return false;
	if (gainAttr.health < 0 && player->get_health() < -gainAttr.health) return false;
	if (gainAttr.hitRate < 0 && player->get_hitRate() < -gainAttr.hitRate) return false;
	if (gainAttr.maxHealth < 0 && player->calc_maxHealth() < -gainAttr.maxHealth) return false;
	if (gainAttr.missRate < 0 && player->get_missRate() < -gainAttr.missRate) return false;
	if (gainAttr.speed < 0 && player->get_speed() < -gainAttr.speed) return false;
	if (gainAttr.strength < 0 && player->get_strength() < -gainAttr.strength) return false;
	if (gainAttr.visibleRadius < 0 && player->get_visibleRadius() < -gainAttr.visibleRadius) return false;
	if (gainAttr.wisdom < 0 && player->get_wisdom() < -gainAttr.wisdom) return false;
	for (int i = 0; i < max_gadget_index; ++i)
	{
		if (player->gadgets[i] < minGadgets[i]) return false;
		if (gadgetsGain[i] < 0 && player->gadgets[i] < -gadgetsGain[i]) return false;
	}
	
	return true;
}

Button::~Button()
{
	if (monster) delete monster;
}