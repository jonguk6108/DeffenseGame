#pragma once
class position
{
protected:
	int cx, cy, sx, sy;
public:
	position(int a, int b, int c, int d):cx(a), cy(b), sx(c), sy(d){}
	int get_cx(void) { return cx; }
	int get_cy(void) { return cy; }
	int get_sx(void) { return sx; }
	int get_sy(void) { return sy; }
};