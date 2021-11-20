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

// ù ���� ����â�̸�, �Է� ���� ���� ���� �޴��� �̵���Ŵ
char select_menu(void)
{
	system("cls");
	cout << "Welcome!! ctrl+���콺 ���� �̿��ϼż� ���ڸ� �۰� ���ֽð�\n";
	cout << "			â ũ�⸦ ���콺 �巡�׷� �÷��ּ���!!\n";

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