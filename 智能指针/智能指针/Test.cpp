#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
#include <functional>
#include <thread>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//	return a / b;
//}
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ�
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�
//	int* p1 = new int;
//	int* p2 = nullptr;
//	try
//	{
//		p2 = new int;
//	}
//	catch (...)
//	{
//		delete p1;
//		throw;
//	}
//	try
//	{
//		cout << div() << endl;
//	}
//	catch (...)
//	{
//		delete p1;
//		delete p2;
//	}
//	delete p1;
//	delete p2;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////
// ��ǰԤ�� -- ����ָ��
// ʹ��RAII˼����Ƶ�SmartPtr��
// 1. RAII
// 2. ��ָ��һ��ʹ��
// 3. ��������
//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//	return a / b;
//}
//void Func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	SmartPtr<int> sp3(sp1); // ����Ҫ����������ָ��ָ��ͬһ�����������������е�ָ��һ����ָ����Ҫ�ľ���ǳ����
//	// ����������ȵ�����������ָ��ṹ���ƣ��õ���ǳ����û�����⣬��Ϊ������������Դ���ͷţ���Դ�ͷ�����������ģ�������ָ����Ҫ����Դ�ͷţ����ܵ�����ǳ������
//	cout << div() << endl;
//}
//int main()
//{
//	try 
//	{
//		Func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////
#include "SmartPtr.h"

void test_auto()
{
	std::auto_ptr<int> ap1(new int(1));
	std::auto_ptr<int> ap2(ap1);

	*ap1 = 1; // ����Ȩת���Ժ���ap1���գ����ܷ���
	*ap2 = 1;
}

void test_unique() // �򵥴ֱ�������������Ҫ�����ĳ���ʹ��
{
	std::unique_ptr<int> up1(new int(1));
	//std::unique_ptr<int> up2(up1);
}

void test_shared() // ���ü�����֧�ֿ���
{
	std::shared_ptr<int> sp1(new int(10));
	std::shared_ptr<int> sp2(sp1);

}

int main()
{
	//zyq::test_auto();

	//test_unique();
	//test_shared();
	//zyq::test_shared();
	//zyq::test_shared_safe();
	zyq::test_shared_cycle();
	//zyq::test_shared_deletor();

}