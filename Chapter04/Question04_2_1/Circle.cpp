#include <iostream>
#include "Circle.h"
using namespace std;

void Circle::Init(int x, int y, int rad)
{
	center.Init(x, y);
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