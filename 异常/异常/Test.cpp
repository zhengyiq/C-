#include <iostream>
#include <string>
#include <thread>
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

//class Exception
//{
//public:
//	Exception(int errid, const string& msg)
//		:_errid(errid)
//		,_errmsg(msg)
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
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		//Exception err(1, "�������");
//		//throw err;
//		throw Exception(1, "�������");
//	}
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
//	catch (const Exception& e) // ���ﲶ�����err�Ŀ���; ��������ֻ������ģ����
//	{
//		cout << "void Func()" << endl;
//		cout << e.GetErrid() << endl;
//		cout << e.GetMsg() << endl;
//	}
//	throw 1;
//}
//int main()
//{
//	while (1)
//	{
//		try {
//			Func();
//		}
//		catch (const char* errmsg)
//		{
//			cout << errmsg << endl;
//		}
//		catch (...) // �������͵��쳣�����Բ���, �ŵ���󣬷�ֹ��һЩ�쳣û�в��񣬵��³�����ֹ
//		{
//			cout << "unkown exception" << endl;
//		}
//	}
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////
// �����׳������������ʹ�û��ಶ�� -- ��̬
//
class Exception
{
public:
	Exception(int errid, const string& msg)
		:_errid(errid)
		, _errmsg(msg)
	{}

	//const string& GetMsg() const
	//{
	//	return _errmsg;
	//}

	virtual string what() const
	{
		return _errmsg;
	}

	int GetErrid() const
	{
		return _errid;
	}

protected: 
	int _errid; // ������
	string _errmsg; // ��������
};

class SqlException : public Exception
{
public:
	SqlException(int errid, const string& msg, const string& sql)
		:Exception(errid, msg)
		,_sql(sql)
	{}

	virtual string what() const
	{
		string msg = "SqlException��";
		msg += _errmsg;
		msg += "->";
		msg += _sql;

		return msg;
	}

protected:
	string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(id, errmsg)
	{}

	virtual string what() const
	{
		string msg = "CacheException��";
		msg += _errmsg;

		return msg;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(id, errmsg)
		, _type(type)
	{}

	virtual string what() const
	{
		string msg = "HttpServerException��";
		msg += _errmsg;
		msg += "->";
		msg += _type;

		return msg;
	}

private:
	const string _type;
};

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException(100, "Ȩ�޲���", "select * from name = '����'");
	}

	cout << "���óɹ�" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	// ģ��������
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}

	CacheMgr();
}

//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//
//		try
//		{
//			HttpServer();
//		}
//		catch (const HttpServerException& e) // ˭����ѡ��˭
//		{
//			cout << "����:";
//			cout << e.what() << endl;
//		}
//		catch (const Exception& e) // ���ﲶ�������Ϳ��� -- ͨ����̬���������
//		{
//			// ��̬
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////
double Division(int a, int b) // throw()//������Щ���������׳��쳣
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}

	return (double)a / (double)b;
}

void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array = new int[10];

	int len, time;
	cin >> len >> time;

	try
	{
		cout << Division(len, time) << endl;
		HttpServer();
	}
	catch (...)   // �쳣�������׳������벻֧�ֽ�������
	{
		cout << "delete []" << array << endl;
		delete[] array;

		throw;   // ����ʲô��ʲô ��������������ͳһ�����쳣���������ﲶ���������׳�
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	while (1)
	{
		try
		{
			Func();
		}
		catch (const char* errmsg)
		{
			cout << errmsg << endl;
		}
		catch (const Exception& e) // ���ﲶ�������Ϳ���
		{
			// ��̬
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
		
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// �쳣�淶
// ��������쳣���������Ǳ���Ĳ��ұȽϷ���
// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
// void fun() throw(A��B��C��D);
// // �����ʾ�������ֻ���׳�bad_alloc���쳣
// void* operator new (std::size_t size) throw (std::bad_alloc);
// // �����ʾ������������׳��쳣
// void* operator delete (std::size_t size, void* ptr) throw();
// // C++11 ��������noexcept����ʾ�������쳣
// thread() noexcept;
// thread(thread&& x) noexcept;