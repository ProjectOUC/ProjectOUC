#pragma once
#include "gadget.h"

// ����ҩˮ
class HealingPotion : public Gadget {
public:
    HealingPotion() : Gadget("����ҩˮ", "�ָ�������ҩˮ��", 1) {}

    Attr use() const override {
        std::cout << "��������ҩˮ����о��˿������ϡ�" << std::endl;
        Attr attr;
        attr.health = 50; // �ָ�����
        return attr;
    }
};
