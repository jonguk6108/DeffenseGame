//�üҽ�3 �ǽ�
//��Ŀ Ÿ�� ���潺
//�̽���, ������
//2021-11-20

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>

//data
#include "data.h"
//�� (Ÿ��)�� ����ϸ�, ��ũ��� Ÿ�� ũ�⿡ ���� ������ ����.
#include "tile.h"
//����Ʈ�ϴ� ��ġ �Լ� gotoxy�� ������ �����ϰ� ������, ��� ������ ���� ǥ����.
#include "print_cout.h"
//���� class
#include "monster.h"

using namespace std;

char select_menu(void);
void start_game(void);
void show_manual(void);
void game_over(void);

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
			game_over();
			break;
		case MANUAL:
			show_manual();
			break;
		case QUIT:
			return 0;
		}
	}
}

// ù ���� ����â�̸�, �Է� ���� ���� ���� �޴��� �̵���Ŵ
char select_menu(void)
{
	system("cls");
	cout << "Welcome!! ctrl+���콺 ���� �̿��ϼż� ���ڸ� �۰� ���ֽð�\n";
	cout << "â ũ�⸦ ���콺 �巡�׷� �÷��ּ���!!\n\n";

	cout << "Press 1 to start game!!\n";
	cout << "Press 2 to see manual!!\n";
	cout << "Press 3 to exit the game!!\n";

	char c;
	cin >> c;
	return c;
}

// ù ��ŸƮ ȭ��
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
		int generate_time = 20;
		int monster_number_max = 10;
		int monster_number = 0;
		int wait_time_max = 30;
		int wait_time = 0;
		int monster_type_num = 1;

		//phase 2, generate tower

		//phase 3, generate monster and remove
		int i = 0;
		vector<class monster> m;
		while(1)
		{
			// generate monster
			if (monster_number == monster_number_max)
			{
				wait_time++;
				if (wait_time > wait_time_max)	return;
			}
			else if (i % generate_time == 0 && monster_number < monster_number_max)
			{
				monster_number++;
				class monster m_tmp(round % monster_type_num);
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
			i++;
		}

		round++;
	}
}

// game_overâ
void game_over(void)
{
	while (1)
	{
		system("cls");
		cout << "GAME OVER!!\n";
		cout << "press 1 button to return the start screen\n";

		char c = '0';
		cin >> c;
		if (c == '1')	break;
		else			continue;
	}
	return;
}

// �Ŵ����� ������
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