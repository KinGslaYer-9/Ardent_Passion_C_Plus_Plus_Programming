#include <iostream>

int main(void)
{
	int salesMoney, salary;

	while (true)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> salesMoney;
		
		if (salesMoney == -1)
			break;

		salary = 50 + salesMoney * 0.12;
		std::cout << "�̹� �� �޿�: " << salary << "����" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	return 0;
}