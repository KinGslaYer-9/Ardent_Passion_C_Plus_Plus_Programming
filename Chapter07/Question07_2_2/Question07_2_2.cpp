#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;	// å�� ����
	char* isbn;		// ����ǥ�ص�����ȣ
	int price;		// å�� ����
public:
	Book(const char* _title, const char* _isbn, int _price)
		: price(_price)
	{
		int lenTitle = strlen(_title) + 1;
		int lenIsbn = strlen(_isbn) + 1;
		title = new char[lenTitle];
		isbn = new char[lenIsbn];
		strcpy_s(title, lenTitle, _title);
		strcpy_s(isbn, lenIsbn, _isbn);
	}

	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;	// ���Ȱ��� Ű
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		: Book(_title, _isbn, _price)
	{
		int len = strlen(_DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, _DRMKey);
	}

	void ShowEbookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}

	~EBook()
	{
		delete[] DRMKey;
	}
};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();
	return 0;
}