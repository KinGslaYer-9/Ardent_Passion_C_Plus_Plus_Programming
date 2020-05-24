#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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