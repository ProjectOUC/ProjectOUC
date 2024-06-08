#pragma once
#include "monster.h"

class Skeleton : public Monster
{
public:
    Skeleton(int _level = 0, Attr _attr = Attr(), std::string _name = "Skeleton", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 12 + 3 * _level + roll(3, 4);
        attr.agility = 10 + 2 * _level + roll(2, 3);
        attr.wisdom = 8 + 2 * _level;
        attr.maxHealth = roll(2, 15);
        attr.health = attr.maxHealth;
        attr.attack = 22 + 4 * _level + roll(2, 4);
        attr.block = 8 + 2 * _level + roll(1, 3);
        attr.defense = 20 + 5 * _level + roll(2, 4);
        attr.speed = 18 + 5 * _level + roll(2, 2);
        attr.hitRate = 80.0f;
        attr.missRate = 20.0f;
        attr.criticalAttackRate = 10.0f + 2 * _level;

        set_coin(10 + 5 * _level + roll(2, 3));
        set_attr(attr);

        // Skeletons have a chance to carry common gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 4, 3, 3, 2, 2, 1, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

