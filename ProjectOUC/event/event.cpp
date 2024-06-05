#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>

Event::Event()
{
	type = EVENT_UNDEFINED;
	buttonCount = 0;
}

Event::Event(std::string path)
{
	

	FILE* fp;
	if ((fp = fopen(path.c_str(), "r")) == nullptr)
	{
		std::cerr << "Event path " << path << " doesn't exist\n";
		exit(0);
	}

	char buffer[1024];
	fscanf(fp, "%s\n", buffer);
	if (strncmp(buffer, "EVENT_NPC", 9) == 0)
	{
		type = EVENT_NPC;
	}
	else if (strncmp(buffer, "EVENT_TRAP", 10) == 0)
	{
		type = EVENT_TRAP;
	}
	else
	{
		std::cerr << "Event type " << buffer << " doesn't exist\n";
		exit(0);
	}

	fscanf(fp, "%s\n", eventName);
	fscanf(fp, "%s\n", eventDescription);
	/***** 
	* 
	* 
	Todo: �޸�����ĺ�������ȡͼƬ
	*
	*
	*****/
	std::string img_path;
	fscanf(fp, "%s\n", img_path);
	loadimage(&img, img_path.c_str());

	fscanf(fp, "%d\n", &buttonCount);
	buttons.resize(buttonCount);

	for (int i = 0; i < buttonCount; ++i)
	{
		buttons[i] = new Button;
		int _;
		fscanf(fp, "Button%d:\n", &_);
		fscanf(fp, "%s\n", buffer);
		if (strncmp(buffer, "BUTTON_QUIT", 11) == 0)
			buttons[i]->type = BUTTON_QUIT;
		else if (strncmp(buffer, "BUTTON_TRADE", 12) == 0)
			buttons[i]->type = BUTTON_TRADE;
		else if (strncmp(buffer, "BUTTON_FOOD", 11) == 0)
			buttons[i]->type = BUTTON_FOOD;
		fscanf(fp, "Description:%s\n", &buttons[i]->description);

		if (buttons[i]->type == BUTTON_TRADE)
		{
			fscanf(fp, "coinCost:%d\n", &buttons[i]->coinCost);
			fscanf(fp, "healthCost:%d\n", &buttons[i]->healthCost);
			fscanf(fp, "minStrength:%d\n", &buttons[i]->minStrength);
			fscanf(fp, "minAgility:%d\n", &buttons[i]->minAgility);
		
			fscanf(fp, "attrGain:\n");
			fscanf(fp, "speed:%d\n", &buttons[i]->attrGain.speed);
			fscanf(fp, "strength:%d\n", &buttons[i]->attrGain.strength);
			fscanf(fp, "agility:%d\n", &buttons[i]->attrGain.agility);
			fscanf(fp, "wisdom:%d\n", &buttons[i]->attrGain.wisdom);
			fscanf(fp, "maxHealth:%d\n", &buttons[i]->attrGain.maxHealth);
			fscanf(fp, "health:%d\n", &buttons[i]->attrGain.health);
			fscanf(fp, "attack:%d\n", &buttons[i]->attrGain.attack);
			fscanf(fp, "diceNum:%d\n", &buttons[i]->attrGain.diceNum);
			fscanf(fp, "facet:%d\n", &buttons[i]->attrGain.facet);
			fscanf(fp, "defense:%d\n", &buttons[i]->attrGain.defense);
			fscanf(fp, "block:%d\n", &buttons[i]->attrGain.block);
			fscanf(fp, "visibleRadius:%d\n", &buttons[i]->attrGain.visibleRadius);

			fscanf(fp, "criticalAttackRate:%f\n", &buttons[i]->attrGain.criticalAttackRate);
			fscanf(fp, "hitRate:%f\n", &buttons[i]->attrGain.hitRate);
			fscanf(fp, "missRate:%f\n", &buttons[i]->attrGain.missRate);

			fscanf(fp, "teleport:%d\n", &buttons[i]->attrGain.teleport);
		}
	}
}


bool Event::isNPC() const
{
	return type == EVENT_NPC;
}

bool Event::isTrap() const
{
	return type == EVENT_TRAP;
}

eventType Event::getType() const
{
	return type;
}

int Event::getEventCount() const
{
	return buttonCount;
}

void Event::setType(const eventType& _type)
{
	type = _type;
}

void Event::setButtonCount(const int& _buttonCount)
{
	buttonCount = _buttonCount;
}

void Event::occurEvent(Character** player)
{

	/*
		����ὫButton::isShown��Ϊ1��Ȼ�󲻶ϻ���Event�е�button
	���ж��Ƿ���button�����
		��֤��һ��button���Ե�����˳�����ὫButton::isShown��Ϊ0
	Todo:
	1. Ԥ����Event��button��layout������buttonCountֱ��ȷ��layout
	2. ����Event��buttons��Description��Name
	3. ��scene�л���Event
		���ｫEvent��IMG���ڶ����У���ȡʱֱ��ͨ���ļ��е�path��ȡ
	*/
	ExMessage msg;
	Button::isShown = 1;
	while (Button::isShown)
	{
		//
		
		for (Button* btn : buttons)
			btn->onClick(msg, player);

		cleardevice();
	}
}

Event::~Event()
{
	for (int i = 0; i < buttonCount; ++i) delete buttons[i];
}