#pragma once

class bullet {
private:
	int attack;
	int sx, sy;
	int fx, fy;
	int time;
	int color;
	int monster_index;

public:
	bullet(int sx, int sy, int fx, int fy, int i, int a);
	void bullet_print(void);
	void pre_frame_bullet(int color_a, int color_b);
	int get_time(void);
	int get_monster_index(void);
	int get_attack(void);
	int getx(void);
	int gety(void);
	void set_time(int t);
	void set_monster_index(int m_idx);

};