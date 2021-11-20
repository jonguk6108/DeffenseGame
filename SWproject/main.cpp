//시소실3 실습
//포커 타워 디펜스
//이승태, 박종욱
//2021-11-20

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>
#include"tile.h"
#include"print_cout.h"

#ifndef MAPX
#define MAPX	7
#define MAPY	6
#define TILEX	16
#define TILEY	8
#endif

using namespace std;

char select_menu(void);
void start_game(void);
void show_manual(void);

enum command
{
	GAMESTART = '1',
	MANUAL,
	QUIT
};

int main()
{
	while (1)
	{
		switch (select_menu())
		{
		case GAMESTART:
			start_game();
			break;
		case MANUAL:
			show_manual();
			break;
		case QUIT:
			return 0;
		}
	}
}

char select_menu(void)
{
	system("cls");
	cout << "Welcome!! ctrl+마우스 휠을 이용하셔서 글자를 작게 해주시고\n";
	cout << "			창 크기를 마우스 드래그로 늘려주세요!!\n";

	cout << "Press 1 to start game!!\n";
	cout << "Press 2 to see manual!!\n";
	cout << "Press 3 to exit the game!!\n";

	char c;
	cin >> c;
	return c;
}

void start_game(void)
{
	system("cls");
	for(int i = 0; i < MAPX; i++)
		for(int j = 0; j < MAPY; j++)
			print_map(i, j);

	while (1) {}
}

void show_manual(void)
{
	while (1)
	{
		system("cls");
		cout << "abcd\n";
		cout << "Press 1 button to return the start screen\n";

		char c = '0';
		cin >> c;
		if (c == '1')	break;
		else			continue;
	}
	return;
}