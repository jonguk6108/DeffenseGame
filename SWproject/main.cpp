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
//poker class
#include "poker.h"
//tower class
#include "tower.h"
//bullet class
#include "bullet.h"

using namespace std;

char select_menu(void);
void start_game(void);
void show_manual(void);
void game_over(void);
void show_map(void);
void print_select(int x, int y);

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

// 첫 시작 실행창이며, 입력 받은 값에 따라 메뉴를 이동시킴
char select_menu(void)
{
	system("cls");
	ColorSet(black, brightyellow);

	for (int i = 0; i < CARDPOINTX + (CARDX + 4) * 5 + 3; i++)
		cout << "*";

	ColorSet(black, white);
	cout << "\n";
	cout << "Welcome!! ctrl+마우스 휠을 이용하셔서 글자를 작게 해주시고\n";
	cout << "창 크기를 마우스 드래그로 늘려주세요!!\n\n";

	cout << "Press 1 to start game!!\n";
	cout << "Press 2 to see manual!!\n";
	cout << "Press 3 to exit the game!!\n";


	char c;
	cin >> c;
	return c;
}

void show_map(void)
{
	//system("cls");
	for (int i = 0; i < MAPX; i++)
		for (int j = 0; j < MAPY; j++)
			print_map(i, j);
}

void print_select(int x, int y) {
	int tx = 0;
	int ty = 0;
	ColorSet(green, white);
	for (tx = 0; tx < MAPX - 2; tx++)
		for (ty = 0; ty < MAPY - 2; ty++) {
			for (int i = 0; i < TILEY - 2; i++) {
				gotoxy(TILEX * (tx + 1) + 2, TILEY * (ty + 1) + 1 + i);
				if (i == 0 || i == TILEY - 3)
					for (int j = 0; j < TILEX - 4; j++)
						cout << " ";
				else {
					cout << "  ";
					gotoxy(TILEX * (tx + 1) + 2 + TILEX - 6, TILEY * (ty + 1) + 1 + i);
					cout << "  ";
				}
			}
		}

	gotoxy(0, 0);
	if (x == -1 && y == -1)
		return;
	tx = x;
	ty = y;

	ColorSet(gray, white);
	for (int i = 0; i < TILEY - 2; i++) {
		gotoxy(TILEX * (tx + 1) + 2, TILEY * (ty + 1) + 1 + i);
		if (i == 0 || i == TILEY - 3)
			for (int j = 0; j < TILEX - 4; j++)
				cout << " ";
		else {
			cout << "  ";
			gotoxy(TILEX * (tx + 1) + 2 + TILEX - 6, TILEY * (ty + 1) + 1 + i);
			cout << "  ";
		}
	}
	ColorSet(black, white);
}

