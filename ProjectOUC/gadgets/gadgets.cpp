#include "gadgets.h"

<<<<<<< HEAD
<<<<<<< HEAD
extern const int max_gadget_index = 7;
=======
extern const int max_gadget_index = 6;
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
=======
extern const int max_gadget_index = 7;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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

<<<<<<< HEAD
<<<<<<< HEAD
	gadgetList[6] = new Key;

=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
	for (int i = 0; i < max_gadget_index; ++i)
	{
		std::string path = gadgetList[i]->get_name() + ".jpg";
		loadimage(&gadgetList[i]->img, path.c_str());
	}
=======
	gadgetList[6] = new Key;
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
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