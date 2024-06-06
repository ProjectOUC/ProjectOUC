#include"backpack.h"

bool Backpack::addItem(Item* item) {
    if (curCapacity + item->getSpace() <= capacity) {
        items.push_back(item);
        curCapacity += item->getSpace();
        return true;
    }
    std::cout << "�����������޷���Ӹ�����Ʒ��" << std::endl;
    return false;
}

void Backpack::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        curCapacity -= item->getSpace();
        delete* it;
        items.erase(it);
    }
    else {
        std::cout << "��Ʒ���ڱ����С�" << std::endl;
    }
}

void Backpack::displayContents() const {
    if (items.empty()) {
        std::cout << "�����ǿյġ�" << std::endl;
    }
    else {
        std::cout << "�������ݣ�" << std::endl;
        for (const auto& item : items) {
            /*item->display();*/
        }
    }
}

// ���ӵ�ǰ����
void Backpack::incCurCapacity(size_t amount) {
    if (curCapacity + amount <= capacity) {
        curCapacity += amount;
    }
    else {
        std::cout << "�޷�������������������������ơ�" << std::endl;
    }
}

// ���ٵ�ǰ����
void Backpack::decCurCapacity(size_t amount) {
    if (curCapacity >= amount) {
        curCapacity -= amount;
    }
    else {
        std::cout << "�޷�������������ǰ�������㡣" << std::endl;
    }
}