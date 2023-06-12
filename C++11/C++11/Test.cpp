#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <assert.h>
using namespace std;
#include "string.h"

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}

// 统一列表初始化
// {}初始化
//int main()
//{
//	int x = 1;
//	int x2 = { 1 };
//	int x3{ 3 }; // 可以省略赋值符号
//	int array1[]{ 1, 2, 3, 4, 5 };
//
//	// C++11中列表初始化也可以适用于new表达式中
//	int* pa = new int[4]{ 0 };
//}

class Date
{
public:
	//explicit Date(int year, int month, int day)
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 }; // explicit
//	return 0;
//}

// std::initializer_list
//int main()
//{
	//vector<int> v1{ 1,2,3,4,5 };  // 这两种是一致的
	//vector<int> v2 = { 10,20,30 }; // 这是在调用使用initializer_list<>的构造函数
	//vector<int> v3 = { 10,20,30,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,1,1,2 };

	//list<int> lt1 = { 1,2,3,4,5 };
	//list<int> lt2 = { 10,20,30 };

	//auto i1 = { 10,20,30,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,1,1,2 };
	//auto i2 = { 10,20,30 };
	//cout << typeid(i1).name() << endl; // class std::initializer_list<int>
	//cout << typeid(i2).name() << endl; // class std::initializer_list<int>

	//initializer_list<int>::iterator it1 = i1.begin();
	//
	////(*it1)++;
	//cout << *it1 << endl; // 不能修改，说明数据存储在常量区

	//Date d1{ 2023, 5, 28 };
	//Date d2{ 2023, 5, 29 };

	//vector<Date> v1 = { d1, d2 };
	//vector<Date> v2 = { Date { 2023, 5, 28 }, Date { 2023, 5, 29 } };

	//Date d3( 2023, 5, 28 );
	//Date d4( 2023, 5, 29 );
	//// initializer_list<Date>
	//vector<Date> v3 = { d3, d4 };
	//vector<Date> v4 = { Date ( 2023, 5, 28 ), Date ( 2023, 5, 29 ) };

	//// 在C++11中我们自己编写的vector有这样的问题：没有实例化的类模板取内嵌类型需要进行typename声明

	//vector<Date> vd3 = { {2023,5,20}, {2023,5,20} }; // 调用Date的构造 + 调用initializer_list构造
	//
	//map<string, string> dict = { {"sort", "排序"},{"string", "字符串"},{"Date", "日期"} };
	//pair<string, string> kv1 = { "Date", "日期" };
	//pair<string, string> kv2 { "Date", "日期" };
//}


// decltype
// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p; // p的类型是int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//
//	// vector存储的类型跟x*y表达式返回值类型一致
//	// decltype推导表达式类型，用这个类型实例化模板参数或者定义对象
//	vector<decltype(x* y)> v;
//	return 0;
//}

// 1. 增加支持initialzer_list的构造接口。使用更方便，有一定的价值
// 2. 增加cbegin与cend系列迭代器的接口
// 3. 移动构造和移动赋值

//左值引用
//int main()
//{
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}
//
//右值引用
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 1; 
//	int* p = &a;
//
//	a + b;
//
//	// 左值引用给左值取别名
//	int& ref1 = a;
//	
//	// 左值引用给右值取别名
//	//int& ref2 = (a + b); err
//	const int& ref = (a + b);
//
//	// 右值引用给右值取别名
//	int&& ref3 = (a + b);
//
//	// 右值引用给左值取别名
//	//int&& ref4 = a; err
//	int&& ref4 = move(a);
//
//	return 0;
//}

//void func(const int& a)
//{
//	cout << "void func(const int& a)" << endl;
//}
//
//void func(int& a)
//{
//	cout << "void func(int& a)" << endl;
//}
//
//void func(int&& a)
//{
//	cout << "void func(int&& a)" << endl;
//}
//
//int main()
//{
//	int a = 0; 
//	int b = 1;
//
//	func(a);
//	func(a + b); // 如果只有左值引用，且临时变量具有常性，那么由于权限的放大是无法进行传递的；如果要进行传递就需要在func的形参中添加const。但是这样的无法对传入的参数是左值还是右值进行区分。有了右值引用就可以将左值与右值进行区分。
//}


int  main()
{
	//右值：纯右值；将亡值
	//左值引用已经将减少拷贝的场景进行处理，右值引用区分左值与右值，然后将右值(将亡值)的资源进行交换
	//左值引用：直接减少拷贝。1.左值引用传参 2.传引用返回(函数类的局部对象不能使用引用返回)

	//zyq::string s1("hello world");
	//zyq::string ret1 = s1;
	//zyq::string ret2 = (s1 + '!');
	
	zyq::string valStr = zyq::to_string(1234);
	return 0;
}