#include "tile.h"
#include "print_cout.h"

#include<iostream>
#include<Windows.h>

using namespace std;

class tile {
public:
	tile() {};
	tile(int x_, int y_);
	void print_tile();

private :
	int x = 0, y = 0;
	int t[9][9] =	{
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0}
					};
};

tile::tile(int x_, int y_) {
	x = x_;
	y = y_;
	if (x == 0 || x == 6 || y == 0 || y == 5)
		for (int x1 = 0; x1 < 9; x1++)
			for (int x2 = 0; x2 < 9; x2++)
				t[x1][x2] = 1;
	else {
		for (int x1 = 0; x1 < 9; x1++)
			for (int x2 = 0; x2 < 9; x2++) {
				t[x1][x2] = 2;
				if (x1 == 0 || x1 == 9 || x2 == 0 || x2 == 9)
					t[x1][x2] = 3;
			}
	}
}
void tile::print_tile() {
	int start_x = 9 * x;
	int start_y = 9 * y;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			gotoxy(start_x + i, start_y + j);
			if (t[i][j] == 1)
				ColorSet(pink, pink);
			else if (t[i][j] == 2)
				ColorSet(green, green);
			else if (t[i][j] == 3)
				ColorSet(blue, blue);

			cout << " ";
			ColorSet(0, white);
		}
}

void print() {
	system("cls");
	cout << "Welcome tile.cc!!\n";

	tile tiles[7][6];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6; j++)
			tiles[i][j] = tile(i, j);

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6; j++)
			tiles[i][j].print_tile();

	Sleep(5000);
	return;
}