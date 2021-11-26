#pragma once

class tower {
private:
	int level;
	int power;
	int latency;
	int main_latency;
	int sx, sy;
	int cx, cy;
	int ox, oy;

public:
	tower(int rank, int cx, int cy);
	void print_tower();
	int get_power();
	int get_latency();
	int get_main_latency();
	int getx();
	int gety();
	int get_original_x();
	int get_original_y();
	void set_latency(int l);
};