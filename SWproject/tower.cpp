#include <iostream>
#include <Windows.h>
#include "data.h"
#include "tower.h"
#include "print_cout.h"

tower::tower(int rank, int x, int y): level(rank  - 1),
power(rank * 5), latency(1),
ox(x), oy(y),
sx(TILEX* (x + 1) + 4), sy(TILEY* (y + 1) + 2),
cx(TILEX* (x + 1) + TILEX / 2), cy(TILEY* (y + 1) + TILEY / 2)
{
	main_latency = 1 < 5 - rank ? 5 - rank : 1;
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
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4},
		{4,4,4,4,4}
	},
	{
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5}
	},
	{
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6},
		{6,6,6,6,6}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	},
	{
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	}
};

void tower::print_tower()
{
	for (int i = 0; i < TOWERY; i++)
	{
		gotoxy(sx, sy + i);
		for (int j = 0; j < TOWERX; j++)
		{
			ColorSet(tower_shape[level][i][j], 0);
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
void tower::set_latency(int l) { latency = l; }

int get_tower_color(int rank, int x, int y) { return tower_shape[rank][x][y]; }