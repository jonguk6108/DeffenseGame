// Ÿ�� Ŭ���� (������ 2������ ������ : ��, ��ġ��ġ
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