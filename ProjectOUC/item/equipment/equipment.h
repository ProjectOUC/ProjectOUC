#pragma once
#include"../item.h"

class Equipment : public Item {
protected:
    int durability;   // �;öȣ�0��100��
    int level;        // �ȼ���1��3����
    std::string quality;      // Ʒ�ʣ�1����ͨ��2��ϡ�У�3��ʷʫ��4�����棩
    bool isEquipped;  // �Ƿ�ʹ��
public:

    Equipment(const std::string& name, const std::string& description, int space, 
        int durability, int level, const std::string& quality)
        : Item(name, description, space), durability(durability), level(level), quality(quality), isEquipped(false) {}

    // ��������
    virtual ~Equipment() {}

    // Setters
    void setDurability(int durability) { this->durability = durability; }
    void setLevel(int level) { this->level = level; }
    void setQuality(const std::string& quality) { this->quality = quality; }
    void setEquipped(bool equipped) { isEquipped = equipped; }

    // Getters
    int getDurability() const { return durability; }
    int getLevel() const { return level; }
    std::string getQuality() const { return quality; }
    bool getEquipped() const { return isEquipped; }

    //// ��ʾ��Ϣ����
    //void display() const override {
    //    Item::display();
    //    std::cout << "�;ö�: " << durability << std::endl;
    //    std::cout << "�ȼ�: " << level << std::endl;
    //    std::cout << "Ʒ��: " << quality << std::endl;
    //}
    // װ������
    int upgrade();
    // �޸�װ��
    int fix(int addDurability);
};
