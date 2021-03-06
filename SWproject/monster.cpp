#include <iostream>
#include <Windows.h>
#include "monster.h"
#include "print_cout.h"
#include "data.h"

int monster_shape[1][4][MONSTERX][MONSTERY] = {
	//monster type 1
	{
		{
			{7,6,6,6,7},
			{7,7,7,7,7},
			{6,7,7,7,6},
			{6,7,3,3,3},
			{6,7,3,4,3},
			{6,7,3,3,3},
			{6,7,3,4,3},
			{6,7,3,3,3},
			{6,7,7,7,6},
			{7,7,7,7,7},
			{7,6,6,6,7}
		},
		{
			{7,6,6,6,7},
			{7,6,6,6,7},
			{6,7,7,7,6},
			{6,7,7,7,6},
			{6,7,7,7,6},
			{6,3,3,3,6},
			{6,3,3,3,6},
			{6,4,3,4,6},
			{6,4,3,4,6},
			{7,3,3,3,7},
			{7,3,3,3,7}
		},
		{
			{7,6,6,6,7},
			{7,7,7,7,7},
			{6,7,7,7,6},
			{3,3,3,7,6},
			{3,4,3,7,6},
			{3,3,3,7,6},
			{3,4,3,7,6},
			{3,3,3,7,6},
			{6,7,7,7,6},
			{7,7,7,7,7},
			{7,6,6,6,7}
		},
		{
			{7,3,3,3,7},
			{7,3,3,3,7},
			{6,4,3,4,6},
			{6,4,3,4,6},
			{6,3,3,3,6},
			{6,3,3,3,6},
			{6,7,7,7,6},
			{6,7,7,7,6},
			{6,7,7,7,6},
			{7,6,6,6,7},
			{7,6,6,6,7}
		}
	}
};

int px[4] = {0,2,0,-2};
int py[4] = {1,0,-1,0};

monster::monster(int t) : type(t), position(TILEX/2, TILEY/2 + 1, TILEX/2 - MONSTERX/2, TILEY/2 - MONSTERY/2 + 1)
{
	dir = 0;
	hp = t * t * 4 + 15 * t + 5;
	max_latency = 2;
	latency = 2;
}

int monster::get_latency(void) { return latency; }
void monster::set_latency(int l) { latency = l; }

void monster::print_monster(void)
{
	for (int i = 0;i< MONSTERY; i++)
	{
		gotoxy(sx, sy + i);
		for (int j = 0; j < MONSTERX; j++)
		{
			ColorSet((monster_shape[0][dir][j][i] + type) % 15, 0);
			printf(" ");
		}
	}
	ColorSet(0, white);
}

void monster::moving_monster(void)
{
	int EDGE_X1 = TILEX / 2;
	int EDGE_X2 = (MAPX - 1)* TILEX + TILEX / 2;
	int EDGE_Y1 = TILEY / 2;
	int EDGE_Y2 = (MAPY - 1) * TILEY + TILEY / 2;
	if (cx == EDGE_X1 && cy == EDGE_Y1)				dir = 0;
	else if (cx == EDGE_X1 && cy == EDGE_Y2)		dir++;
	else if (cx == EDGE_X2 && cy == EDGE_Y2)		dir++;
	else if (cx == EDGE_X2 && cy == EDGE_Y1)		dir++;

	cx = cx + px[dir];
	cy = cy + py[dir];
	sx = sx + px[dir];
	sy = sy + py[dir];
}

void monster::predict_moving_monster(int n, int &tmp_cx, int &tmp_cy)
{
	int EDGE_X1 = TILEX / 2;
	int EDGE_X2 = (MAPX - 1) * TILEX + TILEX / 2;
	int EDGE_Y1 = TILEY / 2;
	int EDGE_Y2 = (MAPY - 1) * TILEY + TILEY / 2;
	
	int tmp_dir = dir;
	tmp_cx = cx;
	tmp_cy = cy;

	while (n--)
	{
		if (tmp_cx == EDGE_X1 && tmp_cy == EDGE_Y1)				tmp_dir = 0;
		else if (tmp_cx == EDGE_X1 && tmp_cy == EDGE_Y2)		tmp_dir++;
		else if (tmp_cx == EDGE_X2 && tmp_cy == EDGE_Y2)		tmp_dir++;
		else if (tmp_cx == EDGE_X2 && tmp_cy == EDGE_Y1)		tmp_dir++;

		tmp_cx = tmp_cx + px[tmp_dir];
		tmp_cy = tmp_cy + py[tmp_dir];
	}
}

void monster::pre_frame_monster(void)
{
	if (dir == 0)
	{
		gotoxy(sx, sy - 1);
		for (int i = 0; i < MONSTERX; i++)
		{
			ColorSet(pink, 0);
			printf(" ");
		}
	}
	else if (dir == 1)
	{
		for (int i = 0; i < MONSTERY; i++)
		{
			gotoxy(sx - 2, sy + i);
			ColorSet(pink, 0);
			printf("  ");
		}
	}
	else if (dir == 2)
	{
		gotoxy(sx, sy + MONSTERY);
		for (int i = 0; i < MONSTERX; i++)
		{
			ColorSet(pink, 0);
			printf(" ");
		}
	}
	else
	{
		for (int i = 0; i < MONSTERY; i++)
		{
			gotoxy(sx + MONSTERX, sy + i);
			ColorSet(pink, 0);
			printf("  ");
		}
	}
}

void monster::delete_monster(void)
{
	for (int i = 0; i < MONSTERY; i++)
	{
		gotoxy(sx, sy + i);
		for (int j = 0; j < MONSTERX; j++)
		{
			ColorSet(pink, 0);
			printf(" ");
		}
	}
	ColorSet(0, white);
}

int monster::getx(void) { return cx; }
int monster::gety(void) { return cy; }
int monster::get_hp(void) { return hp; }
int monster::get_max_latency(void) { return max_latency; }
void monster::set_hp(int h) { hp = h; }