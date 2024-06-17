#pragma once
#ifndef _MONSTER_H
#define _MONSTER_H
#endif

#include "../character.h"
#include <iostream>

extern std::vector<Gadget*> gadgetList;

enum monster_type {
    SKULL,
    GOBLIN,
    SLIME,
    ORC,
    DRAGON,
    SKELETON,
    VAMPIRE,
    WITCH,
    GHOST,
    WEREWOLF,
    ZOMBIE,
    TROLL,
    MUMMY,
    HYDRA,
    GIANT,
    BASILISK,
    LICH,
    CYCLOPS,
    MINOTAUR,
    HARPY
};

class Monster : public Character
{
protected:
    monster_type type;

public:
    Monster(int _level = 0, Attr _attr = Attr(), std::string _name = "", int _coin = 0, Position _pos = Position(), bool _moved = false, monster_type _type = GOBLIN) :
        Character(_attr, _name, MONSTER, _coin, _pos, _moved), type(_type)
    {
        set_level(_level);
        set_exp(10 * _level + roll(2, 4));
    };

    Monster(const Monster& monster) :
        Character(monster), type(monster.type) {};

    Monster(std::string path, monster_type _type = GOBLIN) :
        Character(path), type(_type) {};

    virtual monster_type getType() const { return type; }
};

Monster getMonster(int level);

