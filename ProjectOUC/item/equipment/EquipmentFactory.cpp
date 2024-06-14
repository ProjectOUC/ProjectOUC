#include"equipment_factory.h"

// 武器工厂
Equipment* WeaponFactory::createEquipment(const std::string& quality)const {
	int idx = std::rand() % 3;
	if (idx == 0) {
		return createSword(quality);
	}
	else if (idx == 1) {
		return createLance(quality);
	}
	else if (idx == 2) {
		return createBow(quality);
	}
	return nullptr;
	
}	
Equipment* WeaponFactory::createSword(const std::string& quality)const {
	if (quality == "普通") {
		return new IronSword();
	}
	else if (quality == "稀有") {
		return new MithrilSword();
	}
	else if (quality == "传说") {
		return new BladeOfTheRuinedKing();
	}
	return nullptr;
}
Equipment* WeaponFactory::createLance(const std::string& quality)const {
	if (quality == "普通") {
		return new IronLance();
	}
	else if (quality == "稀有") {
		return new RedCrestedLance();
	}
	else if (quality == "传说") {
		return new DragonBoneLance();
	}
	return nullptr;
}
Equipment* WeaponFactory::createBow(const std::string& quality)const {
	if (quality == "普通") {
		return new LightBow();
	}
	else if (quality == "稀有") {
		return new StormBow();
	}
	else if (quality == "传说") {
		return new EndPoem();
	}
	return nullptr;
}

// 防具工厂
Equipment* ArmorFactory::createEquipment(const std::string& quality)const {

	if (quality == "普通") return new LeatherArmor();
	if (quality == "稀有") return new ChainmailArmor();
	if (quality == "传说") return new DragonScaleArmor();
	return nullptr;
}

// 饰品工厂
Equipment* AccessoryFactory::createEquipment(const std::string& quality)const {
	int idx = std::rand() % 2;
	if (idx == 0) {
		return createRing(quality);
	}
	else if (idx == 1) {
		return createAmulet(quality);
	}
	return nullptr;
}
Equipment* AccessoryFactory::createRing(const std::string& quality)const
{
	if (quality == "普通") {
		return new BronzeRing();
	}
	else if (quality == "稀有") {
		return new AmethystRing();
	}
	else if (quality == "传说") {
		return new  DragonRing();
	}
	return nullptr;
}
Equipment* AccessoryFactory::createAmulet(const std::string& quality)const
{
	if (quality == "普通") {
		return new BronzeAmulet();
	}
	else if (quality == "稀有") {
		return new JadeAmulet();
	}
	else if (quality == "传说") {
		return new  MysticalAmulet();
	}
	return nullptr;
}
