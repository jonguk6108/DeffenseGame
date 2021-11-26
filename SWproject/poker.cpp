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
				cout << " wrong input (이미 한 번 바꾸셨음)";
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
		cout << "포커페이즈 끝 rank : " << rank;
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
		1	탑 : 숫자가 이어지지 않고 같은 숫자가 없는 경우
		2	원페어 : 똑같은 숫자가 2개인 경우 (= K탑)
		3	투페어 : 똑같은 숫자인 2개 + 똑같은 숫자인 2개 o
		4	트리플 : 똑같은 숫자 3개 o
		5	풀하우스 : 똑같은 숫자2개 + 똑같은 숫자 3개 o
		6	스트레이트 : 이어지는 숫자 5개 o
		7	포카드 : 똑같은 숫자 4개 o
		8	플러쉬 : 똑같은 색깔 5개 o
		9	스트레이트 플러쉬 : 이어지는 숫자, 같은 색깔 5개 o
		10	로얄 스트레이트 플러쉬 : 10, J, Q, K, A, 같은 색 o
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
	// 0개 1개, 2개, 3개,4개
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