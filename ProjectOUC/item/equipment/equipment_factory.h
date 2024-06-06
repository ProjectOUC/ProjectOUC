#pragma once
#include "equipment.h"
#include "weapon/sword.h"
#include "weapon/lance.h"
#include "weapon/bow.h"
#include "armor/armor.h"
#include "accessory/ring.h"
#include "accessory/amulet.h"

class EquipmentFactory {
public:
    virtual Equipment* createEquipment(const std::string& quality) const = 0;
};

class WeaponFactory : public EquipmentFactory {
public:
    WeaponFactory() {
        std::srand(std::time(nullptr));
    }

    Equipment* createEquipment(const std::string& quality) const override;
private:
    Equipment* createSword(const std::string& quality) const;
    Equipment* createLance(const std::string& quality) const;
    Equipment* createBow(const std::string& quality) const;
};

class ArmorFactory : public EquipmentFactory {
public:
    Equipment* createEquipment(const std::string& quality) const override;
};

class AccessoryFactory : public EquipmentFactory {
public:
    Equipment* createEquipment(const std::string& quality) const override;
private:
    Equipment* createRing(const std::string& quality) const;
    Equipment* createAmulet(const std::string& quality) const;
};
