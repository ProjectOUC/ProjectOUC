#pragma once
#include "gadget.h"

// 扩容宝石
class ExpansionGem : public Gadget {
public:
    ExpansionGem() : Gadget("扩容宝石", "扩展你的背包容量的宝石。", 1) {}

    Attr use() const override {
        std::cout << "使用扩容宝石。你的背包容量增加了。" << std::endl;
        Attr attr;
        attr.capacity = 5;
        return attr;
    }
};

