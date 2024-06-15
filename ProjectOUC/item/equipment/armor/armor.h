#pragma once
#include "../equipment.h"

// ������
class Armor : public Equipment {
protected:
    int defense; // ������
    int block;   // ��ֵ
    int health;  // ����ֵ
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
        std::cout << "������: " << defense << "����ֵ: " << block << "������ֵ: " << health << std::endl;
    }*/

    virtual void protect() const = 0;
};

class LeatherArmor : public Armor {
public:
    LeatherArmor()
        : Armor("Ƥ��", "һ������Ƥ�ף��ṩ��������", 3, 40, 1, "��ͨ", 10, 5, 20) {}

    void protect() const override {
        std::cout << "����Ƥ�ף������� " << getDefense()
            << "����ֵ " << getBlock()
            << "������ֵ " << getHealth() << std::endl;
    }
};

class ChainmailArmor : public Armor {
public:
    ChainmailArmor()
        : Armor("���Ӽ�", "һ����̵����Ӽף��ṩ�еȷ���", 5, 70, 1, "ϡ��", 20, 10, 40) {}

    void protect() const override {
        std::cout << "�������Ӽף������� " << getDefense()
            << "����ֵ " << getBlock()
            << "������ֵ " << getHealth() << std::endl;
    }
};

class DragonScaleArmor : public Armor {
public:
    DragonScaleArmor()
        : Armor("���ۼ�", "һ����˵�е����ۼף��ṩ���߷���", 7, 100, 1, "��˵", 50, 25, 100) {}

    void protect() const override {
        std::cout << "�������ۼף������� " << getDefense()
            << "����ֵ " << getBlock()
            << "������ֵ " << getHealth() << std::endl;
    }
};


