#include <iostream>

int main(void)
{
	int inputNum;
	std::cout << "����� ���� �Է��ϼ���: ";
	std::cin >> inputNum;

	for (int i = 0; i < 9; i++)
		std::cout << inputNum << " * " << i + 1 << " = " << inputNum * (i + 1) << std::endl;

	return 0;
}