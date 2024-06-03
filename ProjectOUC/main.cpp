#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "roles/characters.h"
#include "gadgets/gadgets.h"
#include "scene.h"
#include "paint.h"
#include "gaming.h"

#define WIDTH 800
#define HEIGHT 600

#pragma comment(lib,"Winmm.lib")//º”‘ÿæ≤Ã¨ø‚

#pragma execution_character_set("utf-8")

int gadgetInHand;
bool moveConstraint;
const int fps = 60;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;
extern std::set<int> usefulGadgetSet;

window_type current_window_type = MAIN_WINDOW;
void pt_scene(std::vector<Scene*>& scenes, Player* player)
{
	cleardevice();
	int i, j;
	Position pos = player->get_pos();
	Scene* scene = scenes[pos.stage];
	if (scene->get_scene_type() == Scene::CAVE)Cave_Wall_paint(scene, 1);
	else if (scene->get_scene_type() == Scene::MAZE)Maze_Wall_paint(scene, pos.stage);
	else if (scene->get_scene_type() == Scene::TOWN)TOWN_Wall_paint(scene, pos.stage);
	for (i = 0; i <	scene->get_width(); ++i)
	{
		for (j = 0; j < scene->get_height(); ++j)
		{
			if(scene->get_scene_type() == Scene::CAVE)Cave_Empty_paint(i, j, scene, pos.stage);
			else if(scene->get_scene_type() == Scene::MAZE)Maze_Empty_paint(i, j, scene, pos.stage);
			else Cave_Empty_paint(i, j, scene, pos.stage);

			Tile* tile = scene->get_tiles(i, j);
			if (tile->get_type() == BATTLE_TILE) Monster_paint(i, j);
			else if (tile->get_type() == CHEST_TILE) Chest_paint(i, j);
			else if (i == pos.x && j == pos.y)
			{
				if(player->get_name()== "Rogue")
					Player_paint(i, j,2);
				else 
					Player_paint(i, j,1);
			}	
			else if (tile->get_type() == START_TILE) Start_paint(i, j);
			else if (tile->get_type() == END_TILE) End_paint(i,j);
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
	Player* player=getPlayer(random(1,2));
	std::vector<Scene*> scenes(5);
	bool loadGame = false;
	scenes[0] = new Scene("init/basic-town.txt", 0);
	scenes[1] = new Scene("init/basic-cave.txt", 1);
	scenes[2] = new Scene("init/basic-cave.txt", 2);
	scenes[3] = new Scene("init/basic-maze.txt", 3);
	scenes[4] = new Scene("init/basic-maze.txt", 4);
	Loading_image();
	direction d[4] = { LEFT, RIGHT, UP, DOWN };
	int movePause = 0; //∑¿÷πø®Ω¯«Ω¿Ô

	ExMessage msg;
	int begin = 1;
	int choice = 1;
	int item = 1;
	setbkcolor(WHITE);
	cleardevice();
	mciSendString("open res/UnicornTales(Master)9.wav alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat from 0", NULL, 0, NULL);
	while (begin)
	{
		
		BeginBatchDraw();
		start_paint(WIDTH, HEIGHT);
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 + 100 && msg.y >= HEIGHT / 3 - 50 && msg.y <= HEIGHT / 3 + 50)
				{
					begin = 0;
					break;
				}
				else if (msg.x >= WIDTH / 2 - 100 && msg.x <= WIDTH / 2 + 100 && msg.y >= (HEIGHT / 3) * 2 - 50 && msg.y <= (HEIGHT / 3) * 2 + 50)
				{
					return 0;
					break;
				}
			default:
				break;
			}
		}
		EndBatchDraw();
	}
	cleardevice();
	while (choice)
	{
		Player_choice(WIDTH, HEIGHT);
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= WIDTH / 3 - 8 && msg.x <= WIDTH / 3 + 8 && msg.y >= HEIGHT/2 - 8 && msg.y <= HEIGHT / 2 + 8)
				{
					player = getPlayer(1);
					choice=0;
					break;
				}
				else if (msg.x >= (WIDTH / 3)*2 - 8 && msg.x <= (WIDTH / 3)*2 + 8 && msg.y >= HEIGHT / 2 - 8 && msg.y <= HEIGHT / 2 + 8)
				{
					player = getPlayer(2);
					choice = 0;
					break;
				}
			default:
				break;
			}
		}
	}

	player->moveTo(scenes[0]->get_startPos());
	player->gadgets[findGadget("TeleportScroll")]++;
	while (running)
	{
		movePause = max(movePause-1, 0);
		DWORD start_time = GetTickCount();

		BeginBatchDraw();

		pt_scene(scenes, player);
		Message_paint();
		GUI_paint(scenes,player);

		//Player_paint(scene);
		

		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if (movePause) continue;
				movePause = 2;
				switch (msg.ch)
				{
				case 72://…œº¸µƒ–Èƒ‚÷µ
				case 'W':
				case 'w':
				case VK_UP:
					player->move(UP);
					break;
				case 80://œ¬º¸µƒ–Èƒ‚÷µ
				case 'S':
				case 's':
				case VK_DOWN:
					player->move(DOWN);
					break;
				case 75://◊Ûº¸µƒ–Èƒ‚÷µ
				case 'A':
				case 'a':
				case VK_LEFT:
					player->move(LEFT);
					break;
				case 77://”“º¸µƒ–Èƒ‚÷µ
				case 'D':
				case 'd':
				case VK_RIGHT:
					player->move(RIGHT);
					break;
				case 'E':
				case 'e':
					while(item)
					{
						int type;
						item_paint();
						for (int index=0 ; index < max_gadget_index; index++)
						{
							gadgets_paint(index,player->gadgets[index]);
						}
						FlushBatchDraw();
						while (peekmessage(&msg))
						{
							if (msg.message == WM_KEYDOWN)
							{
								switch (msg.ch)
								{
									case 'E':
									case 'e':
										item = 0;
										break;
									default:
										break;
								}
							}
						}
					}
					item = 1;
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
		FlushBatchDraw();
		checkTile(scenes, player);

		if (player->dead())
		{
			int ind = findGadget("TeleportScroll");
			if (player->gadgets[ind] != 0)
			{
				std::cout << "ƒ„ π”√ªÿ≥«æÌ÷·Ã”¿Î¡À" << ((player->get_pos().stage == Scene::CAVE) ? "∂¥—®" : "√‘π¨") << "\n";
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
	EndBatchDraw();
	getchar();
	closegraph();
	//
	return 0;
}