#pragma once
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"

class Circle
{
private:
	Point center;
	int radius;

public:
	Circle(int x, int y, int rad);
	void ShowCenter() const;
	void ShowRadius() const;
};

#endif // !__CIRCLE_H__
