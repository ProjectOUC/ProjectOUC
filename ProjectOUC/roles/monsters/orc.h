#pragma once
#include "monster.h"

class Orc : public Monster
{
public:
    Orc(int _level = 0, Attr _attr = Attr(), std::string _name = "Orc", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 18 + 4 * _level + roll(3, 5);
        attr.agility = 8 + 2 * _level + roll(2, 3);
        attr.wisdom = 6 + 1 * _level;
        attr.maxHealth = roll(3, 25);
        attr.health = attr.maxHealth;
        attr.attack = 28 + 5 * _level + roll(3, 5);
        attr.block = 12 + 3 * _level + roll(2, 4);
        attr.defense = 25 + 8 * _level + roll(2, 4);
        attr.speed = 15 + 4 * _level + roll(2, 2);
        attr.hitRate = 75.0f;
        attr.missRate = 25.0f;
        attr.criticalAttackRate = 10.0f + 2 * _level;

        set_coin(10 + 4 * _level + roll(2, 3));
        set_attr(attr);

        // Orcs have a chance to carry common gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 4, 3, 3, 2, 2, 1, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

