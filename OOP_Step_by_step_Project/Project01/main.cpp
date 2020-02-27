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
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accArr[accCount].accountID;
	cout << "이름: ";
	cin >> accArr[accCount].name;
	cout << "입금액: ";
	cin >> accArr[accCount].currentMoney;
	cout << endl;
	accCount++;
}

void DepositMoney(void)
{
	int isFind = FALSE;
	int accountID, depositMoney, idx;

	cout << "[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "계좌ID를 확인 중 입니다..." << endl;
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
		cout << "입금액: ";
		cin >> depositMoney;

		accArr[idx].currentMoney += depositMoney;

		cout << "입금완료" << endl << endl;
	}
	else
	{
		cout << "ID가 존재하지 않습니다." << endl << endl;
	}
}

void WithdrawMoney(void)
{
	int isFind = FALSE;
	int accountID, withdrawMoney, idx;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountID;

	cout << "계좌ID를 확인 중 입니다..." << endl;
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
		cout << "출금액: ";
		cin >> withdrawMoney;

		accArr[idx].currentMoney -= withdrawMoney;

		cout << "출금완료" << endl << endl;
	}
	else
	{
		cout << "ID가 존재하지 않습니다." << endl << endl;
	}
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accCount; i++)
	{
		cout << "계좌ID: " << accArr[i].accountID << endl;
		cout << "이름: " << accArr[i].name << endl;
		cout << "잔액: " << accArr[i].currentMoney << endl << endl;
	}
}