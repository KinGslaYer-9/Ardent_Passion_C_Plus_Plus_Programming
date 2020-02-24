#include <iostream>

int main(void)
{
	int inputNum, result = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> inputNum;
		result += inputNum;
	}

	std::cout << "합계: " << result << std::endl;
	return 0;
}