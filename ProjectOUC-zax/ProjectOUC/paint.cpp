#include "paint.h"
#include<conio.h>
#include<graphics.h>
#include<string>
#define LENGTH_PIXIV 16
#define WIDTH 800
#define HEIGHT 600
using namespace std;

extern const int EMPTY;
extern const int WALL;
extern const int BIRTH;

static IMAGE img_town_wall;
static IMAGE img_town_left_wall;
static IMAGE img_town_up_wall;
static IMAGE img_town_up_left_wall;
static IMAGE img_town_up_right_wall;
static IMAGE img_town_left_down_wall;
static IMAGE img_town_right_down_wall;
static IMAGE img_town_middle_wall;
static IMAGE img_town_up_middle_wall;
static IMAGE img_town_right_middle_wall;
static IMAGE img_town_left_middle_wall;
static IMAGE img_town_down_middle_wall;
static IMAGE img_town_down_wall;
static IMAGE img_cave_wall;
static IMAGE img_cave_left_wall;
static IMAGE img_cave_up_wall;
static IMAGE img_cave_up_left_wall;
static IMAGE img_cave_up_right_wall;
static IMAGE img_cave_left_down_wall;
static IMAGE img_cave_right_down_wall;
static IMAGE img_cave_middle_wall;
static IMAGE img_cave_up_middle_wall;
static IMAGE img_cave_right_middle_wall;
static IMAGE img_cave_left_middle_wall;
static IMAGE img_cave_down_middle_wall;
static IMAGE img_cave_down_wall;
static IMAGE img_maze_wall;
static IMAGE img_maze_left_wall;
static IMAGE img_maze_up_wall;
static IMAGE img_maze_up_left_wall;
static IMAGE img_maze_up_right_wall;
static IMAGE img_maze_left_down_wall;
static IMAGE img_maze_right_down_wall;
static IMAGE img_maze_middle_wall;
static IMAGE img_maze_up_middle_wall;
static IMAGE img_maze_right_middle_wall;
static IMAGE img_maze_left_middle_wall;
static IMAGE img_maze_down_middle_wall;
static IMAGE img_maze_down_wall;
static IMAGE img_GUI_left_up;
static IMAGE img_GUI_left;
static IMAGE img_GUI_right_up;
static IMAGE img_GUI_up;
static IMAGE img_GUI_right;
static IMAGE img_GUI_left_down;
static IMAGE img_GUI_right_down;
static IMAGE img_GUI_down;
static IMAGE img_GUI_middle;
static IMAGE img_Message_left_up;
static IMAGE img_Message_left;
static IMAGE img_Message_right_up;
static IMAGE img_Message_up;
static IMAGE img_Message_right;
static IMAGE img_Message_left_down;
static IMAGE img_Message_right_down;
static IMAGE img_Message_down;
static IMAGE img_Message_middle;
static IMAGE img_cave_floor;
static IMAGE img_cave_down_floor;
static IMAGE img_cave_left_up_floor;
static IMAGE img_cave_up_floor;
static IMAGE img_cave_right_up_floor;
static IMAGE img_cave_left_floor;
static IMAGE img_cave_middle_floor;
static IMAGE img_cave_right_floor;
static IMAGE img_cave_left_down_floor;
static IMAGE img_cave_right_down_floor;
static IMAGE img_cave_leftright_up_floor;
static IMAGE img_cave_leftright_floor;
static IMAGE img_cave_leftright_down_floor;
static IMAGE img_cave_updown_left_floor;
static IMAGE img_cave_updown_floor;
static IMAGE img_cave_updown_right_floor;
static IMAGE img_maze_floor;
static IMAGE img_maze_down_floor;
static IMAGE img_maze_left_up_floor;
static IMAGE img_maze_up_floor;
static IMAGE img_maze_right_up_floor;
static IMAGE img_maze_left_floor;
static IMAGE img_maze_middle_floor;
static IMAGE img_maze_right_floor;
static IMAGE img_maze_left_down_floor;
static IMAGE img_maze_right_down_floor;
static IMAGE img_maze_leftright_up_floor;
static IMAGE img_maze_leftright_floor;
static IMAGE img_maze_leftright_down_floor;
static IMAGE img_maze_updown_left_floor;
static IMAGE img_maze_updown_floor;
static IMAGE img_maze_updown_right_floor;

