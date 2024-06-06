#include"equipment_tool.h"

// 随机生成装备
Equipment* EquipmentTool::generateEquipment(EquipmentType type) {
    std::string quality = generateQuality();
    EquipmentFactory* factory = getFactory(type);
    if (factory) {
        Equipment* equipment = factory->createEquipment(quality);
        if (equipment) {
            equipments.push_back(equipment);
        }
        delete factory;
        return equipment;
    }
    return nullptr;
}

// 批量随机生成装备
std::vector<Equipment*> EquipmentTool::generateEquipment(EquipmentType type, int quantity) {
    std::vector<Equipment*> newEquipments;
    EquipmentFactory* factory = getFactory(type);

    if (factory) {
        for (int i = 0; i < quantity; ++i) {
            std::string quality = generateQuality();
            Equipment* equipment = factory->createEquipment(quality);
            if (equipment) {
                equipments.push_back(equipment);
                newEquipments.push_back(equipment);
            }
        }
        delete factory;
    }

    return newEquipments;
}

// 删除装备
void EquipmentTool::removeEquipment(Equipment* equipment) {
    auto it = std::find(equipments.begin(), equipments.end(), equipment);
    if (it != equipments.end()) {
        equipments.erase(it);
    }
}

// 随机生成装备的品质
std::string EquipmentTool::generateQuality() {
    int total = 0;
    for (const auto& p : probability) {
        total += p.second;
    }

    int rand = std::rand() % total;
    int cumulative = 0;
    for (const auto& p : probability) {
        cumulative += p.second;
        if (rand < cumulative) {
            return p.first;
        }
    }
    return "普通";
}

// 根据装备类型获取到装备工厂
EquipmentFactory* EquipmentTool::getFactory(EquipmentType type) {
    switch (type) {
    case EquipmentType::Weapon:
        return new WeaponFactory();
    case EquipmentType::Armor:
        return new ArmorFactory();
    case EquipmentType::Accessory:
        return new AccessoryFactory();
    default:
        return nullptr;
    }
}