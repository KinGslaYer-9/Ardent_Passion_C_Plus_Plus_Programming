#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN		20

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

namespace ACCOUNT_TYPE
{
	enum
	{
		NORMAL = 1,
		HIGHCREDIT
	};
}

namespace CREDIT_RATING_INTEREST
{
	enum
	{
		RATING_A = 7,
		RATING_B = 4,
		RATING_C = 2
	};
}

#pragma region Account
class Account
{
private:
	int _accountID;
	char* _name;
	unsigned int currentMoney;
public:
	Account(int accountID, const char* name, int depositMoney);
	Account(const Account& copy);
	~Account();

	int GetAccountID() const;
	char* GetName() const;
	int GetCurrentMoney() const;

	virtual void Deposit(int money);
	int Withdraw(int money);

	void ShowAccInfo() const;
};

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
#pragma endregion

#pragma region NormalAccount
class NormalAccount : public Account
{
private:
	int interestRate;
public:
	NormalAccount(int accountID, const char* name, int depositMoney, double baseInterestRate)
		: Account(accountID, name, depositMoney), interestRate(baseInterestRate)
	{ }
	virtual void Deposit(int money);
};

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * (interestRate / 100.0));
}
#pragma endregion

#pragma region HighCreditAccount
class HighCreditAccount : public NormalAccount
{
private:
	int creditRating;
public:
	HighCreditAccount(int accountID, const char* name, int depositMoney, double baseInterestRate, int credit)
		: NormalAccount(accountID, name, depositMoney, baseInterestRate), creditRating(credit)
	{ }
	virtual void Deposit(int money);
};

void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money);
	Account::Deposit(money * (creditRating / 100.0));
}
#pragma endregion

#pragma region AccountHandler
class AccountHandler
{
private:
	Account* accArr[100];
	int accCount = 0;
public:
	void ShowMenu() const;				// 메뉴 출력
	int ChoiceCreateAccount();			// 생성할 계좌의 종류를 선택
	void CreateAccount();				// 계좌 생성
	void DepositMoney();				// 입금
	void WithdrawMoney();				// 출금
	void ShowAllAccount() const;		// 모든계좌출력, 잔액조회
	~AccountHandler();
protected:
	void CreateNormalAccount();			// 보통예금계좌 생성
	void CreateHighCreditAccount();		// 신용신뢰계좌 생성
};

void AccountHandler::ShowMenu() const
{
	cout << "----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::CreateAccount()
{
	int choice;

	while (true)
	{
		choice = ChoiceCreateAccount();

		switch (choice)
		{
		case ACCOUNT_TYPE::NORMAL:
			CreateNormalAccount();
			return;
		case ACCOUNT_TYPE::HIGHCREDIT:
			CreateHighCreditAccount();
			return;
		default:
			cout << "잘못된 메뉴를 선택하셨습니다. 다시 선택하세요" << endl << endl;
		}
	}
}

int AccountHandler::ChoiceCreateAccount()
{
	int choice;

	cout << "[계좌종류선택]" << endl;
	cout << "1 .보통예금계좌 2 .신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;

	return choice;
}

void AccountHandler::CreateNormalAccount()
{
	char name[NAME_LEN];
	int accountID, depositMoney, interestRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "이  름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> depositMoney;

	cout << "이자율: ";
	cin >> interestRate;

	cout << endl;

	accArr[accCount++] = new NormalAccount(accountID, name, depositMoney, interestRate);
}

void AccountHandler::CreateHighCreditAccount()
{
	char name[NAME_LEN];
	int accountID, depositMoney, interestRate, creditRating;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "이  름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> depositMoney;

	cout << "이자율: ";
	cin >> interestRate;

	while (true)
	{
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> creditRating;

		switch (creditRating)
		{
		case 1:
			accArr[accCount++] = new HighCreditAccount(accountID, name, depositMoney, interestRate, CREDIT_RATING_INTEREST::RATING_A);
			return;
		case 2:
			accArr[accCount++] = new HighCreditAccount(accountID, name, depositMoney, interestRate, CREDIT_RATING_INTEREST::RATING_B);
			return;
		case 3:
			accArr[accCount++] = new HighCreditAccount(accountID, name, depositMoney, interestRate, CREDIT_RATING_INTEREST::RATING_C);
			return;
		default:
			cout << "범위에 없는 등급을 입력하셨습니다. 다시 입력하세요!" << endl;
			break;
		}
	}

	cout << endl;
}

void AccountHandler::DepositMoney()
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

void AccountHandler::WithdrawMoney()
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

void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < accCount; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	delete[] accArr;
}
#pragma endregion

#pragma region Main
int main(void)
{
	AccountHandler control;
	int selectMenuNum = 0;

	while (true)
	{
		control.ShowMenu();
		cout << "선택: ";
		cin >> selectMenuNum;
		cout << endl;

		switch (selectMenuNum)
		{
		case BANK_CONTROL_CONST::CREATE:
			control.CreateAccount();
			break;
		case BANK_CONTROL_CONST::DEPOSIT:
			control.DepositMoney();
			break;
		case BANK_CONTROL_CONST::WITHDRAW:
			control.WithdrawMoney();
			break;
		case BANK_CONTROL_CONST::INQUIRE:
			control.ShowAllAccount();
			break;
		case BANK_CONTROL_CONST::EXIT:
			return 0;
		default:
			cout << "잘못된 메뉴를 선택하셨습니다" << endl << endl;
		}
	}

	return 0;
}
#pragma endregion