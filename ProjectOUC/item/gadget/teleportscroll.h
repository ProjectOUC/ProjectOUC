#pragma once
#include "gadget.h"

// ���;���
class TeleportScroll : public Gadget {
public:
    TeleportScroll() : Gadget("���;���", "���Դ��͵ľ��ᡣ", 1) {}

    Attr use() const override {
        std::cout << "ʹ�ô��;��ᡣ�㱻���͵���һ���µص㡣" << std::endl;
        Attr attr;
        attr.teleport = true; // ����Ч��
        return attr;
    }
};

