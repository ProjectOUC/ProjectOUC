#pragma once
#include <vector>
#include <map>
#include "equipment_factory.h"

enum class EquipmentType { Weapon, Armor, Accessory };

class EquipmentTool {
public:
    EquipmentTool() {
        std::srand(std::time(nullptr));
        initProbability();
    }

    ~EquipmentTool() {
        for (Equipment* equipment : equipments) {
            delete equipment;
        }
    }

    // 随机生成装备
    Equipment* generateEquipment(EquipmentType type);
    // 批量随机生成装备
    std::vector<Equipment*> generateEquipment(EquipmentType type, int quantity);
    // 删除装备
    void removeEquipment(Equipment* equipment);
    // 获取装备列表
    const std::vector<Equipment*>& getEquipments() const {
        return equipments;
    }

private:
    std::vector<Equipment*> equipments;
    std::map<std::string, int> probability;

    void initProbability() {
        // 初始化不同品质装备的概率
        probability["普通"] = 70;
        probability["稀有"] = 20;
        probability["传说"] = 10;
    }

    // 随机生成装备的品质
    std::string generateQuality();

    // 根据装备类型获取到装备工厂
    EquipmentFactory* getFactory(EquipmentType type);
};
