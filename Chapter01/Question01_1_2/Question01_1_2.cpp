#include <iostream>

int main(void)
{
	char name[10];
	std::cout << "�̸��� �Է��ϼ���: ";
	std::cin >> name;

	char phoneNum[20];
	std::cout << "��ȭ��ȣ�� �Է��ϼ���: ";
	std::cin >> phoneNum;

	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȭ��ȣ: " << phoneNum << std::endl;
	return 0;
}