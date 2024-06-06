#pragma once
#include "accessory.h"

// 护身符
class Amulet : public Accessory {
protected:
    int speed;      // 速度
    float  missRate;   // 闪避率

public:
    Amulet(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom, int speed, float missRate)
        : Accessory(name, description, space, durability, level, quality, strength, agility, wisdom),
        speed(speed), missRate(missRate) {}

    virtual void display() const {
        std::cout << "护身符: ";
 /*       Accessory::display();*/
        std::cout << "速度: " << speed << "，闪避率: " << missRate << std::endl;
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
        : Amulet("青铜项链", "一条普通的青铜项链，朴素而耐用。", 1, 50, 1, "普通", 3, 2, 2, 2, 0.10) {}

    void display() const override {
        std::cout << "青铜项链: ";
        Amulet::display();
    }
};

class JadeAmulet : public Amulet {
public:
    JadeAmulet()
        : Amulet("翠玉项链", "一条稀有的翠玉项链，散发着清凉的气息。", 1, 80, 1, "稀有", 5, 4, 3, 5, 0.25) {}

    void display() const override {
        std::cout << "翠玉项链: ";
        Amulet::display();
    }
};

class MysticalAmulet : public Amulet {
public:
    MysticalAmulet()
        : Amulet("神秘项链", "一条传说中的神秘项链，蕴含着无尽的神秘力量。", 1, 100, 1, "传说", 10, 8, 7, 10, 0.5) {}

    void display() const override {
        std::cout << "神秘项链: ";
        Amulet::display();
    }
};

