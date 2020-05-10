#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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

#endif // !__ACCOUNT_H__