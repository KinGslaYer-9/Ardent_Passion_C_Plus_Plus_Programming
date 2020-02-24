#include <iostream>
#include <cstring>
#include "NameCard.h"
using namespace std;

void COMP_POS::ShowPositionInfo(int pos)
{
	switch (pos)
	{
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "매니저" << endl;
		break;
	}
}

NameCard::NameCard(const char* name, const char* compName, const char* phoneNum, int position)
	:_position(position)
{
	_name = new char[strlen(name) + 1];
	_compName = new char[strlen(compName) + 1];
	_phoneNum = new char[strlen(phoneNum) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
	strcpy_s(_compName, strlen(compName) + 1, compName);
	strcpy_s(_phoneNum, strlen(phoneNum) + 1, phoneNum);
}

void NameCard::ShowNameCardInfo() const
{
	cout << "이름: " << _name << endl;
	cout << "회사: " << _compName << endl;
	cout << "전화번호: " << _phoneNum << endl;
	cout << "직급: ";
	COMP_POS::ShowPositionInfo(_position);
	cout << endl;
}

NameCard::~NameCard()
{
	delete[] _name;
	delete[] _compName;
	delete[] _phoneNum;
}