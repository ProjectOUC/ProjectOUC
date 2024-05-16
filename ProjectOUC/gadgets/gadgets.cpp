#include "gadgets.h"

extern const int max_gadget_index = 5;
std::vector<Gadget*> gadgetList;
std::set<int> usefulGadgetSet;
std::vector<int> gadgetVisited;

void initGadgetList()
{
	gadgetList.resize(max_gadget_index);
	gadgetVisited.resize(max_gadget_index);

	gadgetList[0] = new Sword;

	gadgetList[1] = new Shield;

	gadgetList[2] = new HealPotion;
	usefulGadgetSet.insert(2);

	gadgetList[3] = new CursedStone;

	gadgetList[4] = new Bow;


}

void destroyGadgetList()
{
	for (int i = 0; i < max_gadget_index; ++i)
	{
		delete gadgetList[i];
	}
}