#pragma once
#include "gadget.h"

class Key : public Gadget {
public:
    Key() : Gadget("钥匙", "一把用来开门的基础钥匙。", 1) {}

    Attr use() const override {
        std::cout << "使用钥匙来开门。" << std::endl;
        return Attr(); // 钥匙可能没有特别的属性影响
    }
};
