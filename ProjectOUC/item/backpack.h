#pragma once
#include <vector>
#include "Item.h"

class Backpack {
private:
    size_t capacity;     // 最大容量
    size_t curCapacity;  // 当前容量
    std::vector<Item*> items;

public:
    Backpack(size_t capacity) : capacity(capacity), curCapacity(capacity) {}
    ~Backpack() {
        for (auto item : items) {
            delete item;
        }
    }

    // 向背包中添加物品
    bool addItem(Item* item);
    // 从背包中移除物品
    void removeItem(Item* item);
    // 显示背包中元素
    void displayContents() const;

    void incCurCapacity(size_t amount);
    void decCurCapacity(size_t amount);
    size_t getCurCapacity() const {
        return curCapacity;
    }
    void setCapacity(size_t newCapacity) {
        capacity = newCapacity;
    }
    size_t getCapacity() const {
        return capacity;
    }

};
