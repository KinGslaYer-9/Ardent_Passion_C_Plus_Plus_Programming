#include <iostream>

int main(void)
{
	int salesMoney, salary;

	while (true)
	{
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> salesMoney;
		
		if (salesMoney == -1)
			break;

		salary = 50 + salesMoney * 0.12;
		std::cout << "이번 달 급여: " << salary << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}