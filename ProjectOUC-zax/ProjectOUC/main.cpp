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

#pragma comment(lib,"winmm.lib")//加载静态库

#pragma execution_character_set("utf-8")

int gadgetInHand;
bool moveConstraint;
const int fps = 60;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;
extern std::set<int> usefulGadgetSet;

window_type current_window_type = MAIN_WINDOW;
void BGM()//播放音乐
{
	mciSendString("open \\res\\UnicornTales(Master)9.wav alias BGM", 0, 0, 0);
	mciSendString("play BGM repeat", 0, 0, 0);
	if (0)
	{
		mciSendString("close BGM", 0, 0, 0);
	}
}
void pt_scene(std::vector<Scene*>& scenes, Player* player)
{
	cleardevice();
	int i, j;
	Position pos = player->get_pos();
	Scene* scene = scenes[pos.stage];
	if (pos.stage == 1)Cave_Wall_paint(scene, pos.stage);
	else if (pos.stage == 2)Maze_Wall_paint(scene, pos.stage);
	else if (pos.stage == 0)TOWN_Wall_paint(scene, pos.stage);
	for (i = 0; i <	scene->get_width(); ++i)
	{
		for (j = 0; j < scene->get_height(); ++j)
		{
			if(pos.stage==1)Cave_Empty_paint(i, j, scene, pos.stage);
			else if(pos.stage==2)Maze_Empty_paint(i, j, scene, pos.stage);
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
	std::vector<Scene*> scenes(3);
	bool loadGame = false;
	scenes[0] = new Scene("init/basic-town.txt");
	scenes[1] = new Scene("init/basic-cave.txt");
	scenes[2] = new Scene("init/basic-maze.txt");
	Loading_image();
	direction d[4] = { LEFT, RIGHT, UP, DOWN };
	int movePause = 0; //防止卡进墙里

	ExMessage msg;
	int begin = 1;
	int choice = 1;
	setbkcolor(WHITE);
	cleardevice();
	BGM();
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
				case 72://上键的虚拟值
				case 'W':
				case 'w':
				case VK_UP:
					player->move(UP);
					break;
				case 80://下键的虚拟值
				case 'S':
				case 's':
				case VK_DOWN:
					player->move(DOWN);
					break;
				case 75://左键的虚拟值
				case 'A':
				case 'a':
				case VK_LEFT:
					player->move(LEFT);
					break;
				case 77://右键的虚拟值
				case 'D':
				case 'd':
				case VK_RIGHT:
					player->move(RIGHT);
					break;
				case 'E':
				case 'e':
					gadgetInHand = (gadgetInHand + 1) % max_gadget_index;
					std::cout << gadgetList[gadgetInHand]->get_name() << " 当前拥有" << player->gadgets[gadgetInHand] << "个\n";
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
				std::cout << "你使用回城卷轴逃离了" << ((player->get_pos().stage == Scene::CAVE) ? "洞穴" : "迷宫") << "\n";
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