#pragma once
#include "../equipment.h"

// 防具类
class Armor : public Equipment {
protected:
    int defense; // 防御力
    int block;   // 格挡值
    int health;  // 生命值
public:
    Armor(const std::string& name, const std::string& description,
        int space, int durability, int level,const std::string& quality, 
        int defense,int block, int health)
        : Equipment(name, description, space, durability, level, quality),
        defense(defense), block(block), health(health) {}

    int getDefense() const {return defense;}
    int getBlock() const {return block;}
    int getHealth() const {return health; }

    Attr use() const override {
        Attr attr;
        attr.defense = defense;
        attr.block = block;
        attr.health = health;
        return getEquipped() ? -attr : attr;
    }

 /*   void display() const override {
        Equipment::display();
        std::cout << "防御力: " << defense << "，格挡值: " << block << "，生命值: " << health << std::endl;
    }*/

    virtual void protect() const = 0;
};

class LeatherArmor : public Armor {
public:
    LeatherArmor()
        : Armor("皮甲", "一件轻便的皮甲，提供基本防护", 3, 40, 1, "普通", 10, 5, 20) {}

    void protect() const override {
        std::cout << "穿上皮甲，防御力 " << getDefense()
            << "，格挡值 " << getBlock()
            << "，生命值 " << getHealth() << std::endl;
    }
};

class ChainmailArmor : public Armor {
public:
    ChainmailArmor()
        : Armor("锁子甲", "一件坚固的锁子甲，提供中等防护", 5, 70, 1, "稀有", 20, 10, 40) {}

    void protect() const override {
        std::cout << "穿上锁子甲，防御力 " << getDefense()
            << "，格挡值 " << getBlock()
            << "，生命值 " << getHealth() << std::endl;
    }
};

class DragonScaleArmor : public Armor {
public:
    DragonScaleArmor()
        : Armor("龙鳞甲", "一件传说中的龙鳞甲，提供极高防护", 7, 100, 1, "传说", 50, 25, 100) {}

    void protect() const override {
        std::cout << "穿上龙鳞甲，防御力 " << getDefense()
            << "，格挡值 " << getBlock()
            << "，生命值 " << getHealth() << std::endl;
    }
};


