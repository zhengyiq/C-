#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class B
//{
//public:
//	B(int b  = 2)
//		:_b(b)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _b;
//};
//
//class A
//{
//public:
//
//	// 1、哪个对象调用构造函数初始化列表是所有成员变量定义的位置
//	// 2、不管是否显示在初始化列表写，那么编译器每个变量都会在初始化列表定义初始化
//	A()
//		:_x(1)
//		//, _a1(1)
//		, _a2(1)
//		//, _a2(2) // 每个成员变量只可以在初始化列表中出现一次 
//		, ref(_a1)
//		, _bb(0)
//	{
//		_a1++; // 2
//		_a2--; // 0 没有显示给值就是用缺省值，显示给了值就是用初始化列表中的值。
//	}
//
//	int _a1 = 1; // 声明
//	int _a2 = 2;
//
//	const int _x; // 添加了之后无法生成默认的构造函数，因为const变量必须在定义的时候初始化
//	// 可以使用const int _x = 1;使用缺省参数的方式（C++11)，在C++11之前遇到这样的问题就需要使用初始化列表
//	int& ref;
//	B _bb; // 只能调用默认构造函数
//};
//
//int main()
//{
//	A aa; // 对象整体的定义，每个成员什么时候定义？
//	// 必须给每个成员变量找一个定义的位置，不然像const这样的成员无法初始化
//
//	// const变量必须在定义的时候初始化
//	const int i = 0;
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a) // 后初始化
//		, _a2(_a1) // 先初始化
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl; // 1 随机值
//	}
//private:
//	int _a2; // 先声明
//	int _a1; // 后声明
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}


//class A
//{
//public:
//	/*explicit*/ A(int a, int b)
//		:_a1(a)
//		, _a2(b)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//		, _a2(aa._a2)
//	{
//		cout << "A(const A & aa)" << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	// 单参数构造函数 C++98
//	//A aa1(1); // 构造函数
//	//A aa2 = 1; // 隐式类型转换，产生A类型的临时变量 构造+拷贝+优化->构造
//	//const A& ref = 10;
//
//	// 多参数构造函数 C++11
//	A aa1(1, 2);
//	A aa2 = { 1, 2 };
//	const A& ref = { 2, 2 };
//
//	int i = 0;
//	double d = i; // 隐式类型转换，i中间产生临时变量具有常性,然后转换为double类型
//
//	return 0;
//}

//class A
//{
//public:
//	A() 
//	{ 
//		++_scount; 
//	}
//	
//	A(const A& t) 
//	{ 
//		++_scount; 
//	}
//	~A() 
//	{ 
//		--_scount; 
//	}	
//
//	// 静态成员函数 -- 没有this指针
//	static int GetACount() 
//	{
//		// _a++; // 不能访问非静态成员
//		return _scount; 
//	}
//private:
//	// 不属于某个对象，属于所有对象，属于整个类
//	static int _scount; // 声明
//};
//
//int A::_scount = 0; // 定义初始化
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	A aa4[10];
//	A* ptr = nullptr;
//
//	cout << ptr->GetACount() << endl;
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	cout << A::GetACount() << endl;
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	// d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
//	// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};



//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	// 内部类 -- 跟 A 是独立，只是受A类域限制
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A aa;
//	cout << sizeof(A) << endl; // 只有外部类
//
//	A::B b; // 如果是A类的私有则外部无法访问到B类
//	b.foo(A());
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//A func()
//{
//	int n = 0;
//	cin >> n;
//	int ret = Solution().Sum_Solution(n);
//
//	// 之前通过构建一个对象来返回A类型的值
//	//A retA(ret);
//	//return retA;
//	return A(ret); // 直接通过匿名对象返回
//}
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << endl;
//	}
//};
//int main()
//{
//	// 匿名对象，声明周期只在这一行
//	Solution();
//	cout << Solution().Sum_Solution(1) << endl; // 一次性，临时使用
//
//	return 0;
//}


class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{}

void func2(const A& aa)
{}

//int main()
//{
//	A aa1 = 1; // 构造+拷贝构造->优化为直接构造
//
//	func1(aa1); // 无优化
//	cout << "--------------------" << endl;
//	func1(1); // 构造+拷贝构造->优化为直接构造
//	cout << "--------------------" << endl;
//	func1(A(2)); // 构造+拷贝构造->优化为直接构造
//	cout << "--------------------" << endl;
//	func2(aa1); // 无优化
//	cout << "--------------------" << endl;
//	func2(1); // 无优化
//	cout << "--------------------" << endl;
//	func2(A(2)); // 无优化
//	cout << "--------------------" << endl;
//	return 0;
//}

A func3()
{
	A aa;
	return aa; // 函数体中有一个构造和一个拷贝构造 
}

int main()
{
	func3(); // func3函数语句分在两行可能不会进行优化
	cout << "--------------------" << endl;
	A aa1 = func3(); // 构造+拷贝构造+拷贝构造->构造+拷贝构造
}