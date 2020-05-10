#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN		20

void ShowMenu(void);			// 메뉴 출력
void CreateAccount(void);		// 계좌 생성
void DepositMoney(void);		// 입금
void WithdrawMoney(void);		// 출금
void ShowAllAccount(void);		// 모든계좌출력, 잔액조회

namespace BANK_CONTROL_CONST
{
	enum
	{
		CREATE = 1,
		DEPOSIT,
		WITHDRAW,
		INQUIRE,
		EXIT
	};
}

class Account
{
private:
	int _accountID;
	char* _name;
	unsigned int currentMoney;
public:
	Account(int accountID, char* name, int depositMoney);
	Account(const Account& copy);
	~Account();

	int GetAccountID() const;
	char* GetName() const;
	int GetCurrentMoney() const;

	void Deposit(int money);
	int Withdraw(int money);

	void ShowAccInfo() const;
};

Account* accArr[100];
int accCount = 0;

Account::Account(int accountID, char* name, int depositMoney)
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
	if (currentMoney < 0 || currentMoney < money)
		return;

	currentMoney -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << GetAccountID() << endl;
	cout << "이름: " << GetName() << endl;
	cout << "잔액: " << GetCurrentMoney() << endl << endl;
}

int main(void)
{
	int selectMenuNum = 0;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> selectMenuNum;
		cout << endl;

		switch (selectMenuNum)
		{
		case BANK_CONTROL_CONST::CREATE:
			CreateAccount();
			break;
		case BANK_CONTROL_CONST::DEPOSIT:
			DepositMoney();
			break;
		case BANK_CONTROL_CONST::WITHDRAW:
			WithdrawMoney();
			break;
		case BANK_CONTROL_CONST::INQUIRE:
			ShowAllAccount();
			break;
		case BANK_CONTROL_CONST::EXIT:
			return 0;
		default:
			cout << "잘못된 메뉴를 선택하셨습니다" << endl << endl;
		}
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CreateAccount(void)
{
	int id, depositMoney;
	char name[NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	cout << "이름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> depositMoney;

	cout << endl;

	accArr[accCount++] = new Account(id, name, depositMoney);
}

void DepositMoney()
{
	bool isFind = false;
	int accountID, depositMoney, idx;

	cout << "[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "계좌ID를 확인 중 입니다..." << endl;
	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i]->GetAccountID())
		{
			isFind = true;
			idx = i;
			break;
		}
	}

	if (isFind)
	{
		cout << "입금액: ";
		cin >> depositMoney;

		accArr[idx]->Deposit(depositMoney);

		cout << "입금완료" << endl << endl;
		return;
	}

	cout << "ID가 존재하지 않습니다." << endl << endl;
}

void WithdrawMoney()
{
	bool isFind = false;
	int accountID, withdrawMoney, idx;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "계좌ID를 확인 중 입니다..." << endl;
	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i]->GetAccountID())
		{
			isFind = true;
			idx = i;
			break;
		}
	}

	if (isFind)
	{
		cout << "출금액: ";
		cin >> withdrawMoney;

		if (accArr[idx]->Withdraw(withdrawMoney) < 0)
		{
			cout << "잔액이 부족합니다. 출금처리를 종료합니다." << endl;
			return;
		}

		cout << "출금완료" << endl << endl;
		return;
	}

	cout << "ID가 존재하지 않습니다." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}