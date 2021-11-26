// 타일 클래스 (종류는 2가지로 구성됨 : 길, 설치위치
class tile {
public:
	tile();
	tile(int x_, int y_);
	~tile();
	void print_tile();
	int get_tile_color(int x, int y);

private:
	int x, y;
	int** t;
};

void print_map(int x, int y);
int get_map_color(int x, int y);