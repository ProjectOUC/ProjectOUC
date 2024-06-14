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
        : Bow("����֮��", "һ���������Ĺ����ʺϿ��ٹ���", 2, 40, 1, "��ͨ", 8) {}

    void attack() const override {
        std::cout << "����֮�������ʸ�������� " << getAttackPower() << std::endl;
    }
};

class StormBow : public Bow {
public:
    StormBow()
        : Bow("�籩֮��", "һ���ܹ��ٻ��籩�Ĺ�������ļ�ʸ��籩������", 3, 70, 1, "ϡ��", 35) {}

    void attack() const override {
        std::cout << "�籩֮�������ʸ�������� " << getAttackPower() << "����ʸ��籩�����ҡ�" << std::endl;
    }
};

class EndPoem : public Bow {
public:
    EndPoem()
        : Bow("��ĩ֮ʫ", "һ�Ѵ�˵�еĹ����ܹ����ǿ�����ĩ֮��", 5, 100, 3, "��˵", 85) {}

    void attack() const override {
        std::cout << "��ĩ֮ʫ�����ʸ�������� " << getAttackPower() << "����ʸ��ͬ��ĩ��Ԥ�ԡ�" << std::endl;
    }
};
