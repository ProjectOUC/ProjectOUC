#pragma once
#include "gadget.h"

// ���ݱ�ʯ
class ExpansionGem : public Gadget {
public:
    ExpansionGem() : Gadget("���ݱ�ʯ", "��չ��ı��������ı�ʯ��", 1) {}

    Attr use() const override {
        std::cout << "ʹ�����ݱ�ʯ����ı������������ˡ�" << std::endl;
        Attr attr;
        attr.capacity = 5;
        return attr;
    }
};

