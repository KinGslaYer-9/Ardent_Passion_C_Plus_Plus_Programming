#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* _name, int _age) : age(_age)
	{
		int len = strlen(_name) + 1;
		name = new char[len];
		strcpy_s(name, len, _name);
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* _name, int _age, const char* _addr, const char* _phone)
		: MyFriendInfo(_name, _age)
	{
		int lenAddr = strlen(_addr) + 1;
		int lenPhone = strlen(_phone) + 1;
		addr = new char[lenAddr];
		phone = new char[lenPhone];
		strcpy_s(addr, lenAddr, _addr);
		strcpy_s(phone, lenPhone, _phone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}
};

int main(void)
{
	MyFriendDetailInfo fri1("Kim", 25, "Seoul", "010-1234-5678");
	fri1.ShowMyFriendDetailInfo();

	return 0;
}