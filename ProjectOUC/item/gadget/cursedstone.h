#pragma once
#include "gadget.h"

// 诅咒之石
class CursedStone : public Gadget {
public:
    CursedStone() : Gadget("诅咒之石", "携带可怕诅咒的石头。", 1) {}

    Attr use() const override {
        std::cout << "使用诅咒之石。你感受到黑暗的能量。" << std::endl;
        Attr attr;
        attr.health = attr.maxHealth = -5;
        return attr;
    }
};
