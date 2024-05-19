#pragma once
#include "sword.h"
#include "shield.h"
#include "healpotion.h"
#include "cursedstone.h"
#include "bow.h"
#include "teleportscroll.h"
#include "key.h"

void initGadgetList();
void destroyGadgetList();
int findGadget(std::string str);