#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str1[100] = "AAABBBCCC";
	char str2[100] = "ABABCCC";
	char cpy[50];

	cout << "str1의 길이: " << strlen(str1) << endl;
	strcat_s(str1, sizeof(str1), str2);
	strcpy_s(cpy, sizeof(cpy), str1);
	cout << "str1에 str2를 덧붙이고 cpy에 복사한 결과: " << cpy << endl;
	cout << endl;

	if (strcmp(str1, str2) == 0)
		cout << "str1과 str2는 같은 문자열입니다." << endl;
	else
		cout << "str1과 str2는 같지 않습니다." << endl;

	return 0;
}