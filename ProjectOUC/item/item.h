#pragma once
#include <string>
#include<iostream>
#include "../attribute.h"

class Item {
protected:
    std::string name;
    std::string description;
    int space;        // ռ�ÿռ�

public:

    Item(const std::string& name, const std::string& description, int space)
        : name(name), description(description), space(space) {}
    virtual ~Item() = default;

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setDescription(const std::string& description) { this->description = description; }
    void setSpace(int space) { this->space = space; }

    // Getters
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getSpace() const { return space; }

    /*virtual void display() const {
        std::cout << "����: " << name << "������: " << description << "��ռ�ÿռ�: " << space << std::endl;
    }*/
    virtual Attr use() const = 0;

};

