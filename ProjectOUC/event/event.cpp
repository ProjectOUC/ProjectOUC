#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include"../paint.h"
#include <iostream>
#include <io.h>

extern const int max_gadget_index;

Event::Event()
{
	type = EVENT_UNDEFINED;
	buttonCount = 0;
	disappear = -1;
}

Event::Event(std::string path)
{
	disappear = -1;
	FILE* fp;
	if ((fp = fopen(path.c_str(), "r")) == nullptr)
	{
		std::cerr << "Event path " << path << " doesn't exist\n";
		exit(0);
	}

	char buffer[1024];
	fscanf(fp, "%s\n", buffer);
	if (_strnicmp(buffer, "EVENT_NPC", 9) == 0)
	{
		type = EVENT_NPC;
	}
	else if (_strnicmp(buffer, "EVENT_TRAP", 10) == 0)
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
		imgPath = "res/event/placeholder.png";
	loadimage(&img, imgPath.c_str());

	fscanf(fp, "%d\n", &buttonCount);
	buttons.resize(buttonCount);

	for (int i = 0; i < buttonCount; ++i)
	{
		buttons[i] = new Button;
		int _;
		fscanf(fp, "Button%d:\n", &_);
		fscanf(fp, "%s\n", buffer);
		if (_strnicmp(buffer, "BUTTON_QUIT", 11) == 0)
			buttons[i]->type = BUTTON_QUIT;
		else if (_strnicmp(buffer, "BUTTON_TRADE", 12) == 0)
			buttons[i]->type = BUTTON_TRADE;
		else if (_strnicmp(buffer, "BUTTON_FOOD", 11) == 0)
			buttons[i]->type = BUTTON_FOOD;
		buttons[i]->description.resize(128);
		fscanf(fp, "Description:%s\n", &buttons[i]->description[0]);

		if (buttons[i]->type == BUTTON_TRADE)
		{
			fscanf(fp, "Gain:\n");
			while (1)
			{
				float reading = 0.0f;
				fscanf(fp, "%1024[^:\n]", buffer);
				if (!_strnicmp(buffer, "End", 3))
				{
					fgetc(fp);
					break;
				}

				if (!_strnicmp(buffer, "gadget", 6))
				{
					char* name = strtok(buffer, " ");
					name = strtok(NULL, " ");
					int num = -1;
					int ind = -1;
					fscanf(fp, ":%d\n", &num);
					if (isdigit(buffer[0])) ind = std::stoi(name);
					else ind = findGadget(std::string(name));
					if (ind < 0 || ind >= max_gadget_index) continue;
					buttons[i]->gadgetsGain[ind] = num;
					continue;
				}
				fscanf(fp, ":%f\n", &reading);
				if (!_strnicmp(buffer, "coin", 4))
				{
					buttons[i]->gainCoin = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "foodCapacity", 12))
				{
					buttons[i]->gainFoodCapacity = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "food", 4))
				{
					buttons[i]->gainFood = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "exp", 3))
				{
					buttons[i]->gainExp = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "maxHealth", 9))
				{
					buttons[i]->gainAttr.maxHealth = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "health", 6))
				{
					buttons[i]->gainAttr.health = static_cast<int>(reading);
				
				}
				else if (!_strnicmp(buffer, "strength", 8))
				{
					buttons[i]->gainAttr.strength = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "speed", 5))
				{
					buttons[i]->gainAttr.speed = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "agility", 7))
				{
					buttons[i]->gainAttr.agility = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "wisdom", 6))
				{
					buttons[i]->gainAttr.wisdom = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "attack", 6))
				{
					buttons[i]->gainAttr.attack = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "block", 5))
				{
					buttons[i]->gainAttr.block = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "criticalAttackRate", 18))
				{
					buttons[i]->gainAttr.criticalAttackRate = reading;
				}
				else if (!_strnicmp(buffer, "defense", 7))
				{
					buttons[i]->gainAttr.defense = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "diceNum", 7))
				{
					buttons[i]->gainAttr.diceNum = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "facet", 5))
				{
					buttons[i]->gainAttr.facet = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "hitRate", 7))
				{
					buttons[i]->gainAttr.hitRate = reading;
				}
				else if (!_strnicmp(buffer, "missRate", 8))
				{
					buttons[i]->gainAttr.missRate = reading;
				}
				else if (!_strnicmp(buffer, "visibleRadius", 13))
				{
					buttons[i]->gainAttr.visibleRadius = static_cast<int>(reading);
				}
			}
 			fscanf(fp, "Need:\n");
			while (1)
			{
				float reading = 0.0f;
				fscanf(fp, "%1024[^:\n]", buffer);
				if (!_strnicmp(buffer, "End", 3))
				{
					std::cout << fgetc(fp);
					break;
				}
				if (!_strnicmp(buffer, "gadget", 6))
				{
					char* name = strtok(buffer, " ");
					name = strtok(NULL, " ");
					std::cout << name << "\n";
					int num = -1;
					int ind = -1;
					fscanf(fp, ":%d\n", &num);
					if (isdigit(buffer[0])) ind = std::stoi(name);
					else ind = findGadget(std::string(name));
					if (ind < 0 || ind >= max_gadget_index) continue;
					buttons[i]->minGadgets[ind] = num;
					continue;
				}
				fscanf(fp, ":%f\n", &reading);
				if (!_strnicmp(buffer, "coin", 4))
				{
					buttons[i]->minCoin = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "foodCapacity", 12))
				{
					buttons[i]->minFoodCapacity = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "food", 4))
				{
					buttons[i]->minFood = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "level", 5))
				{
					buttons[i]->minLevel = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "maxHealth", 9))
				{
					buttons[i]->minAttr.maxHealth = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "health", 6))
				{
					buttons[i]->minAttr.health = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "strength", 8))
				{
					buttons[i]->minAttr.strength = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "speed", 5))
				{
					buttons[i]->minAttr.speed = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "agility", 7))
				{
					buttons[i]->minAttr.agility = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "wisdom", 6))
				{
					buttons[i]->minAttr.wisdom = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "attack", 6))
				{
					buttons[i]->minAttr.attack = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "block", 5))
				{
					buttons[i]->minAttr.block = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "criticalAttackRate", 18))
				{
					buttons[i]->minAttr.criticalAttackRate = reading;
				}
				else if (!_strnicmp(buffer, "defense", 7))
				{
					buttons[i]->minAttr.defense = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "diceNum", 7))
				{
					buttons[i]->minAttr.diceNum = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "facet", 5))
				{
					buttons[i]->minAttr.facet = static_cast<int>(reading);
				}
				else if (!_strnicmp(buffer, "hitRate", 7))
				{
					buttons[i]->minAttr.hitRate = reading;
				}
				else if (!_strnicmp(buffer, "missRate", 8))
				{
					buttons[i]->minAttr.missRate = reading;
				}
				else if (!_strnicmp(buffer, "visibleRadius", 13))
				{
					buttons[i]->minAttr.visibleRadius = static_cast<int>(reading);
				}
			}
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

int Event::getButtonCount() const
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
		Button_paint(buttonCount,buttons);
		FlushBatchDraw();
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.ch)
				{
				case '1':
					if (buttonCount >= 1)    //根据按钮个数判断输出是否合法
					{
						Button::isShown = 0;
					}
					break;
				case '2':
					if (buttonCount >= 2)
					{
						Button::isShown = 0;
					}
					break;
				case '3':
					if (buttonCount >= 3)
					{
						Button::isShown = 0;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

Event::~Event()
{
	for (int i = 0; i < buttonCount; ++i) if (buttons[i]) delete buttons[i];
}