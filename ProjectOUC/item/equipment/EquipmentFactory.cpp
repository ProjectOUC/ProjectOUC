#include"equipment_factory.h"

// ��������
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
	if (quality == "��ͨ") {
		return new IronSword();
	}
	else if (quality == "ϡ��") {
		return new MithrilSword();
	}
	else if (quality == "��˵") {
		return new BladeOfTheRuinedKing();
	}
	return nullptr;
}
Equipment* WeaponFactory::createLance(const std::string& quality)const {
	if (quality == "��ͨ") {
		return new IronLance();
	}
	else if (quality == "ϡ��") {
		return new RedCrestedLance();
	}
	else if (quality == "��˵") {
		return new DragonBoneLance();
	}
	return nullptr;
}
Equipment* WeaponFactory::createBow(const std::string& quality)const {
	if (quality == "��ͨ") {
		return new LightBow();
	}
	else if (quality == "ϡ��") {
		return new StormBow();
	}
	else if (quality == "��˵") {
		return new EndPoem();
	}
	return nullptr;
}

// ���߹���
Equipment* ArmorFactory::createEquipment(const std::string& quality)const {

	if (quality == "��ͨ") return new LeatherArmor();
	if (quality == "ϡ��") return new ChainmailArmor();
	if (quality == "��˵") return new DragonScaleArmor();
	return nullptr;
}

// ��Ʒ����
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
	if (quality == "��ͨ") {
		return new BronzeRing();
	}
	else if (quality == "ϡ��") {
		return new AmethystRing();
	}
	else if (quality == "��˵") {
		return new  DragonRing();
	}
	return nullptr;
}
Equipment* AccessoryFactory::createAmulet(const std::string& quality)const
{
	if (quality == "��ͨ") {
		return new BronzeAmulet();
	}
	else if (quality == "ϡ��") {
		return new JadeAmulet();
	}
	else if (quality == "��˵") {
		return new  MysticalAmulet();
	}
	return nullptr;
}
