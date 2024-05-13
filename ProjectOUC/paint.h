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
void Player_paint(Scene& scene);
void Money_paint(Scene& scene);
void chest_paint(Scene& scene);
void monster_paint(Scene& scene);
void Health_paint(Scene& scene);
void paint_heart(Scene& scene);