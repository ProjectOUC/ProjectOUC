#pragma once
#include "gadget.h"

// ����ʯ
class ForgingStone : public Gadget {
public:
    ForgingStone() : Gadget("����ʯ", "����������װ����ʯͷ��", 1) {}

    Attr use() const override {
        std::cout << "ʹ�ö���ʯ����о��������������" << std::endl;
        Attr attr;
        attr.durability = 10;
        return attr;
    }
};

