#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;	// 책의 제목
	char* isbn;		// 국제표준도서번호
	int price;		// 책의 정가
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
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
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
	char* DRMKey;	// 보안관련 키
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
		cout << "인증키: " << DRMKey << endl;
	}

	~EBook()
	{
		delete[] DRMKey;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();
	return 0;
}