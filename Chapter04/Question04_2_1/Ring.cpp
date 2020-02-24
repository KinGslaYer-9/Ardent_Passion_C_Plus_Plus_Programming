#include <iostream>
#include "Ring.h"
using namespace std;

void Ring::Init(int innerXpos, int innerYpos, int innerRad, int outterXpos, int outterYpos, int outterRad)
{
	innerCircle.Init(innerXpos, innerYpos, innerRad);
	outterCircle.Init(outterXpos, outterYpos, outterRad);
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