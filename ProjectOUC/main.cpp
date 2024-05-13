#include <iostream>
#include<conio.h>
#include "graphics.h"
#include "chest.h"
#include "gadget.h"
#include "monster.h"
#include "player.h"
#include "scene.h"
#include "paint.h"
#define WIDTH 800
#define HEIGHT 600

#pragma execution_character_set("utf-8")

window_type current_window_type = MAIN_WINDOW;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	bool running = true;
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);
	//initgraph(GAME_WIDTH, GAME_HEIGHT);
	//SwitchToWindow(current_window_type);
	
	Scene scene;
	Paint paint(WIDTH, HEIGHT);
	
	direction d[4] = { LEFT, RIGHT, UP, DOWN };

	while (running)
	{
		BeginBatchDraw();
		Map_paint(WIDTH, HEIGHT);
		monster_paint(scene);
		chest_paint(scene);
		Money_paint(scene);
		paint_heart(scene);
		std::cout << "当前位置: " << scene.get_player_pos_x() << " " << scene.get_player_pos_y() << "\n";
		std::cout << "生命值: " << scene.get_player()->get_health() << "\n";

		Player_paint(scene);
		EndBatchDraw();
		char key = _getch();
		switch (key)
		{
		case 72://上键的虚拟值
		case 'W':
		case 'w':
			scene.move(UP);;
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
		}
		if (!scene.checkTile())
		{
			Gameover_paint(WIDTH, HEIGHT);
			break;
		}
	}

	getchar();
	closegraph();
	return 0;
}