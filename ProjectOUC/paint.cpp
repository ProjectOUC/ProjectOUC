#include "paint.h"
#include<conio.h>
#include<graphics.h>
#include<string>

#define LENGTH_PIXIV 16
#define WIDTH 800
#define HEIGHT 600
#pragma execution_character_set("utf-8")
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

static IMAGE img_speak_middle;
static IMAGE img_speak_left_up;
static IMAGE img_speak_up;
static IMAGE img_speak_right_up;
static IMAGE img_speak_left;
static IMAGE img_speak_right;
static IMAGE img_speak_left_down;
static IMAGE img_speak_down;
static IMAGE img_speak_right_down;

static IMAGE img_item_left_up;
static IMAGE img_item_up;
static IMAGE img_item_right_up;
static IMAGE img_item_left;
static IMAGE img_item_middle;
static IMAGE img_item_right;
static IMAGE img_item_left_down;
static IMAGE img_item_down;
static IMAGE img_item_right_down;
static IMAGE img_item_equip;

static IMAGE img_grass_left_up;
static IMAGE img_grass_up;
static IMAGE img_grass_right_up;
static IMAGE img_grass_left;
static IMAGE img_grass_middle;
static IMAGE img_grass_right;
static IMAGE img_grass_left_down;
static IMAGE img_grass_down;
static IMAGE img_grass_right_down;
static IMAGE img_grass_leftright_up;
static IMAGE img_grass_leftright;
static IMAGE img_grass_leftright_down;
static IMAGE img_grass_updown_left;
static IMAGE img_grass_updown;
static IMAGE img_grass_updown_right;

static IMAGE img_town_left_up_base;
static IMAGE img_town_left_base;
static IMAGE img_town_up_base;
static IMAGE img_town_right_up_base;
static IMAGE img_town_right_base;
static IMAGE img_town_middle_base;
static IMAGE img_town_left_down_base;
static IMAGE img_town_down_base;
static IMAGE img_town_right_down_base;
static IMAGE img_town_leftright_up_base;
static IMAGE img_town_leftright_base;
static IMAGE img_town_leftright_down_base;
static IMAGE img_town_updown_left_base;
static IMAGE img_town_updown_base;
static IMAGE img_town_updown_right_base;

static IMAGE img_town_left_up_road;
static IMAGE img_town_up_road;
static IMAGE img_town_right_up_road;
static IMAGE img_town_left_road;
static IMAGE img_town_middle_road;
static IMAGE img_town_right_road;
static IMAGE img_town_left_down_road;
static IMAGE img_town_down_road;
static IMAGE img_town_right_down_road;
static IMAGE img_town_leftright_up_road;
static IMAGE img_town_leftright_road;
static IMAGE img_town_leftright_down_road;
static IMAGE img_town_updown_left_road;
static IMAGE img_town_updown_road;
static IMAGE img_town_updown_right_road;

static IMAGE img_town_left_up_floor;
static IMAGE img_town_up_floor;
static IMAGE img_town_right_up_floor;
static IMAGE img_town_left_floor;
static IMAGE img_town_middle_floor;
static IMAGE img_town_right_floor;
static IMAGE img_town_left_down_floor;
static IMAGE img_town_down_floor;
static IMAGE img_town_right_down_floor;
static IMAGE img_town_leftright_floor;
static IMAGE img_town_leftright_up_floor;
static IMAGE img_town_leftright_down_floor;
static IMAGE img_town_updown_floor;
static IMAGE img_town_updown_left_floor;
static IMAGE img_town_updown_right_floor;

static IMAGE img_event_left_up;
static IMAGE img_event_up;
static IMAGE img_event_right_up;
static IMAGE img_event_left;
static IMAGE img_event_middle;
static IMAGE img_event_right;
static IMAGE img_event_left_down;
static IMAGE img_event_down;
static IMAGE img_event_right_down;

static IMAGE img_gadget_sword;
static IMAGE img_gadget_shield;
static IMAGE img_gadget_healpotion;
static IMAGE img_gadget_telescroll;
static IMAGE img_gadget_bow;
static IMAGE img_gadget_cursedstone;
static IMAGE img_gadget_key;

static IMAGE img_player_1;
static IMAGE img_player_2;
static IMAGE img_food_npc;

static IMAGE img_skull;
static IMAGE img_goblin;
static IMAGE img_slime;
static IMAGE img_orc;
static IMAGE img_dragon;
static IMAGE img_skeleton;
static IMAGE img_vampire;
static IMAGE img_witch;
static IMAGE img_ghost;
static IMAGE img_werewolf;



