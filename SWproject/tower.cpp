#include <iostream>
#include <Windows.h>
#include "data.h"
#include "tower.h"
#include "print_cout.h"

tower::tower(int rank, int x, int y): level(rank  - 1),
power(rank * rank + 3 * rank + 1), latency(1), range(rank * (1100)),
ox(x), oy(y),
position(TILEX* (x + 1) + TILEX / 2, TILEY* (y + 1) + TILEY / 2, TILEX* (x + 1) + 4, TILEY* (y + 1) + 2)
{
	main_latency = 1 < 9 - rank ? 9 - rank : 1;
}

int tower_shape[10][TOWERX][TOWERY] =
{
	{
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3},
		{3,3,3,3,3}
	},
	{
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,5,4,4},
		{4,4,5,4,4},
		{4,5,5,5,4},
		{4,4,5,4,4},
		{4,4,5,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4}
	},
	{
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,6,6,6,5},
		{5,6,6,6,5},
		{5,6,6,6,5},
		{5,6,6,6,5},
		{5,6,6,6,5},
		{5,5,5,5,5},
		{5,5,5,5,5}
	},
	{
		{6,7,6,7,6},
		{7,6,6,6,7},
		{7,7,6,7,7},
		{6,7,7,7,6},
		{7,6,7,6,7},
		{6,7,7,7,6},
		{7,7,6,7,7},
		{7,6,6,6,7},
		{6,7,6,7,6}
	},
	{
		{1,2,3,4,5},
		{2,3,4,5,1},
		{3,4,5,1,2},
		{4,5,1,2,3},
		{5,1,2,3,4},
		{1,2,3,4,5},
		{2,3,4,5,1},
		{3,4,5,1,2},
		{4,5,1,2,3}
	},
	{
		{1,1,1,1,1},
		{1,4,9,4,1},
		{1,4,9,4,1},
		{1,9,9,9,1},
		{1,9,9,9,1},
		{1,9,9,9,1},
		{1,4,9,4,1},
		{1,4,9,4,1},
		{1,1,1,1,1}
	},
	{
		{7,1,7,1,7},
		{7,4,7,4,7},
		{1,4,9,4,1},
		{1,9,8,9,1},
		{1,8,7,8,1},
		{1,9,8,9,1},
		{1,4,9,4,1},
		{7,4,7,4,7},
		{7,1,7,1,7}
	},
	{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,3,0,0},
		{0,0,0,0,0}
	},
	{
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0}
	},
	{
		{0,0,0,0,0},
		{0,0,3,0,0},
		{0,2,0,4,0},
		{0,0,3,0,0},
		{0,2,0,4,0},
		{0,0,3,0,0},
		{0,2,0,4,0},
		{0,0,3,0,0},
		{0,0,0,0,0}
	}
};

void tower::print_tower()
{
	for (int i = 0; i < TOWERY; i++)
	{
		gotoxy(sx, sy + i);
		for (int j = 0; j < TOWERX; j++)
		{
			ColorSet(tower_shape[level][j][i], 0);
			printf(" ");
		}
	}
	ColorSet(0, white);
}

int tower::get_power() { return power; }
int tower::get_latency() { return latency; }
int tower::get_main_latency() { return main_latency; }
int tower::getx() { return cx; }
int tower::gety() { return cy; }
int tower::get_original_x() { return ox; }
int tower::get_original_y() { return oy; }
int tower::get_range() { return range; }
void tower::set_latency(int l) { latency = l; }

int get_tower_color(int rank, int x, int y) { return tower_shape[rank][x][y]; }

void tower_refer(void)
{
	gotoxy(1, MAPY * TILEY + 5);
	printf("tower manual");

	for (int i = 0; i < TOWERY + 2; i++)
	{
		gotoxy(1, MAPY * TILEY + 6 + i);
		for (int j = 0; j < TOWERX * 10 + 31; j++)
		{
			ColorSet(green, green);
			printf(" ");
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < TOWERY; j++)
		{
			gotoxy(3 + (TOWERX + 3) * i, MAPY * TILEY + 7 + j);
			for (int k = 0; k < TOWERX; k++)
			{
				ColorSet(tower_shape[i][k][j], tower_shape[i][k][j]);
				printf(" ");
			}
		}
	}
}