#pragma once
#include"weapon.h"

class Sword : public Weapon {
public:
    Sword(const std::string& name, const std::string& description, 
        int space, int durability, int level, 
        const std::string& quality,int attackPower)
        : Weapon(name, description, space, durability, level, quality, 1, attackPower, 0) {}

    // ʵ�� attack ����
    void attack() const = 0;
};

class IronSword : public Sword {
public:
    IronSword()
        : Sword("����", "һ����������Ļ�����", 2, 50, 1, "��ͨ", 15) {}

    // ʵ�� attack ����
    void attack() const override {
        std::cout << "�������裬������ " << getAttackPower() << std::endl;
    }
};

class MithrilSword : public Sword {
public:
    MithrilSword()
        : Sword("��������", "һ������������ĳ���", 2, 70, 1, "ϡ��", 50) {}

    // ʵ�� attack ����
    void attack() const override {
        std::cout << "�����������裬������ " << getAttackPower() << std::endl;
    }
};

class BladeOfTheRuinedKing : public Sword {
public:
    BladeOfTheRuinedKing()
        : Sword("�ư�����֮��", "һ�Ѵ�˵�еĽ�������ȡ���˵�������", 5, 100, 1, "��˵", 120) {}

    // ʵ�� attack ����
    void attack() const override {
        std::cout << "�ư�����֮�����裬������ " << getAttackPower() << "��������ȡ���˵���������" << std::endl;
    }
};