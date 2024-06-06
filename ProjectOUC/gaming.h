#pragma once
#include "scene.h"
#include "roles/character.h"
#include "gadgets/gadgets.h"

#include <iostream>
#include <vector>

void checkTile(std::vector<Scene*>& scenes, Player* player);

void saveGame(std::vector<Scene*>& scenes, Player* player, bool autoSave = true);

void loadGame(int saveIndex, std::vector<Scene*>& scenes, Player** player);