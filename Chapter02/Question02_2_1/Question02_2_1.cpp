#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	const int* ptr = &num;
	const int* (&pref) = ptr;

	cout << "num: " << *pref << endl;
	return 0;
}