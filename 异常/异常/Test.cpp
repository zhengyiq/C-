#include <iostream>
#include <string>
using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
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
	int _errid; // ������
	string _errmsg; // ��������
};

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		//Exception err(1, "�������");
		//throw err;
		throw Exception(1, "�������");
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
	catch (const Exception& e) // ���ﲶ�����err�Ŀ���; ��������ֻ������ģ����
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
		catch (...) // �������͵��쳣�����Բ���, �ŵ���󣬷�ֹ��һЩ�쳣û�в��񣬵��³�����ֹ
		{
			cout << "unkown exception" << endl;
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// �����׳������������ʹ�û��ಶ�� -- ��̬
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
//	int _errid; // ������
//	string _errmsg; // ��������
//};