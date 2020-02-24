#include <cstring>
#include "Printer.h"

void Printer::SetString(const char* szData)
{
	strcpy_s(str, sizeof(str), szData);
}

void Printer::ShowString()
{
	cout << str << endl;
}