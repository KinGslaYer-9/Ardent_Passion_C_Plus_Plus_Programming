#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(int x, int y, int rad)
	: center(x, y)
{
	radius = rad;
}

void Circle::ShowCenter() const
{
	center.ShowPointInfo();
}

void Circle::ShowRadius() const
{
	cout << radius;
}