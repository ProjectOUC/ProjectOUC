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

    // �������װ��
    Equipment* generateEquipment(EquipmentType type);
    // �����������װ��
    std::vector<Equipment*> generateEquipment(EquipmentType type, int quantity);
    // ɾ��װ��
    void removeEquipment(Equipment* equipment);
    // ��ȡװ���б�
    const std::vector<Equipment*>& getEquipments() const {
        return equipments;
    }

private:
    std::vector<Equipment*> equipments;
    std::map<std::string, int> probability;

    void initProbability() {
        // ��ʼ����ͬƷ��װ���ĸ���
        probability["��ͨ"] = 70;
        probability["ϡ��"] = 20;
        probability["��˵"] = 10;
    }

    // �������װ����Ʒ��
    std::string generateQuality();

    // ����װ�����ͻ�ȡ��װ������
    EquipmentFactory* getFactory(EquipmentType type);
};
