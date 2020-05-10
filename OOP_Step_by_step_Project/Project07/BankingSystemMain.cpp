#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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