#pragma once
#include "gadget.h"

// 治疗药水
class HealingPotion : public Gadget {
public:
    HealingPotion() : Gadget("治疗药水", "恢复健康的药水。", 1) {}

    Attr use() const override {
        std::cout << "喝下治疗药水。你感觉伤口在愈合。" << std::endl;
        Attr attr;
        attr.health = 50; // 恢复健康
        return attr;
    }
};
