#include <iostream>

int main(void)
{
	int inputNum;
	std::cout << "출력할 단을 입력하세요: ";
	std::cin >> inputNum;

	for (int i = 0; i < 9; i++)
		std::cout << inputNum << " * " << i + 1 << " = " << inputNum * (i + 1) << std::endl;

	return 0;
}