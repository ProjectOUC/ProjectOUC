#pragma once
#include "accessory.h"

class Ring : public Accessory {
protected:
    float  critRate;   // ������

public:
    Ring(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom, float  critRate)
        : Accessory(name, description, space, durability, level, quality, strength, agility, wisdom),
        critRate(critRate) {}

    virtual void display() const{
        std::cout << "��ָ: ";
     
        std::cout << "������: " << critRate << std::endl;
    }

    float getCritRate() const { return critRate; }

    Attr use() const override {
        Attr attr;
        attr.strength = strength;   
        attr.agility = agility;
        attr.wisdom = wisdom;
        attr.criticalAttackRate = critRate;
        return getEquipped() ? -attr : attr;
    }
};


class BronzeRing : public Ring {
public:
    BronzeRing()
        : Ring("��ָͭ��", "һö��ͨ����ͭ��ָ�����ض���̡�", 1, 50, 1, "��ͨ", 3, 2, 2, 0.10) {}

    void display() const override {
        std::cout << "��ָͭ��: ";
        Ring::display();
    }
};

class AmethystRing : public Ring {
public:
    AmethystRing()
        : Ring("�Ͼ���ָ", "һöϡ�е��Ͼ���ָ����˸�����ص���ɫ��â��", 1, 80, 1, "ϡ��", 5, 4, 3, 0.25) {}

    void display() const override {
        std::cout << "�Ͼ���ָ: ";
        Ring::display();
    }
};

class DragonRing : public Ring {
public:
    DragonRing()
        : Ring("ħ��֮��", "һö��˵�еĽ�ָ����˵����һ�����ϵ�ħ����Ƭ������ɡ�", 1, 100, 1, "��˵", 10, 8, 7, 0.60) {}

    void display() const override {
        std::cout << "ħ��֮��: ";
        Ring::display();
    }
};
