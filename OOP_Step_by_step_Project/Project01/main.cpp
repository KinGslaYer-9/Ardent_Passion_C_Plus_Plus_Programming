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
		cout << "선택: ";
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CreateAccount(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accArr[accCount].accountNum;
	cout << "이름: ";
	cin >> accArr[accCount].name;
	cout << "입금액: ";
	cin >> accArr[accCount].currentMoney;
	cout << endl;
	accCount++;
}

void DepositMoney(void)
{
	int accountNum, depositMoney;

	cout << "[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;

	for (int i = 0; i < accCount; i++)
	{
		if (accountNum == accArr[i].accountNum)
		{
			cout << "입금액: ";
			cin >> depositMoney;

			accArr[i].currentMoney += depositMoney;

			cout << "입금완료" << endl << endl;
			break;
		}
	}
}

void WithdrawMoney(void)
{
	int accountNum, withdrawMoney;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;

	for (int i = 0; i < accCount; i++)
	{
		if (accountNum == accArr[i].accountNum)
		{
			cout << "출금액: ";
			cin >> withdrawMoney;

			accArr[i].currentMoney -= withdrawMoney;

			cout << "출금완료" << endl << endl;
			break;
		}
	}
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		cout << "계좌ID: " << accArr[i].accountNum << endl;
		cout << "이름: " << accArr[i].name << endl;
		cout << "잔액: " << accArr[i].currentMoney << endl << endl;
	}
}