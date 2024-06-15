#pragma once
#include "../equipment.h"

// ��Ʒ��
class Accessory : public Equipment {
protected:
    int strength;    // ����
    int agility;     // ����
    int wisdom;      // �ǻ�

public:
    Accessory(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom)
        : Equipment(name, description, space, durability, level, quality),
        strength(strength), agility(agility), wisdom(wisdom) {}

    /*void display() const override {
        Equipment::display();
        std::cout << "����: " << strength << "������: " << agility << "���ǻ�: " << wisdom << std::endl;
    }*/

    int getStrength() const { return strength; }
    int getAgility() const { return agility; }
    int getWisdom() const { return wisdom; }
};
