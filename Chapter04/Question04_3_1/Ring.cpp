#include <iostream>
#include "Ring.h"
using namespace std;

Ring::Ring(int innerXpos, int innerYpos, int innerRad, int outterXpos, int outterYpos, int outterRad)
	: innerCircle(innerXpos, innerYpos, innerRad), outterCircle(outterXpos, outterYpos, outterRad)
{
}

void Ring::ShowRingInfo()
{
	cout << "Inner Circle Info..." << endl;
	cout << "radius: ";
	innerCircle.ShowRadius();
	cout << endl;
	innerCircle.ShowCenter();

	cout << "Outter Circle Info..." << endl;
	cout << "radius: ";
	outterCircle.ShowRadius();
	cout << endl;
	outterCircle.ShowCenter();
}