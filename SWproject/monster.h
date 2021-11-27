#pragma once
	
class monster
{
private:
	//center x, y, start x, y
	int cx, cy, sx, sy, hp, latency, type, dir, max_latency;
	
public:
	monster(int t);
	int get_latency(void);
	void set_latency(int l);
	void print_monster(void);
	void moving_monster(void);
	void pre_frame_monster(void);
	int getx(void);
	int gety(void);
	int get_hp(void);
	void set_hp(int h);
	void predict_moving_monster(int n, int& tmp_cx, int& tmp_cy);
	
};