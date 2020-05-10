#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int creditRating;
public:
	HighCreditAccount(int accountID, const char* name, int depositMoney, int baseInterestRate, int credit)
		: NormalAccount(accountID, name, depositMoney, baseInterestRate), creditRating(credit)
	{ }
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (creditRating / 100.0));
	}
};

#endif // !__HIGHCREDITACCOUNT_H__
