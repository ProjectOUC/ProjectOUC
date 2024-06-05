#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <io.h>

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

	eventName.resize(32);
	eventDescription.resize(128);
	fscanf(fp, "%s\n", &eventName[0]);
	fscanf(fp, "%s\n", &eventDescription[0]);
	
	eventPath.resize(64);
	fscanf(fp, "%s\n", &eventPath[0]);
	imgPath.resize(64);
	fscanf(fp, "%s\n", &imgPath[0]);

	if (_access(imgPath.c_str(), 0))
		imgPath = "event/img/placeholder.png";
	loadimage(&img, imgPath.c_str());

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
		buttons[i]->description.resize(128);
		fscanf(fp, "Description:%s\n", &buttons[i]->description[0]);

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

std::string Event::getEventName() const
{
	return this->eventName;
}

std::string Event::getEventDescription() const
{
	return this->eventDescription;
}

std::string Event::getEventPath() const
{
	return this->eventPath;
}

std::string Event::getImgPath() const
{
	return this->imgPath;
}

void Event::setButtonCount(const int& _buttonCount)
{
	buttonCount = _buttonCount;
}

void Event::occurEvent(Character** player)
{

	/*
		这里会将Button::isShown设为1，然后不断绘制Event中的button
	并判断是否有button被点击
		保证有一个button可以点击并退出，其会将Button::isShown设为0
	Todo:
	1. 预处理Event中button的layout，根据buttonCount直接确定layout
	2. 绘制Event和buttons的Description与Name
	3. 在scene中绘制Event
		这里将Event的IMG存在对象中，读取时直接通过文件中的path读取.
		eventPath和imgPath在event/NPC/<file>中
		eventPath格式要求: event/NPC/<filename>
		imgPath格式要求: event/img/<filename>
	*/
	ExMessage msg;
	Button::isShown = 1;
	int DEBUG = 1;
	while (Button::isShown)
	{
		//
		
		for (Button* btn : buttons)
			btn->onClick(msg, player);

		/*注释或删除break以正常循环*/
		if (DEBUG)
		{
			for (Button* btn : buttons)
			{
				if (btn->getType() == BUTTON_TRADE)
					btn->tradeButton(player);
				else if (btn->getType() == BUTTON_FOOD)
					btn->foodButton(player);
			}
		}
		
	}
}

Event::~Event()
{
	for (int i = 0; i < buttonCount; ++i) if (buttons[i]) delete buttons[i];
}