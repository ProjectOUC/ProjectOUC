#pragma once
#include "weapon.h"

class Lance : public Weapon {
public:
    Lance(const std::string& name, const std::string& description, 
        int space, int durability, int level, 
        const std::string& quality,
        int attackPower)
        : Weapon(name, description, space, durability, level, quality, 3, attackPower, 0) {}

    // 纯虚函数，具体由子类实现
    virtual void attack() const = 0;
};

class IronLance : public Lance {
public:
    IronLance()
        : Lance("铁尖枪", "一把由铁打造的基础长枪", 2, 50, 1, "普通", 12) {}

    void attack() const override {
        std::cout << "铁长枪刺击，攻击力 " << getAttackPower() << std::endl;
    }
};

class RedCrestedLance : public Lance {
public:
    RedCrestedLance()
        : Lance("红缨枪", "一把装饰有红缨的长枪，轻巧而锋利", 3, 70, 1, "稀有", 43) {}

    void attack() const override {
        std::cout << "红缨枪刺击，攻击力 " << getAttackPower() << std::endl;
    }
};

class DragonBoneLance : public Lance {
public:
    DragonBoneLance()
        : Lance("龙骨长枪", "一把由龙骨打造的长枪，坚韧无比", 6, 100, 1, "传说", 100) {}

    void attack() const override {
        std::cout << "龙骨长枪刺击，攻击力 " << getAttackPower() << std::endl;
    }
};

