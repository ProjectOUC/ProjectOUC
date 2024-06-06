#pragma once
#include "gadget.h"

// 锻造石
class ForgingStone : public Gadget {
public:
    ForgingStone() : Gadget("锻造石", "用来锻造新装备的石头。", 1) {}

    Attr use() const override {
        std::cout << "使用锻造石。你感觉到锻造的力量。" << std::endl;
        Attr attr;
        attr.durability = 10;
        return attr;
    }
};

