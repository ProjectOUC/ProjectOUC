#pragma once
#include "gadget.h"

// ����֮ʯ
class CursedStone : public Gadget {
public:
    CursedStone() : Gadget("����֮ʯ", "Я�����������ʯͷ��", 1) {}

    Attr use() const override {
        std::cout << "ʹ������֮ʯ������ܵ��ڰ���������" << std::endl;
        Attr attr;
        attr.health = attr.maxHealth = -5;
        return attr;
    }
};
