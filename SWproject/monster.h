#pragma once
	
class monster
{
private:
	//center x, y, start x, y
	int cx, cy, sx, sy, hp, latency, type, dir;
	
public:
	monster(int t);
	int get_latency(void);
	void set_latency(int l);
	void print_monster(void);
	void moving_monster(void);
	void pre_frame_monster(void);
};