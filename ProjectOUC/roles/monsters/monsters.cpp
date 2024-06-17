#include "monsters.h"

std::unique_ptr<Monster> getMonster(int level, monster_type type) {
    switch (type) {
    case SKULL:return std::make_unique<Skull>(level);
    case GOBLIN: return std::make_unique<Goblin>(level);
    case SLIME: return std::make_unique<Slime>(level);
    case ORC: return std::make_unique<Orc>(level);
    case DRAGON: return std::make_unique<Dragon>(level);
    case SKELETON: return std::make_unique<Skeleton>(level);
    case VAMPIRE: return std::make_unique<Vampire>(level);
    case WITCH: return std::make_unique<Witch>(level);
    case GHOST: return std::make_unique<Ghost>(level);
    case WEREWOLF: return std::make_unique<Werewolf>(level);
    case ZOMBIE: return std::make_unique<Zombie>(level);
    case TROLL: return std::make_unique<Troll>(level);
    case MUMMY: return std::make_unique<Mummy>(level);
    case HYDRA: return std::make_unique<Hydra>(level);
    case GIANT: return std::make_unique<Giant>(level);
    case BASILISK: return std::make_unique<Basilisk>(level);
    case LICH: return std::make_unique<Lich>(level);
    case CYCLOPS: return std::make_unique<Cyclops>(level);
    case MINOTAUR: return std::make_unique<Minotaur>(level);
    case HARPY: return std::make_unique<Harpy>(level);
    default: return nullptr;
    }
}
