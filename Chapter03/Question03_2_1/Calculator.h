#pragma once
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
using namespace std;

class Calculator
{
private:
	double operand1, operand2;
	double addOpCount, minOpCount, mulOpCount, divOpCount;
public:
	void Init();
	double Add(double, double);
	double Min(double, double);
	double Mul(double, double);
	double Div(double, double);
	void ShowOpCount();
};

#endif // !__CALCULATOR_H__
