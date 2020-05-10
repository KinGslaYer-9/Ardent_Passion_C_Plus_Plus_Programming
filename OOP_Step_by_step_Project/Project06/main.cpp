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
	cout << "����ID: " << GetAccountID() << endl;
	cout << "�̸�: " << GetName() << endl;
	cout << "�ܾ�: " << GetCurrentMoney() << endl << endl;
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
	void ShowMenu() const;				// �޴� ���
	int ChoiceCreateAccount();			// ������ ������ ������ ����
	void CreateAccount();				// ���� ����
	void DepositMoney();				// �Ա�
	void WithdrawMoney();				// ���
	void ShowAllAccount() const;		// ���������, �ܾ���ȸ
	~AccountHandler();
protected:
	void CreateNormalAccount();			// ���뿹�ݰ��� ����
	void CreateHighCreditAccount();		// �ſ�ŷڰ��� ����
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
			cout << "�߸��� �޴��� �����ϼ̽��ϴ�. �ٽ� �����ϼ���" << endl << endl;
		}
	}
}

int AccountHandler::ChoiceCreateAccount()
{
	int choice;

	cout << "[������������]" << endl;
	cout << "1 .���뿹�ݰ��� 2 .�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> choice;

	return choice;
}

void AccountHandler::CreateNormalAccount()
{
	char name[NAME_LEN];
	int accountID, depositMoney, interestRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "��  ��: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> depositMoney;

	cout << "������: ";
	cin >> interestRate;

	cout << endl;

	accArr[accCount++] = new NormalAccount(accountID, name, depositMoney, interestRate);
}

void AccountHandler::CreateHighCreditAccount()
{
	char name[NAME_LEN];
	int accountID, depositMoney, interestRate, creditRating;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "��  ��: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> depositMoney;

	cout << "������: ";
	cin >> interestRate;

	while (true)
	{
		cout << "�ſ���(1toA, 2toB, 3toC): ";
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
			cout << "������ ���� ����� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���!" << endl;
			break;
		}
	}

	cout << endl;
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
		return;
	}

	cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
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
#pragma endregion