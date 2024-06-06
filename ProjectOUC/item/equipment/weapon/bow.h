#pragma once
#include "weapon.h"

class Bow : public Weapon {
public:
    Bow(const std::string& name, const std::string& description,
        int space, int durability, int level,
        const std::string& quality,
        int attackPower)
        : Weapon(name, description, space, durability, level, quality, 5, attackPower, 0) {}

    virtual void attack() const = 0;
};

class LightBow : public Bow {
public:
    LightBow()
        : Bow("轻灵之弓", "一把轻便而灵活的弓，适合快速攻击", 2, 40, 1, "普通", 8) {}

    void attack() const override {
        std::cout << "轻巧之弓射出箭矢，攻击力 " << getAttackPower() << std::endl;
    }
};

class StormBow : public Bow {
public:
    StormBow()
        : Bow("风暴之弓", "一把能够召唤风暴的弓，射出的箭矢如风暴般猛烈", 3, 70, 1, "稀有", 35) {}

    void attack() const override {
        std::cout << "风暴之弓射出箭矢，攻击力 " << getAttackPower() << "，箭矢如风暴般猛烈。" << std::endl;
    }
};

class EndPoem : public Bow {
public:
    EndPoem()
        : Bow("终末之诗", "一把传说中的弓，能够射出强大的终末之箭", 5, 100, 3, "传说", 85) {}

    void attack() const override {
        std::cout << "终末之诗射出箭矢，攻击力 " << getAttackPower() << "，箭矢如同终末的预言。" << std::endl;
    }
};