// 첫 스타트 화면
void start_game(void)
{
	int round = 1;
	// round
	int tower_map[MAPX - 2][MAPY - 2] = {0,};
	vector <class tower> t;
	while (1)
	{
		int generate_time = 30;
		int monster_number_max = 10;
		int monster_number = 0;
		int wait_time_max = 500;
		int wait_time = 0;
		int monster_type_num = 10;

		ColorSet(black, white);
		gotoxy(0, 0);
		for (int space = 0; space < 260; space++)
			cout << " ";
		gotoxy(121, 0);
		cout << "               ";
		gotoxy(121, 1);
		cout << "               ";
		gotoxy(119, 1);
		ColorSet(black, brightyellow);
		cout << "**";
		ColorSet(black, white);
		cout << "  Round : " << round << "  ";
		ColorSet(black, brightyellow);
		cout << "**";
		gotoxy(119, 0);
		cout << "*****************";
		gotoxy(119, 2);
		cout << "*****************";
		ColorSet(black, white);
		for (int space = 0; space < 110; space++)
			cout << " ";

		// phase 1, generate tower

		// poker
		gotoxy(0, 0);
		ColorSet(black, white);
		cout << "                                ";
		gotoxy(0, 0);
		cout << "Poker time!";
		int rank = poker();
		
		// show map
		show_map();

		gotoxy(0, 0);
		ColorSet(black, white);
		cout << "                                ";
		gotoxy(0, 0);
		cout << "Select tower position!";

		// tower print
		for (int i = 0; i < t.size(); i++)	t[i].print_tower();

		int x, y;
		while (1)
		{
			x = (MAPX - 2) / 2;
			y = (MAPY - 2) / 2;
			int key;
			while (1) {
				print_select(x, y);
				key = _getch();
				if (key == 'a') {    //left (a)
					if (x == 0) {
						x = MAPX - 3;
						continue;
					}
					x--;
				}
				if (key == 'd') {    //right (d)
					if (x == MAPX - 3) {
						x = 0;
						continue;
					}
					x++;
				}
				if (key == 'w') {    //up (w)
					if (y == 0) {
						y = MAPY - 3;
						continue;
					}
					y--;
				}
				if (key == 's') {    //down (s)
					if (y == MAPY - 3) {
						y = 0;
						continue;
					}
					y++;
				}
				if (key == 32) {        //finished space
					break;
				}
			}
			print_select(-1, -1);
			Sleep(500);

			if (x >= 0 && x < MAPX - 2 && y >= 0 && y < MAPY - 2 && tower_map[x][y] == 0)	break;
			if (x >= 0 && x < MAPX - 2 && y >= 0 && y < MAPY - 2 && tower_map[x][y])
			{
				gotoxy(0, TILEY * MAPY);
				ColorSet(black, white);
				cout << "Will you remove the tower and make a new one? (y/n): ";
				char answer;
				cin >> answer;
				if (answer == 'y')
				{
					for (size_t j = 0; j < t.size(); j++)
					{
						if (t[j].get_original_x() == x && t[j].get_original_y() == y)
							t.erase(t.begin() + j);
					}
					break;
				}
			}

			gotoxy(0, TILEY * MAPY);
			cout << "                                                                       ";
			ColorSet(black, white);
		}
		// make tower
		class tower tower_tmp(rank, x, y);
		t.push_back(tower_tmp);
		tower_map[x][y] = rank;

		// tower print
		for (int i = 0; i < t.size(); i++)	t[i].print_tower();

		// phase 2, generate monster and remove
		int i = 0;
		vector<class monster> m;
		vector<class bullet> b;

		gotoxy(0, 0);
		ColorSet(black, white);
		cout << "                                              ";
		gotoxy(0, 0);
		cout << "Kill them all !!!";

		while(1)
		{
			// frame time
			clock_t start, end;
			start = clock();

			// generate monster
			if (monster_number == monster_number_max)
			{
				wait_time++;
				if (m.size() == 0)				break;
				if (wait_time > wait_time_max)	return;
			}
			else if (i % generate_time == 0 && monster_number < monster_number_max)
			{
				monster_number++;
				class monster m_tmp(round);
				m.push_back(m_tmp);
			}
			
			// delete previous bullet
			for (size_t j = 0; j < b.size(); j++)
			{
				int x = b[j].getx();
				int y = b[j].gety();
				int color_a, color_b;
				
				if (x > TILEX && y > TILEY &&
					x < (MAPX - 1) * TILEX && y < (MAPY - 1) * TILEY &&
					tower_map[x / TILEX - 1][y / TILEY - 1] &&
					(x % TILEX) > 3 && (x % TILEX) < (TILEX - 4) &&
					(y % TILEY) > 1 && (y % TILEY) < (TILEY - 2))
				{
					color_a = get_tower_color(tower_map[x / TILEX - 1][y / TILEY - 1] - 1, (x % TILEX) - 4, (y % TILEY) - 2);
				}
				else	color_a = get_map_color(x, y);

				if ((x + 1) > TILEX && y > TILEY &&
					(x + 1) < (MAPX - 1) * TILEX && y < (MAPY - 1) * TILEY &&
					tower_map[(x + 1) / TILEX - 1][y / TILEY - 1] &&
					((x+1) % TILEX) > 3 && ((x+1) % TILEX) < (TILEX - 4) &&
					(y % TILEY) > 1 && (y % TILEY) < (TILEY - 2))
				{
					color_b = get_tower_color(tower_map[(x+1) / TILEX - 1][y / TILEY - 1] - 1, ((x+1) % TILEX) - 4, (y % TILEY) - 2);
				}
				else	color_b = get_map_color(x+1, y);

				//color_b = get_map_color(x + 1, y);

				b[j].pre_frame_bullet(color_a, color_b);
			}

			// minus bullet time && monster hp down
			vector<class bullet>::iterator it_bullet;
			for (it_bullet = b.begin(); it_bullet != b.end();)
			{
				int t = (*it_bullet).get_time();
				if (t <= 0)
				{
					int a = (*it_bullet).get_attack();
					int m_idx = (*it_bullet).get_monster_index();
					int m_hp = m[m_idx].get_hp();
					m[m_idx].set_hp(m_hp - a);
					it_bullet = b.erase(it_bullet);
				}
				else
				{
					(*it_bullet).set_time(t - 1);
					it_bullet++;
				}
			}

			// delete monsters && bullets
			vector<class monster>::iterator it_monster;
			for (it_monster = m.begin(); it_monster != m.end();)
			{
				if ((*it_monster).get_hp() <= 0)
				{
					int m_idx = distance(m.begin(), it_monster);
					vector<class bullet>::iterator it_bullet;
					for (it_bullet = b.begin(); it_bullet != b.end();)
					{
						if ((*it_bullet).get_monster_index() == m_idx)			it_bullet = b.erase(it_bullet);
						else if ((*it_bullet).get_monster_index() > m_idx)		(*it_bullet).set_monster_index((*it_bullet).get_monster_index() - 1);
						else													it_bullet++;
					}
					(*it_monster).delete_monster();
					it_monster = m.erase(it_monster);
				}
				else	it_monster++;
			}

			// tower throw bullets
			for (size_t j = 0; j < t.size(); j++)
			{
				int l = t[j].get_latency();
				int tx = t[j].getx();
				int ty = t[j].gety();
				if (l == 0)
				{
					if (m.size() == 0)	continue;
					int min_index = 0;
					int min = 9999999;
					for (size_t k = 0; k < m.size(); k++)
					{
						int mx = m[k].getx();
						int my = m[k].gety();
						int dis = (tx - mx) * (tx - mx) + 4 * (ty - my) * (ty - my);
						if (min > dis)
						{
							min = dis;
							min_index = k;
						}
					}

					if (min < t[j].get_range())
					{
						int predict_x, predict_y;
						m[min_index].predict_moving_monster(2, predict_x, predict_y);
						class bullet bullet_tmp(tx, ty, predict_x, predict_y, min_index, t[j].get_power());
						b.push_back(bullet_tmp);
						t[j].set_latency(t[j].get_main_latency());
					}
				}
				else			t[j].set_latency(l-1);
			}

			// moving monster, eliminate previous frame monster, print monster
			for (size_t j = 0; j < m.size(); j++)
			{
				if (m[j].get_latency() == 0)
				{
					m[j].moving_monster();
					m[j].pre_frame_monster();
					m[j].print_monster();
					m[j].set_latency(m[j].get_max_latency());
				}
				else	m[j].set_latency(m[j].get_latency() - 1);
			}

			for (size_t j = 0; j < b.size(); j++)
				b[j].bullet_print();

			while (1)
			{
				end = clock();
				if ((double)(end - start) >= 100)	break;
			}

			i++;
		}

		round++;
	}
}

// game_over창
void game_over(void)
{
	while (1)
	{
		ColorSet(black, white);
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