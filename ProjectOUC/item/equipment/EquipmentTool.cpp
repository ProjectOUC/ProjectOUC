#include"equipment_tool.h"

// �������װ��
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

// �����������װ��
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

// ɾ��װ��
void EquipmentTool::removeEquipment(Equipment* equipment) {
    auto it = std::find(equipments.begin(), equipments.end(), equipment);
    if (it != equipments.end()) {
        equipments.erase(it);
    }
}

// �������װ����Ʒ��
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
    return "��ͨ";
}

// ����װ�����ͻ�ȡ��װ������
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