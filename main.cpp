#include <iostream>

#include "graphics.h"
#include "chest.h"
#include "gadget.h"
#include "monster.h"
#include "player.h"
#include "scene.h"

#pragma execution_character_set("utf-8")

window_type current_window_type = MAIN_WINDOW;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	bool running = true;
	//initgraph(GAME_WIDTH, GAME_HEIGHT);
	//SwitchToWindow(current_window_type);
	
	Scene scene;

	direction d[4] = { LEFT, RIGHT, UP, DOWN };

	while (running)
	{
		std::cout << "当前位置: " << scene.get_player_pos_x() << " " << scene.get_player_pos_y() << "\n";
		std::cout << "生命值: " << scene.get_player().get_health() << "\n";
		srand(time(0));
		scene.move(d[rand() % 4]);
		if (!scene.checkTile()) break;
		Sleep(1000);
	}
	//closegraph();
	return 0;
}