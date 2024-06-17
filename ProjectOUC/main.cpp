
#include "utils/converter.h"
#include <conio.h>
#include "roles/characters.h"
#include "gadgets/gadgets.h"
#include "utils/rect.h"
#include "scene.h"
#include "paint.h"
#include "gaming.h"

#define WIDTH 800
#define HEIGHT 600

#pragma comment(lib,"Winmm.lib")//加载静态库

#pragma execution_character_set("utf-8")

int gadgetInHand;
bool moveConstraint;
const int fps = 60;
extern const int max_gadget_index;
extern std::vector<Gadget*> gadgetList;

void pt_scene(std::vector<Scene*>& scenes, Player* player)
{
	static int loopCount = 0;
	static Position lastPos;
	static Position curPos;
	loopCount++;
	if (loopCount && loopCount % 10 != 1)
	{
		if (curPos == player->get_pos()) return;
		curPos = player->get_pos();
		if (lastPos == player->get_lastPos()) return;
		lastPos = player->get_lastPos();
		if (curPos == lastPos) return;
	}
	cleardevice();
	
	int i, j;
	Position pos = player->get_pos();
	Scene* scene = scenes[pos.stage];
	if (scene->get_scene_type() == Scene::CAVE)Cave_Wall_paint(scene, 1);
	else if (scene->get_scene_type() == Scene::MAZE)Maze_Wall_paint(scene, pos.stage);
	else if (scene->get_scene_type() == Scene::TOWN)
	{
		TOWN_Wall_paint(scene, pos.stage);
		Town_scene_paint(WIDTH, HEIGHT, pos);
	}
	for (i = 0; i <	scene->get_width(); ++i)
	{
		for (j = 0; j < scene->get_height(); ++j)
		{
			if(scene->get_scene_type() == Scene::CAVE)Cave_Empty_paint(i, j, scene, pos.stage);
			else if(scene->get_scene_type() == Scene::MAZE)Maze_Empty_paint(i, j, scene, pos.stage);

			Tile* tile = scene->get_tiles(i, j);
			if (tile->get_type() == BATTLE_TILE) {
				// 位置%怪物类型数量
				monster_type monster_type = tile->monsters[0]->getType();
				/*int monster_type = (i + j) % 10;*/
				Monster_paint(i, j, monster_type);
			}
			else if (tile->get_type() == CHEST_TILE) Chest_paint(i, j);
			else if (i == pos.x && j == pos.y)
			{
				if (player->get_name() == "Rogue")
					Player_paint(i, j, 2);
				else
					Player_paint(i, j, 1);
			}	
			else if (tile->get_type() == START_TILE) Start_paint(i, j);
			else if (tile->get_type() == END_TILE) End_paint(i,j);
		}
	}

	for (i = 0; i < scene->get_width(); ++i)
	{
		for (j = 0; j < scene->get_height(); ++j)
		{
			Tile* tile = scene->get_tiles(i, j);
			if (tile->event)
			{
				putimage_alpha(16 * i + 64, 16 * j + 64, &tile->event->img);
			}
		}
	}

	int vr = player->get_attr().visibleRadius;
	int lx = lastPos.x, ly = lastPos.y;
	int cx = curPos.x, cy = curPos.y;
	if (lastPos.stage != curPos.stage) lx = cx, ly = cy;
	setfillcolor(BLACK);
	//for (int i = max(0, min(lx, cx) - vr); i < min(max(lx, cx) + vr + 1, scene->get_width()); ++i)
	
	for (int i = 0; i < scene->get_width(); ++i)
	{
		//for (int j = max(0, min(ly, cy) - vr); j < min(max(ly, cy) + vr + 1, scene->get_height()); ++j)
		for (int j = 0; j < scene->get_height(); ++j)
		{
			if (!scene->visited[i][j]) fillrectangle(16 * i + 64, 16 * j + 64, 16 * i + 80, 16 * j + 80);
		}
	}

	//setfillcolor(YELLOW);
	//fillrectangle(16 * (cx+0.5) + 64, 16 * (cy+0.5) + 64, 16 * (cx+0.5) + 80, 16 * (cy+0.5) + 80);
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
	initTrapList();
	Player* player = nullptr;
	std::vector<Scene*> scenes(5);
	bool loadGame = false;
	scenes[0] = new Scene("init/basic-town.txt", 0);
	scenes[1] = new Scene("init/basic-cave.txt", 1);
	scenes[2] = new Scene("init/basic-cave.txt", 2);
	scenes[3] = new Scene("init/basic-maze.txt", 3);
	scenes[4] = new Scene("init/basic-maze.txt", 4);

	Loading_image();

	direction d[4] = { LEFT, RIGHT, UP, DOWN };
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
			if (Rect(HEIGHT / 3 - 50, WIDTH/2-100, HEIGHT / 3 + 50, WIDTH/2+100).include(msg.x, msg.y))
			{
				begin = 0;
				break;
			}
			else if (Rect(HEIGHT / 3 * 2 - 50, WIDTH / 2 - 100, HEIGHT / 3 * 2 + 50, WIDTH / 2 + 100).include(msg.x, msg.y))
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
				if (Rect(WIDTH / 5 + 80, HEIGHT / 2 - 60, WIDTH / 5 + 320, HEIGHT / 2 + 100).include(msg.x, msg.y))
				{
					player = getPlayer(1);
					choice = 0;
					break;
				}
				else if (Rect(WIDTH / 5 + 80, HEIGHT / 2 + 140, WIDTH / 5 + 320, HEIGHT / 2 + 300).include(msg.x, msg.y))
				{
					player = getPlayer(2);
					choice = 0;
					break;
				}
			default:
				break;
			}
		}
		FlushBatchDraw();
	}

	player->moveTo(scenes[0]->get_startPos());
	bool moved = false;
	int moveInterval = 0;
	int saveInterval = 1000;
	scenes[0]->allVisited();
	

	while (running)
	{
		moveInterval++;
		DWORD start_time = GetTickCount();
		std::cout << player->get_pos().x << " " << player->get_pos().y << "\n";
		BeginBatchDraw();

		pt_scene(scenes, player);
		Message_paint();
		GUI_paint(scenes,player);

		//Player_paint(scene);

		/* 自动存档 */
		saveInterval--;
		if (saveInterval == 0)
		{
			saveInterval = 1000;
			saveGame(scenes, player, true);
		}

		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYUP)
			{
				switch (msg.ch)
				{
				case 'W':
				case 'A':
				case 'S':
				case 'D':
				case VK_UP:
				case VK_LEFT:
				case VK_DOWN:
				case VK_RIGHT:
					moved = false;
				default:
					break;
				}
			}
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.ch)
				{
				case 'W':
				case VK_UP:
					if (!moved || moveInterval > 6) moveInterval = 0, player->move(UP);
					moved = true;
					break;
				case 'S':
				case VK_DOWN:
					if (!moved || moveInterval > 6) moveInterval = 0, player->move(DOWN);
					moved = true;
					break;
				case 'A':
				case VK_LEFT:
					if (!moved || moveInterval > 6) moveInterval = 0, player->move(LEFT);
					moved = true;
					break;
				case 'D':
				case VK_RIGHT:
					if (!moved || moveInterval > 6) moveInterval = 0, player->move(RIGHT);
					moved = true;
					break;
				case 'E':
				case 'e':
					while(item)
					{
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
		updateLight(scenes, player);
		randomEvent(&player);
		

		if (player->dead())
		{
			int ind = findGadget("TeleportScroll");
			if (player->gadgets[ind] != 0)
			{
				std::cout << "你使用回城卷轴逃离了" << ((player->get_pos().stage == Scene::CAVE) ? "洞穴" : "迷宫") << "\n";
				gadgetInHand = ind;
				player->use_gadget();
				player->set_health(player->get_maxHealth());
				player->set_food(player->get_food_capacity());
			}
			else
			{
				delete player;
				destroyGadgetList();
				destroyTrapList();
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