#pragma once
#include "gadget.h"

class Key : public Gadget {
public:
    Key() : Gadget("Կ��", "һ���������ŵĻ���Կ�ס�", 1) {}

    Attr use() const override {
        std::cout << "ʹ��Կ�������š�" << std::endl;
        return Attr(); // Կ�׿���û���ر������Ӱ��
    }
};
