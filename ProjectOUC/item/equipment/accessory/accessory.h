#pragma once
#include "../equipment.h"

// 饰品类
class Accessory : public Equipment {
protected:
    int strength;    // 力量
    int agility;     // 敏捷
    int wisdom;      // 智慧

public:
    Accessory(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom)
        : Equipment(name, description, space, durability, level, quality),
        strength(strength), agility(agility), wisdom(wisdom) {}

    /*void display() const override {
        Equipment::display();
        std::cout << "力量: " << strength << "，敏捷: " << agility << "，智慧: " << wisdom << std::endl;
    }*/

    int getStrength() const { return strength; }
    int getAgility() const { return agility; }
    int getWisdom() const { return wisdom; }
};
