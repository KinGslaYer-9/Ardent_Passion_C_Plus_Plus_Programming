#pragma once
#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>
using namespace std;

class Printer
{
private:
	char str[50];
public:
	void SetString(const char*);
	void ShowString();
};

#endif // !__PRINTER_H__
