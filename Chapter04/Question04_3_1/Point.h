#pragma once
#ifndef __POINT_H__
#define __POINT_H__

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y);
	void ShowPointInfo() const;
};

#endif // !__POINT_H__
