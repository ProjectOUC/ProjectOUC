#pragma once
#include "../../attribute.h"
#include "../item.h"

class Gadget : public Item {
public:
    Gadget(const std::string& name, const std::string& description, int space)
        : Item(name, description, space) {}

};

