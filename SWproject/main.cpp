//시소실3 실습
//포커 타워 디펜스
//이승태, 박종욱
//2021-11-20

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>

//data
#include "data.h"
//맵 (타일)을 출력하며, 맵크기와 타일 크기에 대한 정보를 가짐.
#include "tile.h"
//프린트하는 위치 함수 gotoxy의 정보를 내장하고 있으며, 출력 글자의 색을 표시함.
#include "print_cout.h"
//몬스터 class
#include "monster.h"

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

// 첫 시작 실행창이며, 입력 받은 값에 따라 메뉴를 이동시킴
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

// 첫 스타트 화면
void start_game(void)
{
	// phase 1
	system("cls");
	for(int i = 0; i < MAPX; i++)
		for(int j = 0; j < MAPY; j++)
			print_map(i, j);

	int round = 1;
	// round
	while (1)
	{

		//phase 2

		//phase 3
		vector<class monster> m;
		for (int i = 0; i < 500; i++)
		{
			// generate monster
			if (i % 20 == 0)
			{
				class monster m_tmp(round % 1);
				m.push_back(m_tmp);
			}

			// eliminate previous frame monster
			for (size_t j = 0; j < m.size(); j++)
				m[j].pre_frame_monster();

			// monster moving
			for (size_t j = 0; j < m.size(); j++)
				m[j].moving_monster();

			// monster print
			for (size_t j = 0; j < m.size(); j++)
				m[j].print_monster();

			Sleep(100);
		}

		round++;
	}
}

// 매뉴얼을 설명함
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