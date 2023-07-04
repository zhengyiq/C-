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

//class Date
//{
//public:
//	//explicit Date(int year, int month, int day)
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
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


//int  main()
//{
//	//右值：纯右值；将亡值
//	//左值引用已经将减少拷贝的场景进行处理，右值引用区分左值与右值，然后将右值(将亡值)的资源进行交换
//	//左值引用：直接减少拷贝。1.左值引用传参 2.传引用返回(函数类的局部对象不能使用引用返回)
//
//	//zyq::string s1("hello world");
//	//zyq::string ret1 = s1;
//	//zyq::string ret2 = (s1 + '!');
//	
//	//zyq::string valStr = zyq::to_string(1234);
//	//
//	//std::string s1("hello");
//	//std::string s2 = s1;
//	//std::string s3 = move(s1);
//
//	list<zyq::string> lt;
//	
//	lt.push_back(zyq::string("hello world!"));
//	lt.push_back("hello world!");
//	
//	return 0;
//}


//有一点需要注意的就是右值是不能取地址的，但是给右值取别名后，会导致右值被存储到特定位置，且可以取到该位置的地址，也就是说例如：不能取字面量10的地址，但是rr1引用后，可以对rr1取地址，也可以修改rr1。如果不想rr1被修改，可以用const int&& rr1 去引用。
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5; // 报错
//	return 0;
//}

// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//// 万能引用(引用折叠)：既可以引用左值，也可以引用右值
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(move(b)); // const 右值
//	return 0;
//}

#include "List.h"
//
//int main()
//{
//	zyq::list<zyq::string> lt;
//
//	zyq::string s1("hello world");
//	lt.push_back(s1);
//
//	lt.push_back(zyq::string("hello world"));
//	lt.push_back("hello world");
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////

// 左值引用没有解决的问题
// 1.局部对象的返回问题
// 2.插入接口，对象拷贝的问题
// T是自定义类型:
// 1.浅拷贝的类，这里就是拷贝构造，因为对于浅拷贝的类，移动构造是没有什么意义的。
// 2.深拷贝的类，这里就是移动构造，对于深拷贝的类，移动构造可以转移右值的资源，没有拷贝，提高效率。

//int main()
//{
//	zyq::string s1;
//
//	s1 = zyq::to_string(1234);
//	// string(string && s) --移动拷贝 -> 
//	// string& operator=(string s) --深拷贝
//	// string(const string & s) --深拷贝 -> 这里使用的是现代写法复用了拷贝构造的实现
//
//	// 添加了移动拷贝之后的结果
//	// string(string && s) --移动构造
//	// string& operator=(string && s) --移动拷贝
//
//	//zyq::string("hello"); // 调用的是->string(char* str)构造
//
//	//void push_back(const string & s) // 解决了传递临时变量时的生命周期的问题。
//	//{}
//
//	//v.push_back(string("111111"));
//	//v.push_back("111111");
//	// 但是不能够无限的延长生命周期因为变量出了作用域就会调用析构函数进行销毁
//
//	//const string& ref = to_string(1234);
//	//使用const&来进行接收就可以得到生命周期延长的临时变量，传值返回的临时变量生成在上一层栈帧中
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////


//类的新成员
//之前一共有六个默认成员函数
//1.构造函数
//2.析构函数
//3.拷贝构造函数
//4.拷贝赋值重载
//5.取地址重载
//6.const取地址重载
//7.移动构造移动赋值生成条件苛刻
//如果你没有自己实现移动构造函数，且没有实现析构函数 、拷贝构造、拷贝赋值重载中的任意一个。(条件更多了，深拷贝的类，资源转移期望我们自己实现)那么编译器会自动生成一个默认移动构造。默认生成的移动构造函数，对于内置类型成员会执行逐成员按字节拷贝，自定义类型成员，则需要看这个成员是否实现移动构造，如果实现了就调用移动构造，没有实现就调用拷贝构造。


//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{
//		cout << "Person(const char* name = "", int age = 0)" << endl;
//	}
//
//	//Person(const Person& p) = delete;
//
//	//Person(const Person& p)
//	//	:_name(p._name)
//	//	,_age(p._age)
//	//	{}
//
//	//Person& operator=(const Person& p)
//	//{
//	//	if (this != &p)
//	//	{
//	//		_name = p._name;
//	//		_age = p._age;
//	//	}
//	//	return *this;
//	//}
//
//	//Person(Person&& p) = default;
//	//Person& operator=(Person&& p) = default;
//
//	//~Person()
//	//{
//	//	cout << "~Person()" << endl;
//	//}
//private:
//	zyq::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	//Person s3 = std::move(s1);
//	//Person s4;
//	//s4 = std::move(s2);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name, int age)
//		:_name(name)
//		, _age(age)
//	{
//		cout << "Person(const char* name = "", int age = 0)" << endl;
//	}
//
//	// 委托构造，一个构造函数可以复用其他构造函数
//	Person(const Person& p)
//		:Person(name, 18)
//	{}
//
//private:
//	zyq::string _name;
//	int _age;
//};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//可变参数模板
// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{	
//	cout << sizeof...(args) << endl;
//	// 如何解析函数参数包
//	// err
//	//for (int i = 0; i < sizeof...(args); ++i)
//	//{
//	//	cout << args[i] << endl;
//	//}
//	//cout << endl;
//
//
//}

//void ShowList()
//{
//	cout << endl;
//}
//// 递归思维推导
//template <class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << __FUNCTION__ << "(" << sizeof...(args) << ")" << endl;
//	cout << val << " ";
//	ShowList(args...);
//}
//
//int main()
//{
//	//ShowList(1);
//	//ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//}

//void _ShowList()
//{
//	cout << endl;
//}
// 递归思维推导
//template <class T, class ...Args>
//void _ShowList(const T& val, Args... args)
//{
//	cout << __FUNCTION__ << "(" << sizeof...(args) << ")" << endl;
//	cout << val << " ";
//	_ShowList(args...);
//}
//
//template <class ...Args>
//void ShowList(Args... args)
//{
//	_ShowList(args...);
//}
//
//int main()
//{
//	//ShowList(1);
//	//ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//}

//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}
//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//
//	return 0;
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
//// 编译器编译推演生成的代码
////void ShowList(int a1, char a2, std::string a3)
////{
////	int arr[] = { PrintArg(a1), PrintArg(a2), PrintArg(a3) };
////	cout << endl;
////}
//int main()
//{
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

///////////////////////////////////////////////////////////
//STL容器的插入接口都有一个emplace系列
#include "Date.h"
int main()
{
	// 深拷贝的类
	std::list<zyq::string> mylist;
	// 没区别
	/*zyq::string s1("1111");
	mylist.push_back(s1);
	mylist.emplace_back(s1);

	cout << endl;
	zyq::string s2("2222");
	mylist.push_back(move(s1));
	mylist.emplace_back(move(s2));*/

	// 开始有区别
	//cout << endl;
	//mylist.push_back("3333");   // 构造匿名对象 + 移动构造
	//mylist.emplace_back("3333");// 直接构造

	// 浅拷贝的类
	// 没区别
	std::list<Date> list2;
	//Date d1(2023, 5, 28);
	//list2.push_back(d1);
	//list2.emplace_back(d1);

	//cout << endl;
	//Date d2(2023, 5, 28);
	//list2.push_back(move(d1));
	//list2.emplace_back(move(d2));

	// 有区别
	//cout << "=========================" << endl;
	//list2.push_back(Date(2023, 5, 28));
	//list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // 构造+移动构造
	list2.emplace_back(2023, 5, 28);       // 直接构造


	return 0;
}