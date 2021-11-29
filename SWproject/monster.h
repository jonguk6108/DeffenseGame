#pragma once

#include "position.h"

class monster : public position
{
private:
	//center x, y, start x, y
	int hp, latency, max_latency, type, dir;
	
public:
	monster(int t);
	int get_latency(void);
	void set_latency(int l);
	void print_monster(void);
	void moving_monster(void);
	void pre_frame_monster(void);
	void delete_monster(void);
	int getx(void);
	int gety(void);
	int get_hp(void);
	int get_max_latency(void);
	void set_hp(int h);
	void predict_moving_monster(int n, int& tmp_cx, int& tmp_cy);
	
};