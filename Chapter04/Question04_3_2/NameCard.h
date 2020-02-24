#pragma once
#ifndef __NAMECARD_H__
#define __NAMECARD_H__

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos);
}

class NameCard
{
private:
	char* _name;
	char* _compName;
	char* _phoneNum;
	int _position;
public:
	NameCard(const char* name, const char* compName, const char* phoneNum, int position);
	void ShowNameCardInfo() const;
	~NameCard();
};

#endif // !__NAMECARD_H__
