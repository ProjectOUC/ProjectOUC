#pragma once
#include "scene.h"
#include "roles/character.h"
<<<<<<< HEAD
#include "gadgets/gadgets.h"
=======
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d

#include <iostream>
#include <vector>

void checkTile(std::vector<Scene*>& scenes, Player* player);

<<<<<<< HEAD
void saveGame(std::vector<Scene*>& scenes, Player* player, bool autoSave = true);

void loadGame(int saveIndex, std::vector<Scene*>& scenes, Player** player);
=======
void saveGame(std::vector<Scene*>& scenes, Player* player);
>>>>>>> 2bcc77c05f7a479fed838f813342c8af50a3155d
