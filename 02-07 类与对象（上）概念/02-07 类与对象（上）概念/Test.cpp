#include <iostream>
using namespace std;


//// 类
//struct Stack
//{
//	// 成员函数
//	void Init(int n)
//	{
//		// ...
//	}
//
//	// 成员变量
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
	int _year; // 声明（没有开辟空间）
	int _month;
	int _day;
};

//// 指定了Init函数属于Date域
//void Date::Init(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}

int main()
{
	//// Date._year = 2023;// err
	//Date d1;// 类的实例化
	//cout << sizeof(d1) << endl;

	Date d1, d2;
	d1.Init(2022, 1, 11);
	d2.Init(2022, 1, 12);
	d1.Print();
	d2.Print();

	// 编译报错 崩溃 正常运行
	Date* ptr = nullptr;

	//ptr->Init(2023, 2, 7);// 崩溃
	ptr->Print();// 正常运行
	(*ptr).Print();// 正常运行

	// Print()函数不存在对象中，寻找时需要在公共区域中找。
	// 使用Init时不崩溃，但是在this解引用的时候就会发生崩溃。


	return 0;
}

// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
}; // 4

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};// 1

// 类中什么都没有---空类
class A3
{};// 1