#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1)
	{
		num2 = n2;
	}
};

