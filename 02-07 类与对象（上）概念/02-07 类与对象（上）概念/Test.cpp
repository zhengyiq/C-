#include <iostream>
using namespace std;


//// ��
//struct Stack
//{
//	// ��Ա����
//	void Init(int n)
//	{
//		// ...
//	}
//
//	// ��Ա����
//	int *a;
//	int size;
//	int capacity;
//};

class Date
{
public:
	void Init(int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year; // ������û�п��ٿռ䣩
	int _month;
	int _day;
};

//// ָ����Init��������Date��
//void Date::Init(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}

int main()
{
	//// Date._year = 2023;// err
	//Date d1;// ���ʵ����
	//cout << sizeof(d1) << endl;

	Date d1, d2;
	d1.Init(2022, 1, 11);
	d2.Init(2022, 1, 12);
	d1.Print();
	d2.Print();

	// ���뱨�� ���� ��������
	Date* ptr = nullptr;

	//ptr->Init(2023, 2, 7);// ����
	ptr->Print();// ��������
	(*ptr).Print();// ��������

	// Print()���������ڶ����У�Ѱ��ʱ��Ҫ�ڹ����������ҡ�
	// ʹ��Initʱ��������������this�����õ�ʱ��ͻᷢ��������


	return 0;
}

// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1() {}
private:
	int _a;
}; // 4

// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};// 1

// ����ʲô��û��---����
class A3
{};// 1