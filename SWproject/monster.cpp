#include <iostream>
#include <Windows.h>
#include "monster.h"
#include "print_cout.h"
#include "data.h"

int monster_shape[1][4][MONSTERX][MONSTERY] = {
	//monster type 1
	{
		{
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4}
		},
		{
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4}
		},
		{
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4}
		},
		{
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4},
			{4,4,4,4,4}
		}
	}
};

int px[4] = {0,2,0,-2};
int py[4] = {1,0,-1,0};

monster::monster(int t) : type(t), cx(TILEX/2), cy(TILEY/2 + 1), sx(TILEX/2 - MONSTERX/2), sy(TILEY/2 - MONSTERY/2 + 1)
{
	dir = 0;
	hp = (t + 1) * 10;
	latency = 1;
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
			ColorSet(monster_shape[type][dir][i][j], 0);
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

void monster::pre_frame_monster(void)
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

