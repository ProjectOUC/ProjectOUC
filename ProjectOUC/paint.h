#pragma once
#include"scene.h"
class Paint
{
public:
	Paint(int width, int height);
};

void transparentimage(int x, int y, IMAGE img);
void Map_paint(int width, int height);
void Gameover_paint(int width,int height);
void Player_paint(std::vector<Scene*> scenes, Player* player);
void Money_paint(Player* player);
void chest_paint(Scene& scene);
void monster_paint(Scene& scene);
void Health_paint(Player* player);
void paint_heart(Player* player);
void paint_wall(Scene& scene);