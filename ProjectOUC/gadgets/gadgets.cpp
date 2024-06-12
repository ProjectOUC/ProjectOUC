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

	for (int i = 0; i < max_gadget_index; ++i)
	{
		std::string path = gadgetList[i]->get_name() + ".jpg";
		loadimage(&gadgetList[i]->img, path.c_str());
	}
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
		if (gadgetList[i]->get_name() == str) return i;
	return -1;
}