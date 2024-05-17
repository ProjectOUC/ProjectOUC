#include "paint.h"
#include<conio.h>
#include<graphics.h>
#include<string>
using namespace std;

Paint::Paint(int width, int height)
{

}

void Map_paint(int width,int height)
{
	int i, j;
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	line(0, 100, width, 100);
	line(width - 100, 0, width - 100, height);
	line(0, 0, 0, 100);
	line(width - 100, height, width, height);
	for (i = 0; i <= width - 100; i += 100)
	{
		line(i, 100, i, height);
	}
	for (j = 100; j <= height; j += 100)
	{
		line(0, j, width - 100, j);
	}
}

void transparentimage(int x, int y, IMAGE img) {
	IMAGE img1;
	DWORD* d1;
	img1 = img;
	d1 = GetImageBuffer(&img);
	float h, s, l;
	for (int i = 0; i < img1.getheight() * img1.getwidth(); i++) {
		RGBtoHSL(BGR(d1[i]), &h, &s, &l);
		if (l < 0.03) {
			d1[i] = BGR(WHITE);
		}
		if (d1[i] != BGR(WHITE)) {
			d1[i] = 0;
		}
	}
	putimage(x, y, &img1, SRCAND);
	putimage(x, y, &img, SRCPAINT);
	//	putimage(x+100,y,&img1);
	//	putimage(x+200,y,&img);
}

void Gameover_paint(int width, int height)
{
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	setfillcolor(CYAN);
	fillrectangle(width / 2 - 100, height / 2 - 50, width / 2 + 100, height / 2 + 50);
	settextcolor(BROWN);
	
	settextstyle(0, 0, "行楷");
	setbkmode(TRANSPARENT);
	int w=textwidth("Game Over");
	int h = textheight("Game Over");
	int p_x = (200 - w) / 2;
	int p_y = (100 - h) / 2;
	outtextxy(width / 2 - 100+p_x, height / 2-50+p_y, "Game Over");
}

void Player_paint(std::vector<Scene*> scenes, Player* player)
{
	int x, y;
	x = player->get_pos().x;
	y = player->get_pos().y;
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(BLUE);
	fillrectangle(25 + x * 100, 125 + y * 100, 75 + x * 100, 175 + y * 100);
}

void Money_paint(Player* player)
{
	int money = player->get_coin();
	char moneycoin[20]; //用于存放字符串
	sprintf_s(moneycoin, "%d", money);
	settextcolor(RED);
	settextstyle(30, 0, "行楷");
	int w = textwidth("MONEY:");
	int h = textheight("HP:");
	outtextxy(0, h, "MONEY:");
	outtextxy(w, h, moneycoin);
}

void chest_paint(Scene& scene)
{
	int i, j;
	Tile* tile;
	for (i = 0; i < scene.get_width(); i++)
	{
		for (j = 0; j < scene.get_height(); j++)
		{
			tile = scene.get_tiles(i, j);
			if (tile->get_type() == CHEST_TILE)
			{
				setlinecolor(BLACK);
				setlinestyle(PS_SOLID, 2);
				setfillcolor(GREEN);
				fillrectangle(25 + i * 100, 125 + j * 100, 75 + i * 100, 175 + j * 100);
			}
		}
	}	
}

void paint_wall (Scene& scene)
{
	int i, j;
	Tile* tile;
	for (i = 0; i < scene.get_width(); ++i)
	{
		for (j = 0; j < scene.get_height(); ++j)
		{
			tile = scene.get_tiles(i, j);
			if (tile->get_type() == WALL_TILE)
			{
				setlinecolor(BLACK);
				setlinestyle(PS_SOLID, 2);
				setfillcolor(BLACK);
				fillrectangle(25 + i * 100, 125 + j * 100, 75 + i * 100, 175 + j * 100);
			}
		}
	}
}

void monster_paint(Scene& scene)
{
	int i, j;
	Tile* tile;
	for (i = 0; i < scene.get_width(); i++)
	{
		for (j = 0; j < scene.get_height(); j++)
		{
			tile = scene.get_tiles(i, j);
			if (tile->get_type()==BATTLE_TILE)
			{
				setlinecolor(BLACK);
				setlinestyle(PS_SOLID, 2);
				setfillcolor(RED);
				fillrectangle(25 + i * 100, 125 + j * 100, 75 + i * 100, 175 + j * 100);
			}
		}
	}
}

void Health_paint(Player* player)
{
	int health = player->get_health();
	char healthpoint[20]; //用于存放字符串
	sprintf_s(healthpoint, "%d", health);
	settextcolor(RED);
	settextstyle(30,0 , "行楷");
	outtextxy(0, 0, "HP:");
	int w = textwidth("HP:");
	outtextxy(w, 0, healthpoint);
}

void paint_heart(Player* player)
{
	static int i = 0, j = 0;
	static bool flag = false;
	static IMAGE img1, img2, img3;
	if (!flag)
	{
		loadimage(&img1, _T("heart.png"));
		loadimage(&img2, _T("half_heart.png"));
		loadimage(&img3, _T("empty_heart.png"));
		flag = true;
	}
	int heartpoint = player->get_health();
	int heartnum = heartpoint / 2;
	int half_heartnum = heartpoint % 2;
	int empth_heartnum = (10 - heartpoint) / 2;
	settextcolor(RED);
	settextstyle(30, 0, "行楷");
	outtextxy(0, 0, "HP:");
	static int w = textwidth("HP:");
	for (i = 0; i < heartnum; i++)
	{
		transparentimage(w + i * 16, 0, img1);
	}
	if (half_heartnum)
	{
		transparentimage(w + i * 16, 0, img2);
	}
}
