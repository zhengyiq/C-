#include <iostream>
#include <string>
using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	//cout << Division(len, time) << endl;
//	
//	try
//	{
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << "void Func()" << endl;
//		cout << errmsg << endl;
//	}
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...) 
//	{
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}

class Exception
{
public:
	Exception(int errid, const string& msg)
		:_errid(errid)
		,_errmsg(msg)
	{}

	const string& GetMsg() const
	{
		return _errmsg;
	}

	int GetErrid() const
	{
		return _errid;
	}

private:
	int _errid; // 错误码
	string _errmsg; // 错误描述
};

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		//Exception err(1, "除零错误");
		//throw err;
		throw Exception(1, "除零错误");
	}
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	//cout << Division(len, time) << endl;

	try
	{
		cout << Division(len, time) << endl;
	} 
	catch (const Exception& e) // 这里捕获的是err的拷贝; 万能引用只存在于模版中
	{
		cout << "void Func()" << endl;
		cout << e.GetErrid() << endl;
		cout << e.GetMsg() << endl;
	}
	throw 1;
}
int main()
{
	while (1)
	{
		try {
			Func();
		}
		catch (const char* errmsg)
		{
			cout << errmsg << endl;
		}
		catch (...) // 任意类型的异常都可以捕获, 放到最后，防止有一些异常没有捕获，导致程序终止
		{
			cout << "unkown exception" << endl;
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 可以抛出的派生类对象，使用基类捕获 -- 多态
//
//class Exception
//{
//public:
//	Exception(int errid, const string& msg)
//		:_errid(errid)
//		, _errmsg(msg)
//	{}
//
//	const string& GetMsg() const
//	{
//		return _errmsg;
//	}
//
//	int GetErrid() const
//	{
//		return _errid;
//	}
//
//private:
//	int _errid; // 错误码
//	string _errmsg; // 错误描述
//};