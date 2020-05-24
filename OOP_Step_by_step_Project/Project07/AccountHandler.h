#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accCount = 0;
public:
	void ShowMenu() const;				// �޴� ���
	int ChoiceCreateAccount();			// ������ ������ ������ ����
	void CreateAccount();				// ���� ����
	void DepositMoney();				// �Ա�
	void WithdrawMoney();				// ���
	void ShowAllAccount() const;		// ���������, �ܾ���ȸ
	~AccountHandler();
protected:
	void CreateNormalAccount();			// ���뿹�ݰ��� ����
	void CreateHighCreditAccount();		// �ſ�ŷڰ��� ����
};

#endif // !__ACCOUNTHANDLER_H__
