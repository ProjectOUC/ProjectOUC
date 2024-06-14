#pragma once
#include <vector>
#include "Item.h"

class Backpack {
private:
    size_t capacity;     // �������
    size_t curCapacity;  // ��ǰ����
    std::vector<Item*> items;

public:
    Backpack(size_t capacity) : capacity(capacity), curCapacity(capacity) {}
    ~Backpack() {
        for (auto item : items) {
            delete item;
        }
    }

    // �򱳰��������Ʒ
    bool addItem(Item* item);
    // �ӱ������Ƴ���Ʒ
    void removeItem(Item* item);
    // ��ʾ������Ԫ��
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
