#pragma once
#include"scene.h"
class Paint
{
public:
	Paint(int width, int height);
};

void Loading_image();
void GUI_paint(std::vector<Scene*>& scenes, Player* player);
void start_paint(int width, int height);
void Player_choice(int width, int height);
void Message_paint();
inline void putimage_alpha(int x, int y, IMAGE* img);
void Gameover_paint(int width,int height);
void Player_paint(int x, int y,int type);
void Chest_paint(int x,int y);
void Monster_paint(int x,int y);
void TOWN_Wall_paint(Scene* scene, int pos);
void speak_paint();
void item_paint();
void gadgets_paint(int index,int num);
void Cave_Wall_paint(Scene* scene,int pos);
void Maze_Wall_paint(Scene* scene, int pos);
void End_paint(int x, int y);
void Start_paint(int x, int y);
void Cave_Empty_paint(int x, int y, Scene* scene, int pos);
<<<<<<< Updated upstream
void Maze_Empty_paint(int x, int y, Scene* scene, int pos);
=======
void Maze_Empty_paint(int x, int y, Scene* scene, int pos);
void Town_scene_paint(int width, int height, Position pos);
void Button_paint(Event* event);
>>>>>>> Stashed changes
