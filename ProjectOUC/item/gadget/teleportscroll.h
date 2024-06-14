#pragma once
#include "gadget.h"

// 传送卷轴
class TeleportScroll : public Gadget {
public:
    TeleportScroll() : Gadget("传送卷轴", "可以传送的卷轴。", 1) {}

    Attr use() const override {
        std::cout << "使用传送卷轴。你被传送到了一个新地点。" << std::endl;
        Attr attr;
        attr.teleport = true; // 传送效果
        return attr;
    }
};