static IMAGE img_chest;
static IMAGE img_start;
static IMAGE img_end;
static IMAGE img_heart_point;
static IMAGE img_money;
static IMAGE img_food;
static IMAGE img_background_forest;

static IMAGE img_tree;
static IMAGE img_door;
static IMAGE img_counter_leftright_left;
static IMAGE img_counter_leftright;
static IMAGE img_counter_leftright_right;
static IMAGE img_counter_updown;
static IMAGE img_counter_updown_up;
static IMAGE img_counter_updown_down;
static IMAGE img_door_0;
static IMAGE img_food_cupboard_0;
static IMAGE img_food_cupboard_1;
static IMAGE img_food_sold;
static IMAGE img_fountain;
static IMAGE img_left_chair;
static IMAGE img_right_chair;
static IMAGE img_table;
static IMAGE img_light;
static IMAGE img_carpet;
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

	loadimage(&img_grass_left_up, _T("res\\grass\\grass_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_up, _T("res\\grass\\grass_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_right_up, _T("res\\grass\\grass_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_left, _T("res\\grass\\grass_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_middle, _T("res\\grass\\grass_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_right, _T("res\\grass\\grass_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_left_down, _T("res\\grass\\grass_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_down, _T("res\\grass\\grass_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_right_down, _T("res\\grass\\grass_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_leftright_up, _T("res\\grass\\grass_leftright_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_leftright, _T("res\\grass\\grass_leftright.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_leftright_down, _T("res\\grass\\grass_leftright_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_updown_left, _T("res\\grass\\grass_updown_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_updown, _T("res\\grass\\grass_updown.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_grass_updown_right, _T("res\\grass\\grass_updown_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_town_left_up_base, _T("res\\town_base\\town_base_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_base, _T("res\\town_base\\town_base_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_up_base, _T("res\\town_base\\town_base_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_base, _T("res\\town_base\\town_base_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_base, _T("res\\town_base\\town_base_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_middle_base, _T("res\\town_base\\town_base_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_down_base, _T("res\\town_base\\town_base_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_down_base, _T("res\\town_base\\town_base_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_down_base, _T("res\\town_base\\town_base_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_up_base, _T("res\\town_base\\town_base_leftright_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_base, _T("res\\town_base\\town_base_leftright.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_down_base, _T("res\\town_base\\town_base_leftright_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_left_base, _T("res\\town_base\\town_base_updown_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_base, _T("res\\town_base\\town_base_updown.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_right_base, _T("res\\town_base\\town_base_updown_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_town_left_up_road, _T("res\\town_road\\town_road_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_road, _T("res\\town_road\\town_road_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_up_road, _T("res\\town_road\\town_road_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_road, _T("res\\town_road\\town_road_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_road, _T("res\\town_road\\town_road_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_middle_road, _T("res\\town_road\\town_road_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_down_road, _T("res\\town_road\\town_road_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_down_road, _T("res\\town_road\\town_road_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_down_road, _T("res\\town_road\\town_road_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_up_road, _T("res\\town_road\\town_road_leftright_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_road, _T("res\\town_road\\town_road_leftright.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_down_road, _T("res\\town_road\\town_road_leftright_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_left_road, _T("res\\town_road\\town_road_updown_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_road, _T("res\\town_road\\town_road_updown.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_right_road, _T("res\\town_road\\town_road_updown_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_town_left_up_floor, _T("res\\town_floor\\town_floor_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_up_floor, _T("res\\town_floor\\town_floor_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_up_floor, _T("res\\town_floor\\town_floor_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_floor, _T("res\\town_floor\\town_floor_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_floor, _T("res\\town_floor\\town_floor_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_middle_floor, _T("res\\town_floor\\town_floor_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_left_down_floor, _T("res\\town_floor\\town_floor_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_down_floor, _T("res\\town_floor\\town_floor_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_right_down_floor, _T("res\\town_floor\\town_floor_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_up_floor, _T("res\\town_floor\\town_floor_leftright_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_floor, _T("res\\town_floor\\town_floor_leftright.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_leftright_down_floor, _T("res\\town_floor\\town_floor_leftright_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_left_floor, _T("res\\town_floor\\town_floor_updown_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_floor, _T("res\\town_floor\\town_floor_updown.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_town_updown_right_floor, _T("res\\town_floor\\town_floor_updown_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);

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

	loadimage(&img_event_left_up, _T("res\\event\\event_left_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_up, _T("res\\event\\event_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_left_down, _T("res\\event\\event_left_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_right_up, _T("res\\event\\event_right_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_right, _T("res\\event\\event_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_right_down, _T("res\\event\\event_right_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_left, _T("res\\event\\event_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_middle, _T("res\\event\\event_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_event_down, _T("res\\event\\event_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_player_1, _T("res\\player\\player_1.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_player_2, _T("res\\player\\player_2.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_chest, _T("res\\chest\\chest.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_skull, _T("res\\monster\\skull.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_goblin, _T("res\\monster\\goblin.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_slime, _T("res\\monster\\slime.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_orc, _T("res\\monster\\orc.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_dragon, _T("res\\monster\\dragon.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_skeleton, _T("res\\monster\\skeleton2.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_vampire, _T("res\\monster\\vampire.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_witch, _T("res\\monster\\witch.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_ghost, _T("res\\monster\\ghost.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_werewolf, _T("res\\monster\\werewolf.png"), LENGTH_PIXIV, LENGTH_PIXIV);

	loadimage(&img_tree, _T("res\\grass\\tree.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_door, _T("res\\town_floor\\door.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_door_0, _T("res\\town_floor\\door_0.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_left_chair, _T("res\\town_floor\\left_chair.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_right_chair, _T("res\\town_floor\\right_chair.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_table, _T("res\\town_floor\\table.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_light, _T("res\\town_floor\\light.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_fountain, _T("res\\town_floor\\fountain.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_carpet, _T("res\\town_floor\\carpet.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_food_sold, _T("res\\town_floor\\food_sold.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_food_cupboard_0, _T("res\\town_floor\\food_cupboard_0.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_food_cupboard_1, _T("res\\town_floor\\food_cupboard_1.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_leftright, _T("res\\town_floor\\counter_leftright_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_leftright_left, _T("res\\town_floor\\counter_leftright_left.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_leftright_right, _T("res\\town_floor\\counter_leftright_right.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_updown, _T("res\\town_floor\\counter_updown_middle.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_updown_up, _T("res\\town_floor\\counter_updown_up.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_counter_updown_down, _T("res\\town_floor\\counter_updown_down.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_start, _T("res\\status\\start.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_end, _T("res\\status\\end.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_heart_point, _T("res\\GUI\\heart.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_money, _T("res\\GUI\\money_bag.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_food, _T("res\\GUI\\food.png"), LENGTH_PIXIV, LENGTH_PIXIV);
	loadimage(&img_background_forest, _T("res\\background\\background_forest.jpg"),WIDTH,HEIGHT);

	loadimage(&img_speak_left_up, _T("res\\speak\\item_left_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_up, _T("res\\speak\\item_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_right_up, _T("res\\speak\\item_right_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_left, _T("res\\speak\\item_left.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_middle, _T("res\\speak\\item_middle.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_right, _T("res\\speak\\item_right.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_left_down, _T("res\\speak\\item_left_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_down, _T("res\\speak\\item_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_speak_right_down, _T("res\\speak\\item_right_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);

	loadimage(&img_item_left_up, _T("res\\Item\\Item_left_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_up, _T("res\\Item\\Item_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_right_up, _T("res\\Item\\Item_right_up.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_left, _T("res\\Item\\Item_left.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_middle, _T("res\\Item\\Item_middle.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_right, _T("res\\Item\\Item_right.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_left_down, _T("res\\Item\\Item_left_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_down, _T("res\\Item\\Item_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_right_down, _T("res\\Item\\Item_right_down.png"), LENGTH_PIXIV * 2, LENGTH_PIXIV * 2);
	loadimage(&img_item_equip, _T("res\\Item\\Item_equip.png"), LENGTH_PIXIV * 2+14, LENGTH_PIXIV * 2);

	loadimage(&img_gadget_sword, _T("res\\gadgets\\sword.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5 );
	loadimage(&img_gadget_bow, _T("res\\gadgets\\bow.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5);
	loadimage(&img_gadget_cursedstone, _T("res\\gadgets\\cursedstone.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5 );
	loadimage(&img_gadget_shield, _T("res\\gadgets\\shield.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5 );
	loadimage(&img_gadget_telescroll, _T("res\\gadgets\\telescroll.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5 );
	loadimage(&img_gadget_healpotion, _T("res\\gadgets\\healpotion.png"), LENGTH_PIXIV*1.5 , LENGTH_PIXIV*1.5 );
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
	sprintf_s(heart_point, "/%d", player->get_health());
	char Max_heart_point[10];
	sprintf_s(Max_heart_point, "%d", player->get_maxHealth());
	char level[20];
	sprintf_s(level, "level:%d", player->get_level());
	char exp[10];
	sprintf_s(exp, "%d", player->get_exp());
	char upexp[10];
	sprintf_s(upexp, "/%d", player->get_levelUpExp());
	char attack[10];
	sprintf_s(attack, "%d", player->get_attack());
	char defense[10];
	sprintf_s(defense, "%d", player->get_defense());
	char speed[10];
	sprintf_s(speed, "%d", player->get_speed());
	char Max_food[10];
	sprintf_s(Max_food, "%d", player->get_food_capacity());
	char money_point[10];
	sprintf_s(money_point, "%d", player->get_coin());
	char food_point[10];
	sprintf_s(food_point, "/%d", player->get_food());
	int x, y;
	for (x = 0; x < 35; x++)   //ÉÏ·½
	{
		for (y = 0; y < 4; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left_up);
			else if (x == 0 && y != 0 && y != 3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left);
			else if (x != 0 && y == 0 && x != 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_up);
			else if (x == 0 && y == 3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_left_down);
			else if (x == 34 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right_up);
			else if (x == 34 && y == 3)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right_down);
			else if (x != 34 && y == 3 && x != 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_down);
			else if (x == 34 && y != 3 && y != 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_GUI_middle);
		}
	}
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 31; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_left_up);
			else if (x == 0 && y != 0 && y != 30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_left);
			else if (x != 0 && x != 3 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_up);
			else if (x == 0 && y == 30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_left_down);
			else if (x == 3 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_right_up);
			else if (x == 3 && y == 30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_right_down);
			else if (x != 0 && x != 3 && y == 30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_down);
			else if (x == 3 && y != 0 && y != 30)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y + 64, &img_GUI_middle);
		}
	}
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "Î¢ÈíÑÅºÚ");
	int w_h = textwidth(Max_heart_point);
	int w_f = textwidth(Max_food);
	int w_e = textwidth(exp);
	putimage_alpha(LENGTH_PIXIV * 0 + 8, LENGTH_PIXIV * 0 + 8, &img_heart_point);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 0 + 8, Max_heart_point);
	outtextxy(LENGTH_PIXIV * 1 + 8 + w_h, LENGTH_PIXIV * 0 + 8, heart_point);
	putimage_alpha(LENGTH_PIXIV * 0 + 8, LENGTH_PIXIV * 1 + 8, &img_money);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 1 + 8, money_point);
	putimage_alpha(LENGTH_PIXIV * 0 + 8, LENGTH_PIXIV * 2 + 8, &img_food);
	outtextxy(LENGTH_PIXIV * 1 + 8, LENGTH_PIXIV * 2 + 8, Max_food);
	outtextxy(LENGTH_PIXIV * 1 + 8 + w_f, LENGTH_PIXIV * 2 + 8, food_point);
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 4 + 8, level);
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 5 + 8, "exp:");
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 6 + 8, exp);
	outtextxy(LENGTH_PIXIV * 0 + 1 + w_e, LENGTH_PIXIV * 6 + 8, upexp);

	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 8 + 8, "Attack");
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 9 + 8, attack);
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 10 + 8, "Defense");
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 11 + 8, defense);
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 12 + 8, "Speed");
	outtextxy(LENGTH_PIXIV * 0 + 1, LENGTH_PIXIV * 13 + 8, speed);
}

void speak_paint()
{
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * (2*x+7), LENGTH_PIXIV * (2*y+7), &img_speak_left_up);
			else if(x==0&&y==2)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_left_down);
			else if(x==11&&y==0)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_right_up);
			else if(x==11&&y==2)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_right_down);
			else if(x==0&&y!=0&&y!=2)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_left);
			else if(x==11&&y!=0&&y!=2)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_right);
			else if(x!=0&&x!=11&&y==0)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_up);
			else if(x!=0&&x!=11&&y==2)putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_down);
			else putimage_alpha(LENGTH_PIXIV * (2*x + 7), LENGTH_PIXIV * (2*y + 7), &img_speak_middle);
		}
	}
}
void item_paint()
{
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_left_up);
			else if (x == 0 && y == 3)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_left_down);
			else if (x == 0 && y != 0&&y!=3)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_left);
			else if (x == 6)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_equip);
			else if (x == 5 && y == 0)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_right_up);
			else if (x == 5 && y == 3)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_right_down);
			else if (x != 0 &&x!=6&& y == 0)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_up);
			else if (x == 5 && y != 0&&y!=3)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_right);
			else if (x != 0 && x != 5 && y == 3)putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_down);
			else putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_item_middle);
		}
		
	}
}

void gadgets_paint(int index, int num)
{
	int x = index % 6;
	int y = index / 6;
	char gadgets_num[10];
	sprintf_s(gadgets_num, "%d", num);
	if (index == 0)
	{
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_sword);
		outtextxy(LENGTH_PIXIV * (2 * x + 11)+1 , LENGTH_PIXIV * (2 * y + 11)+1 , gadgets_num);
	}
	else if (index == 1)
	{
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_shield);
		outtextxy(LENGTH_PIXIV * (2 * x + 11) + 1, LENGTH_PIXIV * (2 * y + 11) + 1, gadgets_num);
	}
	else if (index == 2)
	{
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_healpotion);
		outtextxy(LENGTH_PIXIV * (2 * x + 11) + 1, LENGTH_PIXIV * (2 * y + 11) + 1, gadgets_num);
	}
	else if (index == 3)
	{
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_cursedstone);
		outtextxy(LENGTH_PIXIV * (2 * x + 11) + 1, LENGTH_PIXIV * (2 * y + 11) + 1, gadgets_num);
	}
	else if (index == 4) 
	{ 
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_bow); 
		outtextxy(LENGTH_PIXIV * (2 * x + 11) + 1, LENGTH_PIXIV * (2 * y + 11) + 1, gadgets_num);
	}
	else if (index == 5) 
	{
		putimage_alpha(LENGTH_PIXIV * (2 * x + 10), LENGTH_PIXIV * (2 * y + 10), &img_gadget_telescroll);
		outtextxy(LENGTH_PIXIV * (2 * x + 11) + 1, LENGTH_PIXIV * (2 * y + 11) + 1, gadgets_num);
	}
}

void Message_paint()
{
	for (int x = 35; x < 47; x++)
	{
		for (int y = 0; y < 35; y++)
		{
			if (x == 35 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left_up);
			else if (x == 35 && y != 0 && y != 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left);
			else if (x != 35 && x != 46 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_up);
			else if (x == 35 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_left_down);
			else if (x == 46 && y == 0)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_right_up);
			else if (x == 46 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y, &img_Message_right_down);
			else if (x != 35 && x != 46 && y == 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_down);
			else if (x == 46 && y != 0 && y != 34)putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_right);
			else putimage_alpha(LENGTH_PIXIV * x, LENGTH_PIXIV * y , &img_Message_middle);
		}
	}
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "Î¢ÈíÑÅºÚ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 0 + 8, "Welcome to game!");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 2 + 8, "        UP       ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 3 + 8, "        W        ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 4 + 8, "LEFT  A S D  RIGHT");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 5 + 8, "       DOWN      ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 7 + 8, "        E        ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 8 + 8, "Open the backpack");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 10 + 8, "       ESC       ");
	outtextxy(LENGTH_PIXIV * 35 + 8, LENGTH_PIXIV * 11 + 8, "    Game Option  ");
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
	putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_dragon);
}
void Monster_paint(int x, int y, int type)
{
	switch (type)
	{
	case 0:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_skull);
		break;
	case 1:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_goblin);
		break;
	case 2:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_slime);
		break;
	case 3:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_orc);
		break;
	case 4:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_dragon);
		break;
	case 5:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_skeleton);
		break;
	case 6:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_vampire);
		break;
	case 7:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_witch);
		break;
	case 8:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_ghost);
		break;
	case 9:
		putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_werewolf);
		break;
	default:
		std::cerr << "Unknown monster type: " << type << std::endl;
		break;
	}
}

void Button_paint(int count, std::vector<Button*> button)
{
	char options[10];
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "Î¢ÈíÑÅºÚ");
	int w;
	for (int x = 0; x < 12; x++)  //»æÖÆÁÄÌì¿ò
	{
		for (int y = 0; y < 20; y++)
		{
			if (x == 0 && y == 0)putimage_alpha(LENGTH_PIXIV * (x+12), LENGTH_PIXIV * (y+8), &img_event_left_up);
			else if (x == 0 && y != 0 && y != 19)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_left);
			else if (x != 0 && x != 11 && y == 0)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_up);
			else if (x == 0 && y == 19)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_left_down);
			else if (x == 11 && y == 0)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_right_up);
			else if (x == 11 && y == 19)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_right_down);
			else if (x != 0 && x != 11 && y == 19)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_down);
			else if (x == 11 && y != 0 && y != 19)putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_right);
			else putimage_alpha(LENGTH_PIXIV * (x + 12), LENGTH_PIXIV * (y + 8), &img_event_middle);
		}
	}
	outtextxy(LENGTH_PIXIV * (0 + 15)+2, LENGTH_PIXIV * (0 + 8)+4, "Event name");
	outtextxy(LENGTH_PIXIV * (0 + 12) + 2, LENGTH_PIXIV * (1 + 8) + 4, "Description");
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j == 0)
			{
				putimage_alpha(LENGTH_PIXIV * (j + 12)+8, LENGTH_PIXIV * ((3*i-1) + 18), &img_event_left_up);
				putimage_alpha(LENGTH_PIXIV * (j + 12) + 8, LENGTH_PIXIV * ((3 * i) + 18), &img_event_left_down);
			}
			else if (j == 10)
			{
				putimage_alpha(LENGTH_PIXIV * (j + 12) + 8, LENGTH_PIXIV * ((3 * i -1) + 18), &img_event_right_up);
				putimage_alpha(LENGTH_PIXIV * (j + 12) + 8, LENGTH_PIXIV * ((3 * i ) + 18), &img_event_right_down);
			}
			else
			{
				putimage_alpha(LENGTH_PIXIV * (j + 12) + 8, LENGTH_PIXIV * ((3 * i - 1) + 18), &img_event_up);
				putimage_alpha(LENGTH_PIXIV * (j + 12) + 8, LENGTH_PIXIV * ((3 * i) + 18), &img_event_down);
			}
		}
		/*sprintf_s(options, "%d:", i + 1);
		int d_n = textwidth(options);
		outtextxy(LENGTH_PIXIV * (0 + 12) + 2, LENGTH_PIXIV * (i+3 + 8) + 4, options);
		outtextxy(LENGTH_PIXIV * (0 + 12) + 2+d_n, LENGTH_PIXIV * (i + 3 + 8) + 4, _T(button[i]->getDescription().c_str()));*/
	}
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
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					}
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == 0 && y == h - 1)
				{
					Tile* tile_right_up = scene->get_tiles(x + 1, y - 1);
					if (tile_right_up->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					}
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == w - 1 && y == h - 1)
				{
					Tile* tile_left_up = scene->get_tiles(x - 1, y - 1);
					if (tile_left_up->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					}
					else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_wall);
				}
				else if (x == w - 1 && y == 0)
				{
					Tile* tile_left_down = scene->get_tiles(x - 1, y + 1);
					if (tile_left_down->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					}
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
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_left_wall);
					}

					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() != WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() == WALL_TILE
						&& tile_right_up->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_right_wall);
					else if (tile_left->get_type() == WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() != WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_right_down->get_type() != WALL_TILE)
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_wall);
					else if (tile_left->get_type() != WALL_TILE && tile_up->get_type() == WALL_TILE && tile_right->get_type() == WALL_TILE && tile_down->get_type() != WALL_TILE
						&& tile_left_down->get_type() != WALL_TILE)
					{
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_wall);
					}
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
						putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_base);
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
void Town_scene_paint(int width, int height, Position pos)
{
	int x, y;
	//»­²Ý
	for (x = 1; x < 14; x++)
	{
		for (y = 1; y < 9; y++)
		{
			if (x == 13 && y != 8)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right);
			else if (x != 1 && y == 8)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_down);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_middle);
		}
	}
	for (x = 16; x < 30; x++)
	{
		y = 8;
		if (x != 21 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_updown);
		else if (x == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_updown_right);
	}
	for (x = 24; x < 30; x++)
	{
		for (y = 11; y < 21; y++)
		{
			if (x == 24 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_up);
			else if (x == 24 && y == 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_down);
			else if (x == 29 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_up);
			else if (x == 29 && y == 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_down);
			else if (x == 24 && y != 11 && y != 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left);
			else if (x == 29 && y != 11 && y != 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right);
			else if (y == 11 && x != 24 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_up);
			else if (y == 20 && x != 24 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_down);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_middle);
		}
	}
	for (x = 11; x < 16; x++)
	{
		for (y = 21; y < 24; y++)
		{
			if (x == 11 && y == 21)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_up);
			else if (x == 11 && y == 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_down);
			else if (x == 15 && y == 21)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_up);
			else if (x == 15 && y == 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_down);
			else if (x == 11 && y != 21 && y != 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left);
			else if (x == 15 && y != 21 && y != 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right);
			else if (y == 21 && x != 11 && x != 15)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_up);
			else if (y == 23 && x != 11 && x != 15)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_down);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_middle);
		}
	}
	for (x = 7; x < 9; x++)
	{
		for (y = 28; y < 30; y++)
		{
			if (x == 7 && y == 28)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_up);
			else if (x == 7 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_down);
			else if (x == 8 && y == 28)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_up);
			else if (x == 8 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_down);
		}
	}
	for (x = 1; x < 9; x++)
	{
		for (y = 11; y < 24; y++)
		{
			if (x == 1 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_up);
			else if (x == 1 && y == 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_down);
			else if (x == 8 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_up);
			else if (x == 1 && y != 11 && y != 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left);
			else if (x == 8 && y != 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right);
			else if (y == 11 && x != 1 && x != 8)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_up);
			else if (y == 23 && x != 1 && x != 7 && x != 8)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_down);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_middle);
		}
	}
	for (x = 7; x < 9; x++)
	{
		for (y = 24; y < 27; y++)
		{
			if (x == 7 && y == 26)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left_down);
			else if (x == 7 && y != 26)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_left);
			else if (x == 8 && y == 26)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right_down);
			else if (x == 8 && y != 26)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_grass_right);
		}
	}
	//»­·¿¼äµØ°å
	for (x = 17; x < 30; x++)
	{
		for (y = 1; y < 7; y++)
		{
			if (x == 17 && y == 1)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_up_floor);
			else if (x == 17 && y == 6)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_floor);
			else if (x == 29 && y == 1)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_up_floor);
			else if (x == 29 && y == 6)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_floor);
			else if (x == 17 && y != 1 && y != 6)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_floor);
			else if (x == 29 && y != 1 && y != 6)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_floor);
			else if (y == 1 && x != 17 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_floor);
			else if (y == 6 && x != 17 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_floor);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_floor);
		}
	}
	for (x = 17; x < 30; x++)
	{
		for (y = 22; y < 30; y++)
		{
			if (x == 17 && y == 22)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_up_floor);
			else if (x == 17 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_floor);
			else if (x == 29 && y == 22)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_up_floor);
			else if (x == 29 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_floor);
			else if (x == 17 && y != 22 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_floor);
			else if (x == 29 && y != 22 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_floor);
			else if (y == 22 && x != 17 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_floor);
			else if (y == 29 && x != 17 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_floor);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_floor);
		}
	}
	for (x = 12; x < 16; x++)
	{
		for (y = 25; y < 30; y++)
		{
			if (x == 12 && y == 25)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_up_floor);
			else if (x == 12 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_floor);
			else if (x == 15 && y == 25)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_up_floor);
			else if (x == 15 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_floor);
			else if (x == 12 && y != 25 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_floor);
			else if (x == 15 && y != 25 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_floor);
			else if (y == 25 && x != 12 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_floor);
			else if (y == 29 && x != 12 && x != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_floor);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_floor);
		}
	}
	putimage_alpha(LENGTH_PIXIV * 16 + 64, LENGTH_PIXIV * 29 + 64, &img_town_updown_floor);
	for (x = 1; x < 6; x++)
	{
		for (y = 25; y < 30; y++)
		{
			if (x == 1 && y == 25)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_up_floor);
			else if (x == 1 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_floor);
			else if (x == 5 && y == 25)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_up_floor);
			else if (x == 5 && y == 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_floor);
			else if (x == 1 && y != 25 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_floor);
			else if (x == 5 && y != 25 && y != 29)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_floor);
			else if (y == 25 && x != 1 && x != 5)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_floor);
			else if (y == 29 && x != 1 && x != 5)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_floor);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_floor);
		}
	}
	putimage_alpha(LENGTH_PIXIV * 6 + 64, LENGTH_PIXIV * 27 + 64, &img_town_updown_floor);

	//»­³ÇÕòµÀÂ·
	for (x = 14; x < 16; x++)
	{
		for (y = 1; y < 9; y++)
		{
			if (x == 14)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_road);
			else if (x == 15)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_road);
		}
	}
	for (x = 1; x < 30; x++)
	{
		for (y = 9; y < 11; y++)
		{
			if (y == 9)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_road);
			else if (y == 10)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_road);
		}
	}
	for (x = 22; x < 24; x++)
	{
		for (y = 11; y < 21; y++)
		{
			if (x == 22)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_road);
			else if (x == 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_road);
		}
	}
	for (x = 9; x < 11; x++)
	{
		for (y = 11; y < 30; y++)
		{
			if (x == 9)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_road);
			else if (x == 10)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_road);
		}
	}
	for (x = 11; x < 22; x++)
	{
		for (y = 11; y < 21; y++)
		{
			if (x == 11 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_up_road);
			else if (x == 11 && y == 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_down_road);
			else if (x == 21 && y == 11)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_up_road);
			else if (x == 21 && y == 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_down_road);
			else if (x == 11 && y != 11 && y != 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_left_road);
			else if (x == 21 && y != 11 && y != 20)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_right_road);
			else if (y == 11 && x != 11 && x != 21)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_up_road);
			else if (y == 20 && x != 11 && x != 21)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_down_road);
			else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_town_middle_road);
		}
	}
	// »­ÃÅ

	if (pos.x == 21 && pos.y == 7)putimage_alpha(LENGTH_PIXIV * 21 + 64, LENGTH_PIXIV * 7 + 64, &img_town_leftright_floor);
	else putimage_alpha(LENGTH_PIXIV * 21 + 64, LENGTH_PIXIV * 7 + 64, &img_door);
	if (pos.x == 22 && pos.y == 21) putimage_alpha(LENGTH_PIXIV * 22 + 64, LENGTH_PIXIV * 21 + 64, &img_town_leftright_floor);
	else putimage_alpha(LENGTH_PIXIV * 22 + 64, LENGTH_PIXIV * 21 + 64, &img_door);
	if (pos.x == 23 && pos.y == 21) putimage_alpha(LENGTH_PIXIV * 23 + 64, LENGTH_PIXIV * 21 + 64, &img_town_leftright_floor);
	else putimage_alpha(LENGTH_PIXIV * 23 + 64, LENGTH_PIXIV * 21 + 64, &img_door);

	if (pos.x != 16 || pos.y != 29)putimage_alpha(LENGTH_PIXIV * 16 + 64, LENGTH_PIXIV * 29 + 64, &img_door_0);
	if (pos.x != 6 || pos.y != 27)putimage_alpha(LENGTH_PIXIV * 6 + 64, LENGTH_PIXIV * 27 + 64, &img_door_0);


	//²¹³äÐ¡¾¶
	putimage_alpha(LENGTH_PIXIV * 21 + 64, LENGTH_PIXIV * 8 + 64, &img_town_leftright_base);
	putimage_alpha(LENGTH_PIXIV * 7 + 64, LENGTH_PIXIV * 27 + 64, &img_town_updown_base);
	putimage_alpha(LENGTH_PIXIV * 8 + 64, LENGTH_PIXIV * 27 + 64, &img_town_updown_base);

	//·¿¼äÄÚÊÎ
	putimage_alpha(LENGTH_PIXIV * 16 + 64, LENGTH_PIXIV * 16 + 64, &img_fountain);
	putimage_alpha(LENGTH_PIXIV * 20 + 64, LENGTH_PIXIV * 7 + 64, &img_food_sold);

	for (x = 17; x < 23; x++)
	{
		y = 0;
		if ((x & 2) == 0)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_food_cupboard_0);
		else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_food_cupboard_1);
	}
	for (x = 17; x < 24; x++)
	{
		y = 2;
		if (x == 17)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_counter_leftright_left);
		else if (x == 23)putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_counter_leftright_right);
		else putimage_alpha(LENGTH_PIXIV * x + 64, LENGTH_PIXIV * y + 64, &img_counter_leftright);
	}

	putimage_alpha(LENGTH_PIXIV * 26 + 64, LENGTH_PIXIV * 2 + 64, &img_left_chair);
	putimage_alpha(LENGTH_PIXIV * 27 + 64, LENGTH_PIXIV * 2 + 64, &img_table);
	putimage_alpha(LENGTH_PIXIV * 28 + 64, LENGTH_PIXIV * 2 + 64, &img_right_chair);

	putimage_alpha(LENGTH_PIXIV * 26 + 64, LENGTH_PIXIV * 4 + 64, &img_left_chair);
	putimage_alpha(LENGTH_PIXIV * 27 + 64, LENGTH_PIXIV * 4 + 64, &img_table);
	putimage_alpha(LENGTH_PIXIV * 28 + 64, LENGTH_PIXIV * 4 + 64, &img_right_chair);

	putimage_alpha(LENGTH_PIXIV * 26 + 64, LENGTH_PIXIV * 6 + 64, &img_left_chair);
	putimage_alpha(LENGTH_PIXIV * 27 + 64, LENGTH_PIXIV * 6 + 64, &img_table);
	putimage_alpha(LENGTH_PIXIV * 28 + 64, LENGTH_PIXIV * 6 + 64, &img_right_chair);

	//»æÖÆnpc
	putimage_alpha(LENGTH_PIXIV * 19 + 64, LENGTH_PIXIV * 1 + 64, &img_food_npc);
}