#include <iostream>

int main(void)
{
	int inputNum, result = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "��° ���� �Է�: ";
		std::cin >> inputNum;
		result += inputNum;
	}

	std::cout << "�հ�: " << result << std::endl;
	return 0;
}