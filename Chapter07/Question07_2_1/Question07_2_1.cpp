#include <iostream>
using namespace std;

class Rectangle		// 직사각형
{
private:
	int width;
	int height;
public:
	Rectangle(int _width, int _height)
		: width(_width), height(_height)
	{ }
	void ShowAreaInfo() const
	{
		cout << "면적: " << width * height << endl;
	}
};

class Square : public Rectangle		// 정사각형
{
private:
	int side;
public:
	Square(int _side)
		: Rectangle(_side, _side)
	{ }
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}