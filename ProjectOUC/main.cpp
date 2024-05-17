#include <iostream>
#include <conio.h>
#include "graphics.h"
#include "roles/chest.h"
#include "gadgets/gadgets.h"
#include "roles/monster.h"
#include "roles/player.h"
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

void checkTile(std::vector<Scene*>& scenes, Player* player)
{
	SetConsoleOutputCP(CP_UTF8);
	Position pos = player->get_pos();
	if (player->get_attr().teleport)
	{
		player->moveTo(scenes[0]->get_startPos());
		player->set_teleport(false);
		return;
	}
	if (pos.stage < 0 || pos.stage >= scenes.size())
	{
		player->modify_pos(player->get_lastPos());
		return;
	}
	Scene* scene = scenes[pos.stage];
	if (pos.x <= 0 || pos.y <= 0 || pos.x >= scene->get_height() || pos.y >= scene->get_width())
	{
		player->modify_pos(player->get_lastPos());
		return;
	}

	Tile* tile = scene->get_tiles(pos.x, pos.y);
	if (tile->get_unreachable())
	{
		player->modify_pos(player->get_lastPos());
		return;
	}


	if (tile->get_type() == WALL_TILE)
	{
		player->modify_moved(false);
		return;
	}

	else if (tile->get_type() == BATTLE_TILE)
	{
		player->modify_moved(true);
		for (int i = 0; i < tile->monsters.size(); ++i)
		{
			std::cout << "遭遇" << tile->monsters[i]->get_name() << "\n";
			std::cout << "HP: " << tile->monsters[i]->get_health() << "\natk: " << tile->monsters[i]->get_attack();
			std::cout << "\ndef: " << tile->monsters[i]->get_defense() << "\n";
			Battle battle((Character*)tile->monsters[i], (Character*)player);

			if (!battle.battle())
			{
				return;
			}
			std::cout << "战胜" << tile->monsters[i]->get_name() << "\n" <<
				"剩余生命: " << player->get_health() <<
				"\n防御: " << player->get_defense() <<
				"\n攻击: " << player->get_attack() << "\n\n";
		}
		tile->monsters.clear();
		tile->modify_type(EMPTY_TILE);
		return;
	}

	else if (tile->get_type() == EMPTY_TILE)
	{
		player->modify_moved(true);
		return;
	}

	else if (tile->get_type() == CHEST_TILE)
	{
		player->modify_moved(true);
		for (int i = 0; i < tile->chests.size(); ++i)
		{
			std::cout << "打开" << tile->chests[i]->get_name() << "\n";
			Battle battle((Character*)tile->chests[i], (Character*)player);
			if (!battle.battle())
			{
				return;
			}
			std::cout << "获得" << tile->chests[i]->get_coin() << "铜币\n";
			std::cout << "当前金钱: " << player->get_coin() << "\n\n";
		}
		tile->chests.clear();
		tile->modify_type(EMPTY_TILE);
		return;
	}

	else if (tile->get_type() == START_TILE)
	{
		if (player->get_moved() && pos.stage > 0) player->moveTo(scenes[pos.stage - 1]->get_endPos());
		player->modify_moved(false);
		return;
	}
	else if (tile->get_type() == END_TILE)
	{
		if (player->get_moved() && pos.stage < scenes.size() - 1) player->moveTo(scenes[pos.stage + 1]->get_startPos());
		player->modify_moved(false);
		return;
	}
	return;
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
	Player* player = getPlayer(1);
	std::vector<Scene*> scene(2);
	scene[0] = new Scene(caveGenerate(15, 15, 6, 45, 0.6), Scene::CAVE, 0);
	scene[1] = new Scene(mazeGenerate(15, 15, 10, 1, 3, 5, 80, 0.5), Scene::MAZE, 1);
	player->moveTo(scene[0]->get_startPos());

	Paint paint(WIDTH, HEIGHT);
	
	direction d[4] = { LEFT, RIGHT, UP, DOWN };
	int movePause = 0; //防止卡进墙里
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
		pt(scene, player);
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
					do gadgetInHand = (gadgetInHand + 1) % max_gadget_index;
					while (!usefulGadgetSet.count(gadgetInHand));
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
		
		checkTile(scene, player);

		if (player->dead())
		{
			Gameover_paint(WIDTH, HEIGHT);
			break;
		}

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / fps)
		{
			Sleep(1000 / fps - delta_time);
		}
	}

	// Ending 
	destroyGadgetList();
	for (int i = 0; i < scene.size(); ++i) delete scene[i];
	getchar();
	closegraph();
	//
	return 0;
}