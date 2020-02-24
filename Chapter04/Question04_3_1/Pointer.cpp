#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int x, int y)
{
	xpos = x;
	ypos = y;
}

void Point::ShowPointInfo() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}