#include <iostream>
#include <cstring>

#define NAME_LEN		20

using namespace std;

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

Account* accArr[100];
int accCount = 0;

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
			break;
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

void DepositMoney(void)
{
	int accountID, depositMoney;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i]->GetAccountID())
		{
			cout << "�Աݾ�: ";
			cin >> depositMoney;

			accArr[i]->Deposit(depositMoney);

			cout << "�ԱݿϷ�" << endl << endl;
			break;
		}
		else
		{
			cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
		}
	}
}

void WithdrawMoney(void)
{
	int accountID, withdrawMoney;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i]->GetAccountID())
		{
			cout << "��ݾ�: ";
			cin >> withdrawMoney;

			accArr[i]->Withdraw(withdrawMoney);

			cout << "��ݿϷ�" << endl << endl;
			break;
		}
		else
		{
			cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
		}
	}
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}