

//class Date
//{
//public:
//	Date(int year = 2023, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//
//		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
//		{
//			return 29;
//		}
//		else
//		{
//			return monthArray[month];
//		}
//	}
//
//	Date GetAfterXDay(int x)
//	{
//		Date tmp = *this;
//
//		tmp._day += x;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			// 进位
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//			++tmp._month;
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//
//		return tmp;
//	}
//
//	// +
//	Date Add(int x)
//	{
//		Date tmp = *this;
//		tmp._day += x;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			// 进位
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//			++tmp._month;
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//
//		return tmp;
//	}
//
//	// +=
//	Date& AddEqual(int x)
//	{
//		_day += x;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			// 进位
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////int main()
////{
////	Date d1;
////	//Date d2(d1);
////	d1.Print();
////	Date d3 = d1.GetAfterXDay(100); 
////	d3.Print();
////
////	return 0;
////}
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(int capacity = 10)
//	{
//		cout << "Stack(size_t capacity = 10)" << endl;
//
//		_a = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//		
//		_size = 0;
//		_capacity = capacity;
//	}
//		
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_a = (DataType*)malloc(sizeof(DataType)*st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//	
//		memcpy(_a, st._a, sizeof(DataType)*st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_a[_size] = data;
//		_size++;
//	}
//	//...
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	// 成员变量
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//class MyQueue
//{
//public:
//	// 默认生成构造
//	// 默认生成析构
//	// 默认生成拷贝构造
//
//private:
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};
//
//int main()
//{
//	//Stack s1;
//	//s1.Push(1);
//	//Stack s2(s1);
//
//	MyQueue q1;
//	MyQueue q2 = q1;
//
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// 运算符重载
//
//class Date
//{
//public:
//	Date(int year = 2023, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	// 成员函数的operator==, d1 == d2 等价于 d1.operator==(d2)
//	// bool operator==(Date* this, const Date& d2)
//	// 这里需要注意的是，左操作数是this，指向调用函数的对象
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//		//可以将代码简化为:
//		//return (_year < d._year)
//		//	|| (_year == d._year && _month < d._month)
//		//	|| (_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator<=(const Date& d)
//	{
//		return *this == d || *this < d;
//	}
//
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	// 需要支持连续赋值，因此需要有Date类型的返回值
//	Date& operator=(const Date& d)// 可以不添加&，赋值引用不会产生无限递归，传参会调用拷贝构造然后进行赋值操作；但是最好将&添加上。
//	{
//		if (this != &d)// 避免出现 d1 = d1 的现象
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//
//// private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 全局operator==
//bool operator==(const Date& d1, const Date&d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//int main()
//{
//	Date d1(2023, 2, 8);
//	Date d2(2023, 5, 5);
//	Date d3(2023, 9, 9);
//
//	// d1 == d2 - 转换成调用函数operator==(d1, d2);
//	//cout << (d1 == d2) << endl;// 注意运算符的优先级
//	//cout << (d1 < d2) << endl;// 注意运算符的优先级
//
//	d3 = d1 = d2;
//	d3.Print();
//	return 0;
//}
//

#include "Date.h"

void TestDate1()
{
	Date d1(2023, 2, 8);
	d1.Print();

	//Date d2(2023, 2, 29);
	//d2.Print();


	//Date d2 = d1 + 100;
	Date d2 = d1;
	d2 += 10000;
	d1.Print();
	d2.Print();
}

void TestDate2()
{
	Date d1(2023, 2, 8);
	d1.Print();
	d1++;
	d1.Print();	
	d1--;
	d1.Print();

}

void TestDate3()
{
	//Date d1(2023, 2, 8);
	//d1.Print();
	//d1 -= 100;
	//d1.Print();

	Date d1(2023, 2, 8);
	Date d2;
	d1 -= -100;
	d1.Print();
}

void TestDate4()
{
	Date d1(2023, 2, 8);

	Date d2(2024, 2, 8);
	cout << (d1 - d2) << endl;
}

void TestDate5()
{
	// 流插入

	int i = 1;
	double j = 1.22;
	// 运算符重载+函数重载
	cout << i;
	cout << j;

	Date d1(2023, 2, 8);
	//cout << d1;
	Date d2(2024, 2, 8);
	//d1.operator<<(cout);
	//d1 << cout;

	operator<<(cout, d1);
	cout << d1 << d2;
}

void TestDate6()
{
	// 流提取
	Date d1;
	cin >> d1;
	cout << d1;
}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate5();
	TestDate6();

	return 0;
}