static IMAGE img_player_1;
static IMAGE img_player_2;
static IMAGE img_skull;
static IMAGE img_chest;
static IMAGE img_start;
static IMAGE img_end;
static IMAGE img_heart_point;
static IMAGE img_money;
static IMAGE img_food;
static IMAGE img_background_forest;
#pragma comment(lib,"MSIMG32.LIB")

Paint::Paint(int width, int height)
{

}

void Loading_image()
{
	loadimage(&img_town_wall, _T("res\\town_wall\\town_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_down_wall, _T("res\\town_wall\\town_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_wall, _T("res\\town_wall\\town_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_wall, _T("res\\town_wall\\town_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_down_wall, _T("res\\town_wall\\town_left_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_middle_wall, _T("res\\town_wall\\town_left_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_down_middle_wall, _T("res\\town_wall\\town_down_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_middle_wall, _T("res\\town_wall\\town_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_down_wall, _T("res\\town_wall\\town_right_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_middle_wall, _T("res\\town_wall\\town_right_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_left_wall, _T("res\\town_wall\\town_up_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_middle_wall, _T("res\\town_wall\\town_up_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_right_wall, _T("res\\town_wall\\town_up_right_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_wall, _T("res\\town_wall\\town_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_wall, _T("res\\cave_wall\\cave_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_down_wall, _T("res\\cave_wall\\cave_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_wall, _T("res\\cave_wall\\cave_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_wall, _T("res\\cave_wall\\cave_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_down_wall, _T("res\\cave_wall\\cave_left_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_middle_wall, _T("res\\cave_wall\\cave_left_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_down_middle_wall, _T("res\\cave_wall\\cave_down_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_middle_wall, _T("res\\cave_wall\\cave_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_right_down_wall, _T("res\\cave_wall\\cave_right_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_right_middle_wall, _T("res\\cave_wall\\cave_right_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_left_wall, _T("res\\cave_wall\\cave_up_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_middle_wall, _T("res\\cave_wall\\cave_up_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_right_wall, _T("res\\cave_wall\\cave_up_right_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_wall, _T("res\\cave_wall\\cave_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_wall, _T("res\\maze_wall\\maze_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_down_wall, _T("res\\maze_wall\\maze_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_wall, _T("res\\maze_wall\\maze_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_wall, _T("res\\maze_wall\\maze_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_down_wall, _T("res\\maze_wall\\maze_left_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_middle_wall, _T("res\\maze_wall\\maze_left_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_down_middle_wall, _T("res\\maze_wall\\maze_down_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_middle_wall, _T("res\\maze_wall\\maze_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_right_down_wall, _T("res\\maze_wall\\maze_right_down_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_right_middle_wall, _T("res\\maze_wall\\maze_right_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_left_wall, _T("res\\maze_wall\\maze_up_left_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_middle_wall, _T("res\\maze_wall\\maze_up_middle_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_right_wall, _T("res\\maze_wall\\maze_up_right_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_wall, _T("res\\maze_wall\\maze_up_wall.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_floor, _T("res\\cave_floor\\cave_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_up_floor, _T("res\\cave_floor\\cave_left_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_up_floor, _T("res\\cave_floor\\cave_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_right_up_floor, _T("res\\cave_floor\\cave_right_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_floor, _T("res\\cave_floor\\cave_left_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_middle_floor, _T("res\\cave_floor\\cave_middle_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_right_floor, _T("res\\cave_floor\\cave_right_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_left_down_floor, _T("res\\cave_floor\\cave_left_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_down_floor, _T("res\\cave_floor\\cave_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_right_down_floor, _T("res\\cave_floor\\cave_right_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_leftright_up_floor, _T("res\\cave_floor\\cave_leftright_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_leftright_floor, _T("res\\cave_floor\\cave_leftright_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_leftright_down_floor, _T("res\\cave_floor\\cave_leftright_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_updown_left_floor, _T("res\\cave_floor\\cave_updown_left_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_updown_floor, _T("res\\cave_floor\\cave_updown_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_cave_updown_right_floor, _T("res\\cave_floor\\cave_updown_right_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_floor, _T("res\\maze_floor\\maze_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_up_floor, _T("res\\maze_floor\\maze_left_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_up_floor, _T("res\\maze_floor\\maze_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_right_up_floor, _T("res\\maze_floor\\maze_right_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_floor, _T("res\\maze_floor\\maze_left_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_middle_floor, _T("res\\maze_floor\\maze_middle_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_right_floor, _T("res\\maze_floor\\maze_right_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_left_down_floor, _T("res\\maze_floor\\maze_left_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_down_floor, _T("res\\maze_floor\\maze_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_right_down_floor, _T("res\\maze_floor\\maze_right_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_leftright_up_floor, _T("res\\maze_floor\\maze_leftright_up_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_leftright_floor, _T("res\\maze_floor\\maze_leftright_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_leftright_down_floor, _T("res\\maze_floor\\maze_leftright_down_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_updown_left_floor, _T("res\\maze_floor\\maze_updown_left_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_updown_floor, _T("res\\maze_floor\\maze_updown_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_maze_updown_right_floor, _T("res\\maze_floor\\maze_updown_right_floor.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_left_up, _T("res\\GUI\\GUI_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_up, _T("res\\GUI\\GUI_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_left_down, _T("res\\GUI\\GUI_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_right_up, _T("res\\GUI\\GUI_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_right, _T("res\\GUI\\GUI_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_right_down, _T("res\\GUI\\GUI_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_left, _T("res\\GUI\\GUI_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_middle, _T("res\\GUI\\GUI_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_GUI_down, _T("res\\GUI\\GUI_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_left_up, _T("res\\GUI\\Message_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_up, _T("res\\GUI\\Message_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_left_down, _T("res\\GUI\\Message_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_right_up, _T("res\\GUI\\Message_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_right, _T("res\\GUI\\Message_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_right_down, _T("res\\GUI\\Message_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_left, _T("res\\GUI\\Message_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_middle, _T("res\\GUI\\Message_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_Message_down, _T("res\\GUI\\Message_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_player_1, _T("res\\player\\player_1.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_player_2, _T("res\\player\\player_2.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_chest, _T("res\\chest\\chest.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_skull, _T("res\\monster\\skull.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_start, _T("res\\status\\start.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_end, _T("res\\status\\end.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_heart_point, _T("res\\GUI\\heart.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_money, _T("res\\GUI\\money_bag.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_food, _T("res\\GUI\\food.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_background_forest, _T("res\\background\\background_forest.jpg"),WIDTH,HEIGHT);
	
}


inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

void start_paint(int width, int height)
{
	putimage_alpha(0, 0, &img_background_forest);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	setfillcolor(YELLOW);
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	fillrectangle(width / 2 - 100, height / 3 - 50, width / 2 + 100, height / 3 + 50);
	fillrectangle(width / 2 - 100, (height / 3)*2 - 50, width / 2 + 100, (height / 3) *2 + 50);
	settextstyle(20, 0, "Î¢ÈíÑÅºÚ");
	int w1 = textwidth("Start Game");
	int h1 = textheight("Start Game");
	int w2 = textwidth("End Game");
	int h2 = textheight("End Game");
	outtextxy(width / 2 - (w1 / 2), height / 3 - (h1 / 2), "Start Game");
	outtextxy(width / 2 - (w2 / 2), (height / 3) * 2-(h2/2), "End Game");
}

void Gameover_paint(int width, int height)
{
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	setfillcolor(CYAN);
	fillrectangle(width / 2 - 100, height / 2 - 50, width / 2 + 100, height / 2 + 50);
	settextcolor(BROWN);
	
	settextstyle(0, 0, "ÐÐ¿¬");
	setbkmode(TRANSPARENT);
	int w=textwidth("Game Over");
	int h = textheight("Game Over");
	int p_x = (200 - w) / 2;
	int p_y = (100 - h) / 2;
	outtextxy(width / 2 - 100+p_x, height / 2-50+p_y, "Game Over");
}

void Player_choice(int width,int height)
{
	putimage_alpha(width/3-LENGTH_PIXIV/2, height/2-LENGTH_PIXIV/2, &img_player_1);
	putimage_alpha((width / 3) * 2 - LENGTH_PIXIV / 2, (height / 2) - LENGTH_PIXIV / 2, &img_player_2);
}

void GUI_paint(std::vector<Scene*>& scenes, Player* player)
{
	char heart_point[10]; 
	sprintf_s(heart_point,":%d", player->get_health());
	char money_point[10];
	sprintf_s(money_point,":%d", player->get_coin());
	char food_point[10];
	sprintf_s(food_point, ":%d", player->get_food());
	int x, y;
	for (x = 0; x < 35; x++)   //ÉÏ·½
	{
		for (y = 0; y < 4; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left_up);
			else if (x == 0 && y != 0&&y!=3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left);
			else if (x != 0 && y == 0&&x!=34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_up);
			else if (x == 0 && y == 3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left_down);
			else if (x == 34 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right_up);
			else if (x == 34 && y == 3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right_down);
			else if (x != 34 && y == 3&&x!=0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_down);
			else if (x == 34 && y != 3&&y!=0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_middle);
		}
	}
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 31; y++)
		{
			if(x==0&&y==0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_left_up);
			else if(x==0&&y!=0&&y!=30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_left);
			else if(x!=0&&x!=3&&y==0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_up);
			else if(x==0&&y==30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_left_down);
			else if(x==3&&y==0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_right_up);
			else if(x==3&&y==30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_right_down);
			else if(x!=0&&x!=3&&y==30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_down);
			else if(x==3&&y!=0&&y!=30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y+64, &img_GUI_middle);
		}
	}
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "Î¢ÈíÑÅºÚ");
	putimage_alpha(LENGTH_PIXIV*0+8, LENGTH_PIXIV*0+8, &img_heart_point);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 0 + 8,heart_point);
	putimage_alpha(LENGTH_PIXIV *0+ 8, LENGTH_PIXIV * 1+ 8, &img_money);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 1 + 8, money_point);
	putimage_alpha(LENGTH_PIXIV * 0 + 8, LENGTH_PIXIV * 2 + 8, &img_food);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 2 + 8, food_point);
}

void Message_paint()
{
	for (int x = 35; x < 46; x++)
	{
		for (int y = 0; y < 35; y++)
		{
			if (x == 35 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left_up);
			else if (x == 35 && y != 0 && y != 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left);
			else if (x != 35 && x != 45 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_up);
			else if (x == 35 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left_down);
			else if (x == 45 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_right_up);
			else if (x == 45 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_Message_right_down);
			else if (x != 35 && x != 45 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_down);
			else if (x == 45 && y != 0 && y != 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_middle);
		}
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(16, 0, "Î¢ÈíÑÅºÚ");
		outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV*0 + 8, "Hello,Can you hear me?");
	}
}

void Player_paint(int x,int y,int type)
{
	if(type==1)
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_player_1);
	else
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_player_2);
}


void Start_paint(int x, int y)
{
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_start);
}

void End_paint(int x, int y)
{
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_end);
}

void Chest_paint(int x, int y)
{
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_chest);
}

void Monster_paint(int x, int y)
{
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_skull);
}

void Cave_Wall_paint(Scene* scene, int pos)
{
	int w = scene->get_width();
	int h = scene->get_height();
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			Tile* tile = scene->get_tiles(x, y);
			if (tile->get_type() == WALL_TILE)
			{
				if (x == 0 && y == 0)
				{
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					if (tile_right_down->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_left_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (x == 0 && y == h - 1)
				{
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (x == w - 1 && y == h - 1)
				{
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (x == w - 1 && y == 0)
				{
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left_down->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (x == 0 && y != 0 && y != h - 1)
				{
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_middle_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (y == 0 && x != 0 && x != w - 1)
				{
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_down->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_middle_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_left_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (y == h - 1 && x != 0 && x != w - 1)
				{
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_up->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_down_middle_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else if (x == w - 1 && y != 0 && y != h - 1)
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
				}
				else
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_left_wall);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_down_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_down->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& (tile_right_up->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_down_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_up->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE || tile_right_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_middle_wall);
				}
			}
		}
	}
}
void Maze_Wall_paint(Scene* scene, int pos)
{
	int w = scene->get_width();
	int h = scene->get_height();
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			Tile* tile = scene->get_tiles(x, y);
			if (tile->get_type() == WALL_TILE)
			{
				if (x == 0 && y == 0)
				{
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					if (tile_right_down->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_left_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (x == 0 && y == h - 1)
				{
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (x == w - 1 && y == h - 1)
				{
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (x == w - 1 && y == 0)
				{
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left_down->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (x == 0 && y != 0 && y != h - 1)
				{
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_middle_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (y == 0 && x != 0 && x != w - 1)
				{
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_down->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_middle_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_left_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (y == h - 1 && x != 0 && x != w - 1)
				{
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_up->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_down_middle_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else if (x == w - 1 && y != 0 && y != h - 1)
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
				}
				else
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_left_wall);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_down_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_down->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& (tile_right_up->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_down_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_up->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE || tile_right_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_middle_wall);
				}
			}
		}
	}
}
void TOWN_Wall_paint(Scene* scene, int pos)
{
	int w = scene->get_width();
	int h = scene->get_height();
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			Tile* tile = scene->get_tiles(x, y);
			if (tile->get_type() == WALL_TILE)
			{
				if (x == 0 && y == 0)
				{
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					if (tile_right_down->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_floor);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					}
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == 0 && y == h - 1)
				{
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == w - 1 && y == h - 1)
				{
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left_up->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == w - 1 && y == 0)
				{
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left_down->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == 0 && y != 0 && y != h - 1)
				{
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_middle_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					else if (tile_right->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (y == 0 && x != 0 && x != w - 1)
				{
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_down->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_middle_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					else if (tile_down->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (y == h - 1 && x != 0 && x != w - 1)
				{
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_up->get_type() != WALL_TILE) putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_middle_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					else if (tile_up->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == w - 1 && y != 0 && y != h - 1)
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left->get_type() != WALL_TILE)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else
				{
					Tile* tile_left = scene->get_tiles(x - 1, y);
					Tile* tile_down = scene->get_tiles(x, y + 1);
					Tile* tile_up = scene->get_tiles(x, y - 1);
					Tile* tile_right = scene->get_tiles(x + 1, y);
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_left_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_floor);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_wall);
					}
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() == WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() == WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_left_up->get_type() == WALL_TILE && tile_right_up->get_type() == WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_down->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_right_down->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_middle_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& (tile_right_up->get_type() != WALL_TILE || tile_left_up->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_middle_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_up->get_type() != WALL_TILE && tile_right_up->get_type() != WALL_TILE && tile_left_down->get_type() != WALL_TILE && tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE
						&& (tile_left_up->get_type() != WALL_TILE || tile_right_up->get_type() != WALL_TILE || tile_left_down->get_type() != WALL_TILE || tile_right_down->get_type() != WALL_TILE))
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_wall);
				}
			}
		}
	}
}
void Cave_Empty_paint(int x, int y,Scene* scene,int pos)
{
		Tile* tile = scene->get_tiles(x, y);
			if (tile->get_type() != WALL_TILE)
			{
				Tile* tile_left = scene->get_tiles(x - 1, y);
				Tile* tile_down = scene->get_tiles(x, y + 1);
				Tile* tile_up = scene->get_tiles(x, y - 1);
				Tile* tile_right = scene->get_tiles(x + 1, y);
				Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
				Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
				Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
				Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
				if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_up_floor);
				else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_down_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_up_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_down_floor);
				else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_left_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE&& tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_up_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_right_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_down_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_updown_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_updown_left_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_updown_right_floor);
				else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_leftright_floor);
				else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_leftright_up_floor);
				else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_leftright_down_floor);
				else  
					putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_cave_floor);
			}
}
void Maze_Empty_paint(int x, int y, Scene* scene, int pos)
{
	Tile* tile = scene->get_tiles(x, y);
	if (tile->get_type() != WALL_TILE)
	{
		Tile* tile_left = scene->get_tiles(x - 1, y);
		Tile* tile_down = scene->get_tiles(x, y + 1);
		Tile* tile_up = scene->get_tiles(x, y - 1);
		Tile* tile_right = scene->get_tiles(x + 1, y);
		Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
		Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
		Tile* tile_right_down = scene->get_tiles(x + 1, y + 1);
		Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
		if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_up_floor);
		else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_down_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_up_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() == WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_down_floor);
		else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_left_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_up_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_right_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_down_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_updown_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_updown_left_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_updown_right_floor);
		else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_leftright_floor);
		else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_leftright_up_floor);
		else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE)
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_leftright_down_floor);
		else
			putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_maze_floor);
	}
}