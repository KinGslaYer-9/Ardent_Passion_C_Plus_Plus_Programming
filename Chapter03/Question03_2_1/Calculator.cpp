#include "Calculator.h"

void Calculator::Init()
{
	addOpCount = minOpCount = mulOpCount = divOpCount = 0;
}

double Calculator::Add(double operand1, double operand2)
{
	addOpCount++;
	return operand1 + operand2;
}

double Calculator::Min(double operand1, double operand2)
{
	minOpCount++;
	return operand1 - operand2;
}

double Calculator::Mul(double operand1, double operand2)
{
	mulOpCount++;
	return operand1 * operand2;
}

double Calculator::Div(double operand1, double operand2)
{
	divOpCount++;
	return operand1 / operand2;
}

void Calculator::ShowOpCount()
{
	cout << "����: " << addOpCount << " "
		<< "����: " << minOpCount << " "
		<< "����: " << mulOpCount << " "
		<< "������: " << divOpCount << endl << endl;
}