#pragma once
#include "scene.h"
#include "roles/character.h"
#include "gadgets/gadgets.h"
#include "event/event.h"

#include <iostream>
#include <vector>

void checkTile(std::vector<Scene*>& scenes, Player* player);

void saveGame(std::vector<Scene*>& scenes, Player* player, bool autoSave = true);

void loadGame(int saveIndex, std::vector<Scene*>& scenes, Player** player);

bool canSee(int x1, int y1, int x2, int y2, Scene* scene);

bool canPredict(int x, int y, Scene* scene);

void updateLight(std::vector<Scene*>& scenes, Player* player);

void randomEvent(Player** player);