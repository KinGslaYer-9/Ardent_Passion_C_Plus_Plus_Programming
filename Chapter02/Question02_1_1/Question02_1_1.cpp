#include <iostream>
using namespace std;

void IncInt(int&);
void SwitchSign(int&);

int main(void)
{
	int val;

	cout << "���� �Է�: ";
	cin >> val;

	IncInt(val);
	cout << "1 ������ ��: " << val << endl;
	SwitchSign(val);
	cout << "��ȣ�� �ٲ� ��: " << val << endl;
	return 0;
}

void IncInt(int& ref)
{
	ref++;
}

void SwitchSign(int& ref)
{
	ref *= -1;
}