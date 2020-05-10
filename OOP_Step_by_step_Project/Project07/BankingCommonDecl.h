#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

#include <iostream>
using namespace std;

#define NAME_LEN		20

namespace BANK_CONTROL_CONST
{
	enum
	{
		CREATE = 1,
		DEPOSIT,
		WITHDRAW,
		INQUIRE,
		EXIT
	};
}

namespace ACCOUNT_TYPE
{
	enum
	{
		NORMAL = 1,
		HIGHCREDIT
	};
}

namespace CREDIT_RATING_INTEREST
{
	enum
	{
		RATING_A = 7,
		RATING_B = 4,
		RATING_C = 2
	};
}

#endif // !__BANKINGCOMMONDECL_H__