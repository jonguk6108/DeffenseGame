#include<iostream>
#include<Windows.h>
#include "tile.h"
#include "print_cout.h"
#include "data.h"

using namespace std;

tile::tile() : x(0), y(0) {
	t = new int* [TILEX];
	for (int i = 0; i < TILEX; i++)
		t[i] = new int[TILEY];
};

//타일 정의
tile::tile(int x_, int y_) : x(x_), y(y_) {
	t = new int* [TILEX];
	for (int i = 0; i < TILEX; i++)
		t[i] = new int[TILEY];

	if (x == 0 || x == MAPX-1 || y == 0 || y == MAPY-1)
		for (int i = 0; i < TILEX; i++)
			for (int j = 0; j < TILEY; j++) {
				t[i][j] = pink;
				if (x == 0)
					t[0][j] = black;
				else if (x == MAPX -1)
					t[TILEX-1][j] = black;
				if (y == 0)
					t[i][0] = black;
				else if (y == MAPY - 1)
					t[i][TILEY - 1] = black;
			}
	
	else {
		for (int i = 0; i < TILEX; i++)
			for (int j = 0; j < TILEY; j++) {
				t[i][j] = green;
				if (i == 0 || i == TILEX-1 || j == 0 || j == TILEY-1 || i == 1 || i == TILEX - 2)
					t[i][j] = blue;
			}
	}
}

// 타일별 프린트하기
void tile::print_tile() {
	int start_x = TILEX * x;
	int start_y = TILEY * y;

	for (int j = 0; j < TILEY; j++) {
		gotoxy(start_x, start_y + j);
		for (int i = 0; i < TILEX; i++) {
			ColorSet(t[i][j], black);
			cout << " ";
		}
		ColorSet(0, white);
	}
}

//t 동적할당 죽이기
tile::~tile() {
	for (int i = 0; i < TILEX; i++)
		delete[] t[i];
	delete[] t;
}

//원하는 위치의 타일 출력하기
void print_map(int x, int y) {
	tile tiles(x, y);
	tiles.print_tile();
	return;
}
