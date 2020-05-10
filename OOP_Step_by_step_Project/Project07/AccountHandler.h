#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accCount = 0;
public:
	void ShowMenu() const;				// 메뉴 출력
	int ChoiceCreateAccount();			// 생성할 계좌의 종류를 선택
	void CreateAccount();				// 계좌 생성
	void DepositMoney();				// 입금
	void WithdrawMoney();				// 출금
	void ShowAllAccount() const;		// 모든계좌출력, 잔액조회
	~AccountHandler();
protected:
	void CreateNormalAccount();			// 보통예금계좌 생성
	void CreateHighCreditAccount();		// 신용신뢰계좌 생성
};

#endif // !__ACCOUNTHANDLER_H__
