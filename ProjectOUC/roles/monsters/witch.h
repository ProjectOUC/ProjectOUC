#pragma once
#include "monster.h"

class Witch : public Monster
{
public:
    Witch(int _level = 0, Attr _attr = Attr(), std::string _name = "Witch", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 10 + 2 * _level + roll(2, 4);
        attr.agility = 14 + 3 * _level + roll(3, 3);
        attr.wisdom = 20 + 5 * _level;
        attr.maxHealth = roll(2, 15);
        attr.health = attr.maxHealth;
        attr.attack = 20 + 3 * _level + roll(2, 4);
        attr.block = 5 + 1 * _level + roll(1, 2);
        attr.defense = 15 + 5 * _level + roll(2, 3);
        attr.speed = 20 + 5 * _level + roll(2, 3);
        attr.hitRate = 90.0f;
        attr.missRate = 10.0f;
        attr.criticalAttackRate = 25.0f + 3 * _level;

        set_coin(20 + 8 * _level + roll(2, 5));
        set_attr(attr);

        // Witches have a chance to carry rare gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 2, 2, 1, 1, 1, 5, 4 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

