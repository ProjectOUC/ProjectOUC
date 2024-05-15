#include <iostream>
#include<conio.h>
#include "graphics.h"
#include "chest.h"
#include "gadget.h"
#include "monster.h"
#include "player.h"
#include "scene.h"
#include "paint.h"
#include "PCG.h"

#define WIDTH 800
#define HEIGHT 600

#pragma execution_character_set("utf-8")

int gadgetInHand;
bool moveConstraint;
const int fps = 60;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;
extern std::set<int> usefulGadgetSet;

window_type current_window_type = MAIN_WINDOW;

int main()
{
	srand(time(0u));
	SetConsoleOutputCP(CP_UTF8);
	caveGenerate(30, 30, 6, 45, 0.6);
	//mazeGenerate(20, 20, 50, 1, 4, 5, 0);
	return 0;

	bool running = true;
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);
	//initgraph(GAME_WIDTH, GAME_HEIGHT);
	//SwitchToWindow(current_window_type);
	
	initGadgetList();
	Scene scene;
	Paint paint(WIDTH, HEIGHT);
	
	direction d[4] = { LEFT, RIGHT, UP, DOWN };

	while (running)
	{
		DWORD start_time = GetTickCount();
		BeginBatchDraw();
		Map_paint(WIDTH, HEIGHT);
		monster_paint(scene);
		chest_paint(scene);
		Money_paint(scene);
		paint_heart(scene);
		//std::cout << "当前位置: " << scene.get_player_pos_x() << " " << scene.get_player_pos_y() << "\n";
		//std::cout << "生命值: " << scene.get_player()->get_health() << " 攻击: "
		//	<< scene.get_player()->get_attack() << " 防御: " << scene.get_player()->get_defense() << "\n";

		Player_paint(scene);
		EndBatchDraw();
		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.ch)
				{
				case 72://上键的虚拟值
				case 'W':
				case 'w':
					scene.move(UP);
					break;
				case 80://下键的虚拟值
				case 'S':
				case 's':
					scene.move(DOWN);
					break;
				case 75://左键的虚拟值
				case 'A':
				case 'a':
					scene.move(LEFT);
					break;
				case 77://右键的虚拟值
				case 'D':
				case 'd':
					scene.move(RIGHT);
					break;
				case 'E':
				case 'e':
					while (!usefulGadgetSet.count(gadgetInHand)) gadgetInHand = (gadgetInHand + 1) % max_gadget_index;
					std::cout << gadgetList[gadgetInHand]->get_name() << " 当前拥有" << scene.get_player()->gadgets[gadgetInHand] << "个\n";
					break;
				case 'R':
				case 'r':
					scene.get_player()->use_gadget();
					break;
				}
			}
		}
		
		if (!scene.checkTile())
		{
			Gameover_paint(WIDTH, HEIGHT);
			destroyGadgetList();
			break;
		}

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / fps)
		{
			Sleep(1000 / fps - delta_time);
		}
	}

	getchar();
	closegraph();
	return 0;
}