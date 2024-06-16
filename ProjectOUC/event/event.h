#pragma once
#include "../utils/button.h"

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
	int getButtonCount() const;
	std::string getEventName() const;
	std::string getEventDescription() const;
	std::string getEventPath() const;
	std::string getImgPath() const;
	Button* getButton(int i) const;

	void setType(const eventType& _type);
	void setButtonCount(const int& _buttonCount);
	bool isDisappear();

	void occurEvent(Character** player);

	IMAGE img;

	~Event();
private:
	eventType type;
	int buttonCount;
	std::vector<Button*> buttons;
	std::string eventName;
	std::string eventDescription;
	std::string eventPath;
	std::string imgPath;
	int disappear;
};

void initTrapList();

void destroyTrapList();