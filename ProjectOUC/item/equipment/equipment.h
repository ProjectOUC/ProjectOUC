#pragma once
#include"../item.h"

class Equipment : public Item {
protected:
    int durability;   // 耐久度（0—100）
    int level;        // 等级（1—3级）
    std::string quality;      // 品质（1：普通，2：稀有，3：史诗，4：传奇）
    bool isEquipped;  // 是否被使用
public:

    Equipment(const std::string& name, const std::string& description, int space, 
        int durability, int level, const std::string& quality)
        : Item(name, description, space), durability(durability), level(level), quality(quality), isEquipped(false) {}

    // 析构函数
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

    //// 显示信息函数
    //void display() const override {
    //    Item::display();
    //    std::cout << "耐久度: " << durability << std::endl;
    //    std::cout << "等级: " << level << std::endl;
    //    std::cout << "品质: " << quality << std::endl;
    //}
    // 装备升级
    int upgrade();
    // 修复装备
    int fix(int addDurability);
};
