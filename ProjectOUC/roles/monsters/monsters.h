#pragma once

#include "monster.h"
#include "skull.h"
#include "goblin.h"
#include "slime.h"
#include "orc.h"
#include "dragon.h"
#include "ghost.h"
#include "skeleton.h"
#include "vampire.h"
#include "werewolf.h"
#include "witch.h"
#include "zombie.h"
#include "troll.h"
#include "mummy.h"
#include "hydra.h"
#include "giant.h"
#include "basilisk.h"
#include "lich.h"
#include "cyclops.h"
#include "minotaur.h"
#include "harpy.h"

std::unique_ptr<Monster> getMonster(int level, monster_type type);