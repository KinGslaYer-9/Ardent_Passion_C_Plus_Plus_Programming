#pragma once
#ifndef __RING_H__
#define __RING_H__

#include "Circle.h"

class Ring
{
private:
	Circle innerCircle, outterCircle;
public:
	Ring(int innerXpos, int innerYpos, int innerRad, int outterXpos, int outterYpos, int outterRad);
	void ShowRingInfo();
};

#endif // !__RING_H__
