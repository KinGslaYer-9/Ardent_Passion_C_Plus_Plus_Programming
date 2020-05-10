#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int interestRate;
public:
	NormalAccount(int accountID, const char* name, int depositMoney, int baseInterestRate)
		: Account(accountID, name, depositMoney), interestRate(baseInterestRate)
	{ }
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interestRate / 100.0));
	}
};

#endif // !__NORMALACCOUNT_H__