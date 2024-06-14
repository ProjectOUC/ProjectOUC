#pragma once
#include "accessory.h"

class Ring : public Accessory {
protected:
    float  critRate;   // 暴击率

public:
    Ring(const std::string& name, const std::string& description, int space, int durability,
        int level, const std::string& quality, int strength, int agility, int wisdom, float  critRate)
        : Accessory(name, description, space, durability, level, quality, strength, agility, wisdom),
        critRate(critRate) {}

    virtual void display() const{
        std::cout << "戒指: ";
     
        std::cout << "暴击率: " << critRate << std::endl;
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
        : Ring("青铜指环", "一枚普通的青铜戒指，朴素而坚固。", 1, 50, 1, "普通", 3, 2, 2, 0.10) {}

    void display() const override {
        std::cout << "青铜指环: ";
        Ring::display();
    }
};

class AmethystRing : public Ring {
public:
    AmethystRing()
        : Ring("紫晶戒指", "一枚稀有的紫晶戒指，闪烁着神秘的紫色光芒。", 1, 80, 1, "稀有", 5, 4, 3, 0.25) {}

    void display() const override {
        std::cout << "紫晶戒指: ";
        Ring::display();
    }
};

class DragonRing : public Ring {
public:
    DragonRing()
        : Ring("魔龙之戒", "一枚传说中的戒指，据说是由一条古老的魔龙鳞片打造而成。", 1, 100, 1, "传说", 10, 8, 7, 0.60) {}

    void display() const override {
        std::cout << "魔龙之戒: ";
        Ring::display();
    }
};
