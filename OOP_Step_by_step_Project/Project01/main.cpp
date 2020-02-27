#include <iostream>

#define TRUE		1
#define FALSE		0

using namespace std;

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccount(void);

typedef struct account
{
	int accountID;
	char name[20];
	unsigned int currentMoney;
} Account;

Account accArr[100];
int accCount = 0;

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main(void)
{
	int selectMenuNum = 0;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> selectMenuNum;
		cout << endl;

		if (selectMenuNum == 5)
			break;

		switch (selectMenuNum)
		{
		case CREATE:
			CreateAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccount();
			break;
		case EXIT:
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
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accArr[accCount].accountID;
	cout << "�̸�: ";
	cin >> accArr[accCount].name;
	cout << "�Աݾ�: ";
	cin >> accArr[accCount].currentMoney;
	cout << endl;
	accCount++;
}

void DepositMoney(void)
{
	int isFind = FALSE;
	int accountID, depositMoney, idx;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "����ID�� Ȯ�� �� �Դϴ�..." << endl;
	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i].accountID)
		{
			isFind = TRUE;
			idx = i;
			break;
		}
	}

	if (isFind)
	{
		cout << "�Աݾ�: ";
		cin >> depositMoney;

		accArr[idx].currentMoney += depositMoney;

		cout << "�ԱݿϷ�" << endl << endl;
	}
	else
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	}
}

void WithdrawMoney(void)
{
	int isFind = FALSE;
	int accountID, withdrawMoney, idx;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountID;

	cout << "����ID�� Ȯ�� �� �Դϴ�..." << endl;
	for (int i = 0; i < accCount; i++)
	{
		if (accountID == accArr[i].accountID)
		{
			isFind = TRUE;
			idx = i;
			break;
		}
	}

	if (isFind)
	{
		cout << "��ݾ�: ";
		cin >> withdrawMoney;

		accArr[idx].currentMoney -= withdrawMoney;

		cout << "��ݿϷ�" << endl << endl;
	}
	else
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl << endl;
	}
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		cout << "����ID: " << accArr[i].accountID << endl;
		cout << "�̸�: " << accArr[i].name << endl;
		cout << "�ܾ�: " << accArr[i].currentMoney << endl << endl;
	}
}