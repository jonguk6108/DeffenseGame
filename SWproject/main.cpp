#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y);

int main() {
	printf("1221");
	Sleep(2000);
	printf("122122");
	while (1) {
		system("cls");
		gotoxy(5, 2);
		cout << "***********fwqifwq********";
		Sleep(2000);
	}
	return 0;
}



void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}