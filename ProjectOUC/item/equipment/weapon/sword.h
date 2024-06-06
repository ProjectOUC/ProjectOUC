#pragma once
#include"weapon.h"

class Sword : public Weapon {
public:
    Sword(const std::string& name, const std::string& description, 
        int space, int durability, int level, 
        const std::string& quality,int attackPower)
        : Weapon(name, description, space, durability, level, quality, 1, attackPower, 0) {}

    // 实现 attack 函数
    void attack() const = 0;
};

class IronSword : public Sword {
public:
    IronSword()
        : Sword("铁剑", "一把由铁打造的基础剑", 2, 50, 1, "普通", 15) {}

    // 实现 attack 函数
    void attack() const override {
        std::cout << "铁剑挥舞，攻击力 " << getAttackPower() << std::endl;
    }
};

class MithrilSword : public Sword {
public:
    MithrilSword()
        : Sword("秘银长剑", "一把由秘银打造的长剑", 2, 70, 1, "稀有", 50) {}

    // 实现 attack 函数
    void attack() const override {
        std::cout << "秘银长剑挥舞，攻击力 " << getAttackPower() << std::endl;
    }
};

class BladeOfTheRuinedKing : public Sword {
public:
    BladeOfTheRuinedKing()
        : Sword("破败王者之剑", "一把传说中的剑，能吸取敌人的生命力", 5, 100, 1, "传说", 120) {}

    // 实现 attack 函数
    void attack() const override {
        std::cout << "破败王者之剑挥舞，攻击力 " << getAttackPower() << "，并且吸取敌人的生命力。" << std::endl;
    }
};