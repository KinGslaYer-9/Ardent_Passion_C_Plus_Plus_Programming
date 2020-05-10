#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accountID, const char* name, int depositMoney)
	: _accountID(accountID), currentMoney(depositMoney)
{
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
}

Account::Account(const Account& copy)
	: _accountID(copy._accountID), currentMoney(copy.currentMoney)
{
	_name = new char[strlen(copy._name) + 1];
	strcpy_s(_name, strlen(copy._name) + 1, copy._name);
}

Account::~Account()
{
	delete[]_name;
}

int Account::GetAccountID() const
{
	return _accountID;
}

char* Account::GetName() const
{
	return _name;
}

int Account::GetCurrentMoney() const
{
	return currentMoney;
}

void Account::Deposit(int money)
{
	currentMoney += money;
}

int Account::Withdraw(int money)
{
	if (currentMoney < 0)
		return 0;

	currentMoney -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << GetAccountID() << endl;
	cout << "ÀÌ¸§: " << GetName() << endl;
	cout << "ÀÜ¾×: " << GetCurrentMoney() << endl << endl;
}