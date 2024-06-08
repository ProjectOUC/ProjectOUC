#pragma once
#include "monster.h"

class Dragon : public Monster
{
public:
    Dragon(int _level = 0, Attr _attr = Attr(), std::string _name = "Dragon", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 20 + 5 * _level + roll(4, 6);
        attr.agility = 12 + 3 * _level + roll(3, 4);
        attr.wisdom = 10 + 3 * _level;
        attr.maxHealth = roll(4, 30);
        attr.health = attr.maxHealth;
        attr.attack = 30 + 5 * _level + roll(4, 6);
        attr.block = 10 + 2 * _level + roll(2, 3);
        attr.defense = 30 + 10 * _level + roll(2, 4);
        attr.speed = 20 + 5 * _level + roll(2, 3);
        attr.hitRate = 80.0f;
        attr.missRate = 20.0f;
        attr.criticalAttackRate = 15.0f + 2 * _level;

        set_coin(20 + 10 * _level + roll(3, 6));
        set_attr(attr);

        // Dragons have a chance to carry rare gadgets
        if (oneIn(3))
        {
            static std::vector<int> weights{ 1, 1, 1, 5, 5, 5, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

