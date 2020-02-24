#include <iostream>
using namespace std;

void IncInt(int&);
void SwitchSign(int&);

int main(void)
{
	int val;

	cout << "정수 입력: ";
	cin >> val;

	IncInt(val);
	cout << "1 증가된 값: " << val << endl;
	SwitchSign(val);
	cout << "부호가 바뀐 값: " << val << endl;
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