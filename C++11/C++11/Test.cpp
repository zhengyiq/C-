#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

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
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
int main()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret的类型是double
	decltype(&x) p; // p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');

	// vector存储的类型跟x*y表达式返回值类型一致
	// decltype推导表达式类型，用这个类型实例化模板参数或者定义对象
	vector<decltype(x* y)> v;
	return 0;
}

// 1. 增加支持initialzer_list的构造接口。使用更方便，有一定的价值
// 2. 增加cbegin与cend系列迭代器的接口
// 3. 移动构造和移动赋值