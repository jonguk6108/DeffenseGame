// Ÿ�� Ŭ���� (������ 2������ ������ : ��, ��ġ��ġ
class tile {
public:
	tile();
	tile(int x_, int y_);
	~tile();
	void print_tile();

private:
	int x, y;
	int** t;
};

void print_map(int x, int y);