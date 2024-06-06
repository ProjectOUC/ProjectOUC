#pragma once
#include "chest.h"

Chest::Chest(Attr _attr, std::string _name, int _coin, Position _pos, bool _moved) :
	Character(_attr, _name, CHEST, _coin, _pos, _moved) {};