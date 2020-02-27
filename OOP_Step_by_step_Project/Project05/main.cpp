#include <iostream>
#include <cstring>

#define NAME_LEN		20

using namespace std;

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
	void Withdraw(int money);

	void ShowAccInfo() const;
};

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

void Account::Withdraw(int money)
{
	if (currentMoney < 0 || currentMoney < money)
		return;

	currentMoney -= money;
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << GetAccountID() << endl;
	cout << "�̸�: " << GetName() << endl;
	cout << "�ܾ�: " << GetCurrentMoney() << endl << endl;
}

class AccountHandler
{
private:
	Account* accArr[100];
	int accCount = 0;
public:
	void ShowMenu() const;				// �޴� ���
	void CreateAccount();				// ���� ����
	void DepositMoney();				// �Ա�
	void WithdrawMoney();				// ���
	void ShowAllAccount() const;		// ���������, �ܾ���ȸ
	~AccountHandler();
};

void AccountHandler::ShowMenu() const
{
	cout << "----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::CreateAccount()
{
	int id, depositMoney;
	char name[NAME_LEN];

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;

	cout << "�̸�: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> depositMoney;

	cout << endl;

	accArr[accCount++] = new Account(id, name, depositMoney);
}

void AccountHandler::DepositMoney()
{
	bool isFind = false;
	int accountID, depositMoney, idx;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "����ID�� Ȯ�� �� �Դϴ�..." << endl;
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
		cout << "�Աݾ�: ";
		cin >> depositMoney;

		accArr[idx]->Deposit(depositMoney);

		cout << "�ԱݿϷ�" << endl << endl;
	}
	else
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	}
}

void AccountHandler::WithdrawMoney()
{
	bool isFind = false;
	int accountID, withdrawMoney, idx;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "����ID�� Ȯ�� �� �Դϴ�..." << endl;
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
		cout << "��ݾ�: ";
		cin >> withdrawMoney;

		accArr[idx]->Withdraw(withdrawMoney);

		cout << "��ݿϷ�" << endl << endl;
	}
	else
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	}
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

int main(void)
{
	AccountHandler control;
	int selectMenuNum = 0;

	while (true)
	{
		control.ShowMenu();
		cout << "����: ";
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
			cout << "�߸��� �޴��� �����ϼ̽��ϴ�" << endl << endl;
		}
	}

	return 0;
}