#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str1[100] = "AAABBBCCC";
	char str2[100] = "ABABCCC";
	char cpy[50];

	cout << "str1�� ����: " << strlen(str1) << endl;
	strcat_s(str1, sizeof(str1), str2);
	strcpy_s(cpy, sizeof(cpy), str1);
	cout << "str1�� str2�� �����̰� cpy�� ������ ���: " << cpy << endl;
	cout << endl;

	if (strcmp(str1, str2) == 0)
		cout << "str1�� str2�� ���� ���ڿ��Դϴ�." << endl;
	else
		cout << "str1�� str2�� ���� �ʽ��ϴ�." << endl;

	return 0;
}