#include"backpack.h"

bool Backpack::addItem(Item* item) {
    if (curCapacity + item->getSpace() <= capacity) {
        items.push_back(item);
        curCapacity += item->getSpace();
        return true;
    }
    std::cout << "背包已满，无法添加更多物品。" << std::endl;
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
        std::cout << "物品不在背包中。" << std::endl;
    }
}

void Backpack::displayContents() const {
    if (items.empty()) {
        std::cout << "背包是空的。" << std::endl;
    }
    else {
        std::cout << "背包内容：" << std::endl;
        for (const auto& item : items) {
            /*item->display();*/
        }
    }
}

// 增加当前容量
void Backpack::incCurCapacity(size_t amount) {
    if (curCapacity + amount <= capacity) {
        curCapacity += amount;
    }
    else {
        std::cout << "无法增加容量，超过最大容量限制。" << std::endl;
    }
}

// 减少当前容量
void Backpack::decCurCapacity(size_t amount) {
    if (curCapacity >= amount) {
        curCapacity -= amount;
    }
    else {
        std::cout << "无法减少容量，当前容量不足。" << std::endl;
    }
}