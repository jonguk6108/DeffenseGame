#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

void gotoxy(int x, int y);
char select_menu(void);
void start_game(void);
void show_manual(void);
void ColorSet(int backColor, int textColor);

enum command
{
	GAMESTART = '1',
	MANUAL,
	QUIT
};

typedef enum ColorKinds
{
	black,
	blue,
	green,
	skyblue,
	red,
	pink,
	orange,
	white,
	gray,
	lightblue,
	brightgreen,
	sky,
	brightred,
	brightpink,
	brightyellow,
	brightwhite
}ColorKinds;

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
	cout << "Welcome!!\n";
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
	gotoxy(0, 0);
	ColorSet(0, brightyellow);
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	ColorSet(0, blue);
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "Some cyan colored text" << endl;
	ColorSet(0, pink);
	cout << "Add red background" << endl;
	ColorSet(0, orange);
	cout << "reset to default colors with NC" << endl;
	ColorSet(0, white);

	gotoxy(1, 1);
	cout << " hello world ";

	while (1)
	{

	}
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

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void ColorSet(int backColor, int textColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backColor << 4) + textColor);
}