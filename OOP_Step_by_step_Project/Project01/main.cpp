#include <iostream>
using namespace std;

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccount(void);

typedef struct account
{
	int accountNum;
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
			break;
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
	cin >> accArr[accCount].accountNum;
	cout << "�̸�: ";
	cin >> accArr[accCount].name;
	cout << "�Աݾ�: ";
	cin >> accArr[accCount].currentMoney;
	cout << endl;
	accCount++;
}

void DepositMoney(void)
{
	int accountNum, depositMoney;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountNum;

	for (int i = 0; i < accCount; i++)
	{
		if (accountNum == accArr[i].accountNum)
		{
			cout << "�Աݾ�: ";
			cin >> depositMoney;

			accArr[i].currentMoney += depositMoney;

			cout << "�ԱݿϷ�" << endl << endl;
			break;
		}
	}
}

void WithdrawMoney(void)
{
	int accountNum, withdrawMoney;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountNum;

	for (int i = 0; i < accCount; i++)
	{
		if (accountNum == accArr[i].accountNum)
		{
			cout << "��ݾ�: ";
			cin >> withdrawMoney;

			accArr[i].currentMoney -= withdrawMoney;

			cout << "��ݿϷ�" << endl << endl;
			break;
		}
	}
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		cout << "����ID: " << accArr[i].accountNum << endl;
		cout << "�̸�: " << accArr[i].name << endl;
		cout << "�ܾ�: " << accArr[i].currentMoney << endl << endl;
	}
}