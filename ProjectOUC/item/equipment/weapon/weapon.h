#pragma once
#include"../equipment.h"

class Weapon : public Equipment {
protected:
    int range;  // 攻击距离
    int attackPower; // 攻击力
    int type;   // 攻击类型（0：物理攻击, 1：魔法攻击）

public:
    // 构造函数
    Weapon(const std::string& name, const std::string& description, int space, int durability, int level, 
           const std::string& quality,
           int range, int attackPower, int type)
        : Equipment(name, description, space, durability, level, quality), 
            range(range), attackPower(attackPower), type(type) {}

    // 析构函数
    virtual ~Weapon() {}

    // Setters
    void setRange(int range) { this->range = range; }
    void setAttackPower(int attackPower) { this->attackPower = attackPower; }
    void setType(int type) { this->type = type; }

    // Getters
    int getRange() const { return range; }
    int getAttackPower() const { return attackPower; }
    int getType() const { return type; }

    // 显示信息函数
  /*  void display() const override {
        Equipment::display();
        std::cout << "Range: " << range << std::endl;
        std::cout << "Attack: " << attackPower << std::endl;
        std::cout << "Type: " << (type == 0 ? "Physical" : "Magical") << std::endl;
    }*/
    Attr use() const override {
        Attr attr;
        attr.attack = attackPower;
        return getEquipped() ? -attr : attr;
    }

    // 纯虚函数 attack
    virtual void attack() const = 0;
};
