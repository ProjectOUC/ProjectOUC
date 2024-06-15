#pragma once
#include "weapon.h"

class Lance : public Weapon {
public:
    Lance(const std::string& name, const std::string& description, 
        int space, int durability, int level, 
        const std::string& quality,
        int attackPower)
        : Weapon(name, description, space, durability, level, quality, 3, attackPower, 0) {}

    // ���麯��������������ʵ��
    virtual void attack() const = 0;
};

class IronLance : public Lance {
public:
    IronLance()
        : Lance("����ǹ", "һ����������Ļ�����ǹ", 2, 50, 1, "��ͨ", 12) {}

    void attack() const override {
        std::cout << "����ǹ�̻��������� " << getAttackPower() << std::endl;
    }
};

class RedCrestedLance : public Lance {
public:
    RedCrestedLance()
        : Lance("��ӧǹ", "һ��װ���к�ӧ�ĳ�ǹ�����ɶ�����", 3, 70, 1, "ϡ��", 43) {}

    void attack() const override {
        std::cout << "��ӧǹ�̻��������� " << getAttackPower() << std::endl;
    }
};

class DragonBoneLance : public Lance {
public:
    DragonBoneLance()
        : Lance("���ǳ�ǹ", "һ�������Ǵ���ĳ�ǹ�������ޱ�", 6, 100, 1, "��˵", 100) {}

    void attack() const override {
        std::cout << "���ǳ�ǹ�̻��������� " << getAttackPower() << std::endl;
    }
};

