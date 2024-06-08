#pragma once
#include "monster.h"

class Vampire : public Monster
{
public:
    Vampire(int _level = 0, Attr _attr = Attr(), std::string _name = "Vampire", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 15 + 3 * _level + roll(3, 4);
        attr.agility = 18 + 4 * _level + roll(4, 4);
        attr.wisdom = 12 + 2 * _level;
        attr.maxHealth = roll(3, 20);
        attr.health = attr.maxHealth;
        attr.attack = 25 + 4 * _level + roll(3, 4);
        attr.block = 8 + 2 * _level + roll(2, 3);
        attr.defense = 20 + 5 * _level + roll(2, 3);
        attr.speed = 25 + 7 * _level + roll(2, 3);
        attr.hitRate = 85.0f;
        attr.missRate = 15.0f;
        attr.criticalAttackRate = 20.0f + 2 * _level;

        set_coin(15 + 5 * _level + roll(2, 4));
        set_attr(attr);

        // Vampires have a chance to carry medium rare gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 2, 2, 2, 4, 4, 4, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

