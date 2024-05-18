#include <iostream>
#include <conio.h>
#include "graphics.h"
#include "roles/characters.h"
#include "gadgets/gadgets.h"
#include "scene.h"
#include "paint.h"
#include "gaming.h"

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

void pt(std::vector<Scene*>& scenes, Player* player)
{
	cleardevice();
	Position pos = player->get_pos();
	Scene* scene = scenes[pos.stage];
	for (int i = 0; i < scene->get_width(); ++i)
	{
		for (int j = 0; j < scene->get_height(); ++j)
		{
			Tile* tile = scene->get_tiles(i, j);
			if (tile->get_type() == BATTLE_TILE) setfillcolor(RED);
			else if (tile->get_type() == CHEST_TILE) setfillcolor(GREEN);
			else if (i == pos.x && j == pos.y) setfillcolor(BLUE);
			else if (tile->get_type() == WALL_TILE) setfillcolor(BLACK);
			else if (tile->get_type() == START_TILE) setfillcolor(YELLOW);
			else if (tile->get_type() == END_TILE) setfillcolor(BROWN);
			else if (tile->get_type() == EMPTY_TILE) setfillcolor(WHITE);
			fillrectangle(100 + 15 * i, 100 + 15 * j, 100 + 15 * i + 14, 100 + 15 * j + 14);
		}
	}
}

int main()
{
	srand(time(nullptr));
	SetConsoleOutputCP(CP_UTF8);

	bool running = true;
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);
	//initgraph(GAME_WIDTH, GAME_HEIGHT);
	//SwitchToWindow(current_window_type);
	
	initGadgetList();
	Player* player = getPlayer(random(1, 2));
	std::vector<Scene*> scenes(3);
	bool loadGame = false;
	scenes[0] = new Scene("init/basic-town.txt");
	scenes[1] = new Scene("init/basic-cave.txt");
	scenes[2] = new Scene("init/basic-maze.txt");
	player->moveTo(scenes[0]->get_startPos());
	player->gadgets[findGadget("TeleportScroll")]++;
	

	Paint paint(WIDTH, HEIGHT);
	
	direction d[4] = { LEFT, RIGHT, UP, DOWN };
	int movePause = 0; //��ֹ����ǽ��
	while (running)
	{
		movePause = max(movePause-1, 0);
		DWORD start_time = GetTickCount();

		BeginBatchDraw();
		//Map_paint(WIDTH, HEIGHT);
		//setbkcolor(WHITE);
		//cleardevice();
		//monster_paint(scene);
		//chest_paint(scene);
		Money_paint(player);
		paint_heart(player);
		//paint_wall(scene);
		pt(scenes, player);
		//Player_paint(scene);
		EndBatchDraw();

		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if (movePause) continue;
				movePause = 2;
				switch (msg.ch)
				{
				case 72://�ϼ�������ֵ
				case 'W':
				case 'w':
				case VK_UP:
					player->move(UP);
					break;
				case 80://�¼�������ֵ
				case 'S':
				case 's':
				case VK_DOWN:
					player->move(DOWN);
					break;
				case 75://���������ֵ
				case 'A':
				case 'a':
				case VK_LEFT:
					player->move(LEFT);
					break;
				case 77://�Ҽ�������ֵ
				case 'D':
				case 'd':
				case VK_RIGHT:
					player->move(RIGHT);
					break;
				case 'E':
				case 'e':
					gadgetInHand = (gadgetInHand + 1) % max_gadget_index;
					std::cout << gadgetList[gadgetInHand]->get_name() << " ��ǰӵ��" << player->gadgets[gadgetInHand] << "��\n";
					break;
				case 'R':
				case 'r':
					player->use_gadget();
					break;
				case VK_SPACE:
					player->modify_moved(true);
				}
			}
		}
		
		checkTile(scenes, player);

		if (player->dead())
		{
			int ind = findGadget("TeleportScroll");
			if (player->gadgets[ind] != 0)
			{
				std::cout << "��ʹ�ûسǾ���������" << ((player->get_pos().stage == Scene::CAVE) ? "��Ѩ" : "�Թ�") << "\n";
				gadgetInHand = ind;
				player->use_gadget();
				player->set_health(player->get_maxHealth());
			}
			else
			{
				delete player;
				destroyGadgetList();
				for (int i = 0; i < scenes.size(); ++i) delete scenes[i];
				Gameover_paint(WIDTH, HEIGHT);
				break;
			}
		}

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / fps)
		{
			Sleep(1000 / fps - delta_time);
		}
	}

	// Ending 
	
	getchar();
	closegraph();
	//
	return 0;
}