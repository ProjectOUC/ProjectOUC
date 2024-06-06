#pragma once
#include "accessory.h"

// �����
class Amulet : public Accessory {
protected:
    int speed;      // �ٶ�
    float  missRate;   // ������

public:
    Amulet(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom, int speed, float missRate)
        : Accessory(name, description, space, durability, level, quality, strength, agility, wisdom),
        speed(speed), missRate(missRate) {}

    virtual void display() const {
        std::cout << "�����: ";
 /*       Accessory::display();*/
        std::cout << "�ٶ�: " << speed << "��������: " << missRate << std::endl;
    }

    int getSpeed() const { return speed; }
    float getMissRate() const { return missRate; }

    Attr use() const override {
        Attr attr;
        attr.strength = strength;
        attr.agility = agility;
        attr.wisdom = wisdom;
        attr.attackFirstLevel = speed;
        attr.missRate = missRate;
        return getEquipped() ? -attr : attr;
    }
};

class BronzeAmulet : public Amulet {
public:
    BronzeAmulet()
        : Amulet("��ͭ����", "һ����ͨ����ͭ���������ض����á�", 1, 50, 1, "��ͨ", 3, 2, 2, 2, 0.10) {}

    void display() const override {
        std::cout << "��ͭ����: ";
        Amulet::display();
    }
};

class JadeAmulet : public Amulet {
public:
    JadeAmulet()
        : Amulet("��������", "һ��ϡ�еĴ���������ɢ������������Ϣ��", 1, 80, 1, "ϡ��", 5, 4, 3, 5, 0.25) {}

    void display() const override {
        std::cout << "��������: ";
        Amulet::display();
    }
};

class MysticalAmulet : public Amulet {
public:
    MysticalAmulet()
        : Amulet("��������", "һ����˵�е������������̺����޾�������������", 1, 100, 1, "��˵", 10, 8, 7, 10, 0.5) {}

    void display() const override {
        std::cout << "��������: ";
        Amulet::display();
    }
};

