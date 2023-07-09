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
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？
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
// 事前预防 -- 智能指针
// 使用RAII思想设计的SmartPtr类
// 1. RAII
// 2. 像指针一样使用
// 3. 拷贝问题
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
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	SmartPtr<int> sp3(sp1); // 这里要让两个智能指针指向同一块区域与内置类型中的指针一样，指针需要的就是浅拷贝
//	// 链表、红黑树等迭代器跟智能指针结构类似，用的是浅拷贝没有问题，因为迭代器不管资源的释放，资源释放是容器处理的，而智能指针需要管资源释放，不能单纯的浅拷贝。
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

	*ap1 = 1; // 管理权转移以后导致ap1悬空，不能访问
	*ap2 = 1;
}

void test_unique() // 简单粗暴防拷贝，不需要拷贝的场景使用
{
	std::unique_ptr<int> up1(new int(1));
	//std::unique_ptr<int> up2(up1);
}

void test_shared() // 引用计数，支持拷贝
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