#pragma once
#include "monster.h"

class Ghost : public Monster
{
public:
    Ghost(int _level = 0, Attr _attr = Attr(), std::string _name = "Ghost", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 10 + 2 * _level + roll(2, 3);
        attr.agility = 5 + 5 * _level + roll(4, 5);
        attr.wisdom = 5 + 4 * _level;
        attr.maxHealth = roll(2, 20);
        attr.health = attr.maxHealth;
        attr.attack = 20 + 4 * _level + roll(2, 3);
        attr.block = 5 + 1 * _level + roll(1, 2);
        attr.defense = 15 + 4 * _level + roll(2, 3);
        attr.speed = 30 + 8 * _level + roll(3, 4);
        attr.hitRate = 90.0f;
        attr.missRate = 10.0f;
        attr.criticalAttackRate = 25.0f + 3 * _level;

        set_coin(15 + 5 * _level + roll(2, 4));
        set_attr(attr);

        // Phantoms have a chance to carry rare gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 2, 2, 2, 3, 3, 4, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

