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

// ͳһ�б��ʼ��
// {}��ʼ��
//int main()
//{
//	int x = 1;
//	int x2 = { 1 };
//	int x3{ 3 }; // ����ʡ�Ը�ֵ����
//	int array1[]{ 1, 2, 3, 4, 5 };
//
//	// C++11���б��ʼ��Ҳ����������new���ʽ��
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
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 }; // explicit
//	return 0;
//}

// std::initializer_list
//int main()
//{
	//vector<int> v1{ 1,2,3,4,5 };  // ��������һ�µ�
	//vector<int> v2 = { 10,20,30 }; // �����ڵ���ʹ��initializer_list<>�Ĺ��캯��
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
	//cout << *it1 << endl; // �����޸ģ�˵�����ݴ洢�ڳ�����

	//Date d1{ 2023, 5, 28 };
	//Date d2{ 2023, 5, 29 };

	//vector<Date> v1 = { d1, d2 };
	//vector<Date> v2 = { Date { 2023, 5, 28 }, Date { 2023, 5, 29 } };

	//Date d3( 2023, 5, 28 );
	//Date d4( 2023, 5, 29 );
	//// initializer_list<Date>
	//vector<Date> v3 = { d3, d4 };
	//vector<Date> v4 = { Date ( 2023, 5, 28 ), Date ( 2023, 5, 29 ) };

	//// ��C++11�������Լ���д��vector�����������⣺û��ʵ��������ģ��ȡ��Ƕ������Ҫ����typename����

	//vector<Date> vd3 = { {2023,5,20}, {2023,5,20} }; // ����Date�Ĺ��� + ����initializer_list����
	//
	//map<string, string> dict = { {"sort", "����"},{"string", "�ַ���"},{"Date", "����"} };
	//pair<string, string> kv1 = { "Date", "����" };
	//pair<string, string> kv2 { "Date", "����" };
//}


// decltype
// decltype��һЩʹ��ʹ�ó���
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
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p; // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//
//	// vector�洢�����͸�x*y���ʽ����ֵ����һ��
//	// decltype�Ƶ����ʽ���ͣ����������ʵ����ģ��������߶������
//	vector<decltype(x* y)> v;
//	return 0;
//}

// 1. ����֧��initialzer_list�Ĺ���ӿڡ�ʹ�ø����㣬��һ���ļ�ֵ
// 2. ����cbegin��cendϵ�е������Ľӿ�
// 3. �ƶ�������ƶ���ֵ

//��ֵ����
//int main()
//{
//	// ���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// ���¼����Ƕ�������ֵ����ֵ����
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}
//
//��ֵ����
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// �������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ
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
//	// ��ֵ���ø���ֵȡ����
//	int& ref1 = a;
//	
//	// ��ֵ���ø���ֵȡ����
//	//int& ref2 = (a + b); err
//	const int& ref = (a + b);
//
//	// ��ֵ���ø���ֵȡ����
//	int&& ref3 = (a + b);
//
//	// ��ֵ���ø���ֵȡ����
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
//	func(a + b); // ���ֻ����ֵ���ã�����ʱ�������г��ԣ���ô����Ȩ�޵ķŴ����޷����д��ݵģ����Ҫ���д��ݾ���Ҫ��func���β������const�������������޷��Դ���Ĳ�������ֵ������ֵ�������֡�������ֵ���þͿ��Խ���ֵ����ֵ�������֡�
//}


//int  main()
//{
//	//��ֵ������ֵ������ֵ
//	//��ֵ�����Ѿ������ٿ����ĳ������д�����ֵ����������ֵ����ֵ��Ȼ����ֵ(����ֵ)����Դ���н���
//	//��ֵ���ã�ֱ�Ӽ��ٿ�����1.��ֵ���ô��� 2.�����÷���(������ľֲ�������ʹ�����÷���)
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


//��һ����Ҫע��ľ�����ֵ�ǲ���ȡ��ַ�ģ����Ǹ���ֵȡ�����󣬻ᵼ����ֵ���洢���ض�λ�ã��ҿ���ȡ����λ�õĵ�ַ��Ҳ����˵���磺����ȡ������10�ĵ�ַ������rr1���ú󣬿��Զ�rr1ȡ��ַ��Ҳ�����޸�rr1���������rr1���޸ģ�������const int&& rr1 ȥ���á�
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5; // ����
//	return 0;
//}

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��

