#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN		20

void ShowMenu(void);			// �޴� ���
void CreateAccount(void);		// ���� ����
void DepositMoney(void);		// �Ա�
void WithdrawMoney(void);		// ���
void ShowAllAccount(void);		// ���������, �ܾ���ȸ

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
	cout << "����ID: " << GetAccountID() << endl;
	cout << "�̸�: " << GetName() << endl;
	cout << "�ܾ�: " << GetCurrentMoney() << endl << endl;
}

int main(void)
{
	int selectMenuNum = 0;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
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
			cout << "�߸��� �޴��� �����ϼ̽��ϴ�" << endl << endl;
		}
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void CreateAccount(void)
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

void DepositMoney()
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
		return;
	}

	cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
}

void WithdrawMoney()
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

		if (accArr[idx]->Withdraw(withdrawMoney) < 0)
		{
			cout << "�ܾ��� �����մϴ�. ���ó���� �����մϴ�." << endl;
			return;
		}

		cout << "��ݿϷ�" << endl << endl;
		return;
	}

	cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}