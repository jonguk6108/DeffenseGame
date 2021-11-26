#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#include "poker.h"
#include "print_cout.h"
#include "data.h"

using namespace std;
/* 0 1 2 3 4 5 6 7 8  9 10 11 12 */
/* A 2 3 4 5 6 7 8 9 10  J  Q  K */
int cards[5][3];
int card_num[13] = { 0, };
int card_color[4] = { 0, };
int check_rank();

int poker() {
	system("cls");

	int dack[13 * 4];
	int dack_size = 14 * 4;
	srand(time(NULL));

	for (int i = 0; i < 14 * 4; i++)
		dack[i] = i;

	for (int i = 0; i < 5; i++) {
		int dack_num = rand() % (dack_size--);
		cards[i][0] = dack[dack_num] / 4;
		cards[i][1] = dack[dack_num] % 4;
		cards[i][2] = 1;
	}

	//choose card lists
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++)
			if (cards[i][2] == 0)
				cnt++;
		if (cnt == 5) {
			cout << "\nfinished\n";
			break;
		}

		for (int i = 0; i < 5; i++) cout << i << " num : " << cards[i][0] << " color : " << cards[i][1] << " chance : " << cards[i][2] << "\n";
		cout << "Select change cards number, if you do not change cards, input is 5\n";
		char num;
		cin >> num;
		
		if (num < '0' || num > '5') {
			cout << " wrong input ";
			continue;
		}
		if (num == '5') {
			cout << "\nfinished\n";
			break;
		}
		else {
			if (cards[num - '0'][2] == 0) {
				cout << " wrong input (�̹� �� �� �ٲټ���)";
				continue;
			}
			int dack_num = rand() % (dack_size--);
			cards[num - '0'][0] = dack[dack_num] / 4;
			cards[num - '0'][1] = dack[dack_num] % 4;
			cards[num - '0'][2]--;
		}
	}

	//card rank check
	int rank = check_rank();

	while (1) {
		system("cls");
		for (int i = 0; i < 5; i++) cout << i << " num : " << cards[i][0] << " color : " << cards[i][1] << " chance : " << cards[i][2] << "\n";
		cout << "��Ŀ������ �� rank : " << rank;
		Sleep(2000);
	}
	return rank;
}

int check_straight() {
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < 13; i++) {
		if (card_num[i] > 1)
			return 0;
		if (card_num[i] == 1) {
			cnt = 1;
			for (int j = 0; j < 4; j++)
				if (card_num[j % 13] == 1)
					cnt++;
			if (cnt == 5)
				return i;
		}
	}
	return 0;
}

int check_rank() {
	int rank = 0;
	/*
		1	ž : ���ڰ� �̾����� �ʰ� ���� ���ڰ� ���� ���
		2	����� : �Ȱ��� ���ڰ� 2���� ��� (= Kž)
		3	����� : �Ȱ��� ������ 2�� + �Ȱ��� ������ 2�� o
		4	Ʈ���� : �Ȱ��� ���� 3�� o
		5	Ǯ�Ͽ콺 : �Ȱ��� ����2�� + �Ȱ��� ���� 3�� o
		6	��Ʈ����Ʈ : �̾����� ���� 5�� o
		7	��ī�� : �Ȱ��� ���� 4�� o
		8	�÷��� : �Ȱ��� ���� 5�� o
		9	��Ʈ����Ʈ �÷��� : �̾����� ����, ���� ���� 5�� o
		10	�ξ� ��Ʈ����Ʈ �÷��� : 10, J, Q, K, A, ���� �� o
	*/

	for (int i = 0; i < 5; i++) {
		card_num[cards[i][0]]++;
		card_color[cards[i][1]]++;
	}
	int color_cnt = 0;
	for (int i = 0; i < 4; i++)
		if (card_color[i] == 1)
			color_cnt++;

	// 0 , 1,  2,  3,    4
	// 0�� 1��, 2��, 3��,4��
	int num_cnt[5] = { 0, };
	for (int i = 0; i < 13; i++)
		num_cnt[card_num[i]]++;

	if (num_cnt[1] > 0)
		rank = 1;
	for (int i = 0; i < 5; i++)
		if (cards[i][0] == 12)
			rank = 2;
	if (num_cnt[2] > 0)
		rank = 2;
	if (num_cnt[2] > 1)
		rank = 3;
	if (num_cnt[3] > 0)
		rank = 4;
	if (num_cnt[2] > 0 && num_cnt[3] > 0)
		rank = 5;
	if (check_straight() != 0)
		rank = 6;
	if (num_cnt[4] > 0)
		rank = 7;

	if (color_cnt == 4) {
		rank = 8;
		if (check_straight() != 0)
			rank = 9;
		if (check_straight() == 9)
			rank = 10;
	}
	return rank;
}