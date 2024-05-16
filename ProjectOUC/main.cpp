#include <iostream>
#include <conio.h>
#include "graphics.h"
#include "chest.h"
#include "gadgets/gadgets.h"
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

void pt(Scene& scene)
{
	setbkcolor(WHITE);
	cleardevice();
	int x1, y1, x2, y2;
	int px = scene.get_player_pos_x(), py = scene.get_player_pos_y();
	x1 = max(px - 2, 0);
	y1 = max(py - 2, 0);
	x2 = min(px + 2, scene.get_width() - 1);
	y2 = min(py + 2, scene.get_height() - 1);

	for (int x = x1; x <= x2; ++x)
	{
		for (int y = y1; y <= y2; ++y)
		{
			Tile* tile = scene.get_tiles(x, y);
			rectangle(100 * (x - x1 + 1), 100 * (y - y1 + 1), 100 * (x - x1 + 2), 100 * (y - y1 + 2));
			if (tile->get_type() == EMPTY_TILE) continue;
			if (tile->get_type() == BATTLE_TILE) setfillcolor(RED);
			else if (tile->get_type() == CHEST_TILE) setfillcolor(GREEN);
			else if (tile->get_type() == WALL_TILE) setfillcolor(BLACK);
			fillrectangle(20 + 100 * (x - x1 + 1), 20 + 100 * (y - y1 + 1), 100 * (x - x1 + 2) - 20, 100 * (y - y1 + 2) - 20);
		}
	}
	setfillcolor(BLUE);
	fillrectangle(20 + 100 * (px - x1 + 1), 20 + 100 * (py - y1 + 1), 100 * (px - x1 + 2) - 20, 100 * (py - y1 + 2) - 20);
}

int main()
{
	srand(time(nullptr));
	SetConsoleOutputCP(CP_UTF8);
	//caveGenerate(30, 30, 6, 45, 0.6);
	//mazeGenerate(30, 30, 60, 1, 4, 5, 80, 0.5);

	bool running = true;
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);
	//initgraph(GAME_WIDTH, GAME_HEIGHT);
	//SwitchToWindow(current_window_type);
	
	initGadgetList();
	Scene scene(mazeGenerate(10, 10, 10, 1, 3, 5, 80, 0.5), Scene::MAZE);
	Paint paint(WIDTH, HEIGHT);
	
	direction d[4] = { LEFT, RIGHT, UP, DOWN };

	while (running)
	{
		DWORD start_time = GetTickCount();
		BeginBatchDraw();
		//Map_paint(WIDTH, HEIGHT);
		//setbkcolor(WHITE);
		//cleardevice();
		//monster_paint(scene);
		//chest_paint(scene);
		Money_paint(scene);
		paint_heart(scene);
		//paint_wall(scene);
		pt(scene);
		//std::cout << "当前位置: " << scene.get_player_pos_x() << " " << scene.get_player_pos_y() << "\n";
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