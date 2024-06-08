#pragma once
#include "monster.h"

class Werewolf : public Monster
{
public:
    Werewolf(int _level = 0, Attr _attr = Attr(), std::string _name = "Werewolf", int _coin = 0, Position _pos = Position(), bool _moved = false) :
        Monster(_level, _attr, _name, _coin, _pos, _moved)
    {
        Attr attr;
        attr.strength = 22 + 5 * _level + roll(4, 5);
        attr.agility = 18 + 4 * _level + roll(3, 4);
        attr.wisdom = 8 + 2 * _level;
        attr.maxHealth = roll(3, 30);
        attr.health = attr.maxHealth;
        attr.attack = 28 + 5 * _level + roll(4, 5);
        attr.block = 12 + 3 * _level + roll(2, 4);
        attr.defense = 25 + 8 * _level + roll(2, 4);
        attr.speed = 22 + 6 * _level + roll(3, 3);
        attr.hitRate = 85.0f;
        attr.missRate = 15.0f;
        attr.criticalAttackRate = 15.0f + 2 * _level;

        set_coin(20 + 8 * _level + roll(3, 5));
        set_attr(attr);

        // Werewolves have a chance to carry rare gadgets
        if (oneIn(4))
        {
            static std::vector<int> weights{ 2, 2, 2, 4, 4, 4, 3 };
            this->take_gadget(gadgetList[randIndByWeights(weights)]);
        }
    }
};