//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//
//// ��������(�����۵�)���ȿ���������ֵ��Ҳ����������ֵ
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a); // ��ֵ
//	PerfectForward(move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b); // const ��ֵ
//	PerfectForward(move(b)); // const ��ֵ
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

// ��ֵ����û�н��������
// 1.�ֲ�����ķ�������
// 2.����ӿڣ����󿽱�������
// T���Զ�������:
// 1.ǳ�������࣬������ǿ������죬��Ϊ����ǳ�������࣬�ƶ�������û��ʲô����ġ�
// 2.������࣬��������ƶ����죬����������࣬�ƶ��������ת����ֵ����Դ��û�п��������Ч�ʡ�

//int main()
//{
//	zyq::string s1;
//
//	s1 = zyq::to_string(1234);
//	// string(string && s) --�ƶ����� -> 
//	// string& operator=(string s) --���
//	// string(const string & s) --��� -> ����ʹ�õ����ִ�д�������˿��������ʵ��
//
//	// ������ƶ�����֮��Ľ��
//	// string(string && s) --�ƶ�����
//	// string& operator=(string && s) --�ƶ�����
//
//	//zyq::string("hello"); // ���õ���->string(char* str)����
//
//	//void push_back(const string & s) // ����˴�����ʱ����ʱ���������ڵ����⡣
//	//{}
//
//	//v.push_back(string("111111"));
//	//v.push_back("111111");
//	// ���ǲ��ܹ����޵��ӳ�����������Ϊ��������������ͻ��������������������
//
//	//const string& ref = to_string(1234);
//	//ʹ��const&�����н��վͿ��Եõ����������ӳ�����ʱ��������ֵ���ص���ʱ������������һ��ջ֡��
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////


//����³�Ա
//֮ǰһ��������Ĭ�ϳ�Ա����
//1.���캯��
//2.��������
//3.�������캯��
//4.������ֵ����
//5.ȡ��ַ����
//6.constȡ��ַ����
//7.�ƶ������ƶ���ֵ������������
//�����û���Լ�ʵ���ƶ����캯������û��ʵ���������� ���������졢������ֵ�����е�����һ����(���������ˣ�������࣬��Դת�����������Լ�ʵ��)��ô���������Զ�����һ��Ĭ���ƶ����졣Ĭ�����ɵ��ƶ����캯���������������ͳ�Ա��ִ�����Ա���ֽڿ������Զ������ͳ�Ա������Ҫ�������Ա�Ƿ�ʵ���ƶ����죬���ʵ���˾͵����ƶ����죬û��ʵ�־͵��ÿ������졣


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
//	// ί�й��죬һ�����캯�����Ը����������캯��
//	Person(const Person& p)
//		:Person(name, 18)
//	{}
//
//private:
//	zyq::string _name;
//	int _age;
//};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//�ɱ����ģ��
// Args��һ��ģ���������args��һ�������ββ�����
// ����һ��������Args...args������������п��԰���0�������ģ�������
//template <class ...Args>
//void ShowList(Args... args)
//{	
//	cout << sizeof...(args) << endl;
//	// ��ν�������������
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
//// �ݹ�˼ά�Ƶ�
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
// �ݹ�˼ά�Ƶ�
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
////չ������
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
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
//// �����������������ɵĴ���
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
//STL�����Ĳ���ӿڶ���һ��emplaceϵ��
#include "Date.h"
int main()
{
	// �������
	std::list<zyq::string> mylist;
	// û����
	/*zyq::string s1("1111");
	mylist.push_back(s1);
	mylist.emplace_back(s1);

	cout << endl;
	zyq::string s2("2222");
	mylist.push_back(move(s1));
	mylist.emplace_back(move(s2));*/

	// ��ʼ������
	//cout << endl;
	//mylist.push_back("3333");   // ������������ + �ƶ�����
	//mylist.emplace_back("3333");// ֱ�ӹ���

	// ǳ��������
	// û����
	std::list<Date> list2;
	//Date d1(2023, 5, 28);
	//list2.push_back(d1);
	//list2.emplace_back(d1);

	//cout << endl;
	//Date d2(2023, 5, 28);
	//list2.push_back(move(d1));
	//list2.emplace_back(move(d2));

	// ������
	//cout << "=========================" << endl;
	//list2.push_back(Date(2023, 5, 28));
	//list2.push_back({ 2023, 5, 28 });

	cout << endl;
	list2.emplace_back(Date(2023, 5, 28)); // ����+�ƶ�����
	list2.emplace_back(2023, 5, 28);       // ֱ�ӹ���


	return 0;
}