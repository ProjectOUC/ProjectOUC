#include "gadgets.h"

extern const int max_gadget_index = 7;
std::vector<Gadget*> gadgetList;
std::vector<int> gadgetVisited;


void initGadgetList()
{
	gadgetList.resize(max_gadget_index);
	gadgetVisited.resize(max_gadget_index);

	gadgetList[0] = new Sword;

	gadgetList[1] = new Shield;

	gadgetList[2] = new HealPotion;

	gadgetList[3] = new CursedStone;

	gadgetList[4] = new Bow;

	gadgetList[5] = new TeleportScroll;

	gadgetList[6] = new Key;
}

void destroyGadgetList()
{
	for (int i = 0; i < max_gadget_index; ++i)
	{
		delete gadgetList[i];
	}
}

int findGadget(std::string str)
{
	for (int i = 0; i < gadgetList.size(); ++i)
	{
		if (str.size() != gadgetList[i]->get_name().size()) continue;
		bool flag = true;
		for (int j = 0; j < str.size(); ++j)
		{
			if (tolower(str[j]) != tolower(gadgetList[i]->get_name()[j])) flag = false;
		}
		if (flag) return i;
	}

	return -1;
}