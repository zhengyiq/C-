

// #define N 10

// 类型模板参数
// 非类型模板参数 -- 整形常量
//template<class T, size_t N = 10>
//class Array
//{
//public:
//
//private:
//	T _a[N];
//};
//
//template <class T, size_t N = 20>
//void func1(const T& a)
//{
//	//N = 10;
//}

//template <class T, double N = 20>
//void func2(const T& a)
//{
//	//N = 10;
//}

//template <class T, bool flag = true>
//void func3(const T& a)
//{
//	//N = 10;
//}
//
//int main()
//{
//	// 这种方法的问题
//	//Array<int, 10> a1; // 10
//	//Array<double, 100> d2; // 100
//
//	//func1(1);
//
//	int arr[10];
//	array<int, 10> a1;
//	a1[5]++;
//
//	// 抽查越界写
//	//arr[10] = 1; // 会检查到 // err
//	arr[15] = 1; // 不 会检查到 // err
//
//	// 读写全面检查
//	//a1[10]++; // err
//
//	vector<int> v(10, 0);
//	v[10]; // err
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//// 模板特化 -- 对某些类型特殊化处理
//// 全特化
//// 全特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//// 偏特化 -- 进一步限制 算一个新的模板并且要在原来的模板基础上
//template<class T>
//bool Less<T*>(T* left, T* right)
//{
//	return *left < *right;
//}
//
//// 匹配
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	return 0;
//}

// 全特化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}

// 偏特化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 将第二个参数特化为int
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	T1 _d1;
//	int _d2;
//};
//
////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//void test2()
//{
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板
//	Data<int*, int*> d3; // 调用特化的指针版本
//	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
//}

//int main()
//{
//	TestVector();
//	//test2();
//}

#include "Func.h"
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);

	func();
	return 0;
}