#include <iostream>
#include <Windows.h>
#include "print_cout.h"
#include "bullet.h"
#include "data.h"

bullet::bullet(int tx, int ty, int mx, int my, int i, int a) : 
	sx(tx), sy(ty), fx(mx), fy(my), time(bullet_time), monster_index(i), attack(a), color(a % 11 + 4) {}

void bullet::bullet_print(void)
{
	int cx = (sx * time + fx * (bullet_time - time)) / bullet_time;
	int cy = (sy * time + fy * (bullet_time - time)) / bullet_time;
	gotoxy(cx, cy);
	ColorSet(color, color);
	std::cout << "  ";
	ColorSet(black, white);
}

void bullet::pre_frame_bullet(int color_a, int color_b)
{
	int cx = (sx * time + fx * (bullet_time - time)) / bullet_time;
	int cy = (sy * time + fy * (bullet_time - time)) / bullet_time;
	gotoxy(cx, cy);
	ColorSet(color_a, color_a);
	std::cout << " ";
	ColorSet(color_b, color_b);
	std::cout << " ";
}

int bullet::get_time(void) { return time; }
int bullet::get_monster_index(void) { return monster_index; }
int bullet::get_attack(void) { return attack; };
int bullet::getx(void) { return (sx * time + fx * (bullet_time - time)) / bullet_time; }
int bullet::gety(void) { return (sy * time + fy * (bullet_time - time)) / bullet_time; }
void bullet::set_time(int t) { time = t; }
void bullet::set_monster_index(int m_idx) { monster_index = m_idx; }
