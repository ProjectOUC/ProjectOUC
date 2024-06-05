#pragma once
#include <string>
#include <vector>
#include "../utils/button.h"
#include "../attribute.h"
#include "graphics.h"

enum eventType
{ 
	EVENT_UNDEFINED,
	EVENT_NPC,
	EVENT_TRAP 
};

class Event
{
public:
	Event();
	Event(std::string path);

	bool isNPC() const;
	bool isTrap() const;

	eventType getType() const;
	int getEventCount() const;

	void setType(const eventType& _type);
	void setButtonCount(const int& _buttonCount);

	void occurEvent(Character** player);

	IMAGE img;

	~Event();
private:
	eventType type;
	int buttonCount;
	std::vector<Button*> buttons;
	std::string eventName;
	std::string eventDescription;
};

