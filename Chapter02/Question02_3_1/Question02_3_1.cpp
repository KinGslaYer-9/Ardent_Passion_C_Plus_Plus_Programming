#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void)
{
	Point* pos1 = new Point;
	Point* pos2 = new Point;

	pos1->xpos = 5;
	pos1->ypos = 6;

	pos2->xpos = 3;
	pos2->ypos = 5;

	Point& result = PntAdder(*pos1, *pos2);

	cout << "xpos: " << result.xpos << endl;
	cout << "ypos: " << result.ypos << endl;

	delete pos1, pos2, result;
	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* _result = new Point;

	_result->xpos = p1.xpos + p2.xpos;
	_result->ypos = p1.ypos + p2.ypos;

	return *_result;
}