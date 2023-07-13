#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <time.h>
using namespace std;

// 请设计一个类，不能被拷贝

// 请设计一个类，只能在堆上创建对象
// 思路一：
//class HeapOnly
//{
//public:
//	HeapOnly(int x = 3)
//		:_x(x)
//	{}
//	void Destory()
//	{
//		delete this;
//	}
//
//private:
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//};
//
//int main()
//{
//	// HeapOnly ho1; // err
//	// static HeapOnly ho2; // err
//	HeapOnly* pho3 = new HeapOnly;
//	//delete pho3;
//	pho3->Destory(); 
//}

// 思路二：
class HeapOnly
{
public:
	
	static HeapOnly* CreateObj(int x)
	{
		HeapOnly* pho = new HeapOnly(1);
		return pho;
	}
	~HeapOnly()
	{
		cout << "~HeapOnly()" << endl;
	}
private:
	HeapOnly(int x = 0)
		:_x(x)
	{}

	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;

	int _x;
};

int main()
{
	// HeapOnly ho1; // err
	// static HeapOnly ho2; // err
	// HeapOnly* pho3 = new HeapOnly; // err
	HeapOnly* p1 = HeapOnly::CreateObj(1);
	// HeapOnly p2(*p1); // 还需要将拷贝构造封掉
	delete p1;
}

// 请设计一个类，只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly CreateObj(int x = 0)
	{
		return StackOnly(x);
	}

	StackOnly(StackOnly&& st) // 显示的写了拷贝构造，就不会再生成移动构造
		:_x(st._x)
	{}

private:
	StackOnly(int x = 0)
		:_x(x)
	{}

	StackOnly(const StackOnly& st) = delete;

	int _x;
};

//int main()
//{
//	// 将构造函数封掉，则正常的创建对象的方式都没有了
//	/*StackOnly st1;
//	static StackOnly st2;
//	StackOnly* st3 = new StackOnly;*/
//
//	StackOnly st1 = StackOnly::CreateObj(1);
//	//StackOnly st2 = st1;
//	//static StackOnly st2 = st1; // 将拷贝构造封掉之后，静态对象就不能在创建了，但是调用CreateObj的方式也失效了，考虑到StackOnly::CreateObj(1);是临时变量，可以使用移动构造来进行构建对象
//	//static StackOnly st2 = move(st1);
//
//	return 0;
//}

// 请设计一个类，不能被继承

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 请设计一个类，只能创建一个对象(单例模式)

// 适配器
// 迭代器
// 单例
// 扩展 工厂 观察者

//// 饿汉模式：一开始(main函数之前)就创建对象
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _ins;
//	}
//
//	void Add(const string& str)
//	{
//		_mtx.lock();
//
//		_v.push_back(str);
//
//		_mtx.unlock();
//	}
//
//	void Print()
//	{
//		_mtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_mtx.unlock();
//	}
//
//private:
//	// 限制类外面随意创建对象
//	Singleton()
//	{}
//private:
//	mutex _mtx;
//	int _n = 0;
//	vector<string> _v;
//
//	static Singleton* _ins;
//};
//
//Singleton* Singleton::_ins = new Singleton;


// 懒汉模式：第一次访问实例对象时创建

// 分析：懒汉和饿汉的优缺点
// 饿汉的缺点：
// 1、如果单例对象很大，main函数之前就要申请，第一，暂时不需要使用确占用资源，第二程序启动会受影响。
// 2、如果两个单例都是饿汉，并且有依赖关系，要求单例1再创建，单例2再创建，饿汉无法控制顺序，懒汉才可以。
// 饿汉的优点：
// 简单（相对懒汉而言）

// 懒汉完美的解决了上面饿汉的问题，但是就是相对复杂一点点

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// 双检查加锁
//		if (_ins == nullptr)
//		{
//			_imtx.lock(); // 只需要保护第一次
//
//			if (_ins == nullptr)
//			{ 
//				_ins = new Singleton;
//			}
//
//			_imtx.unlock();
//		}
//
//		return _ins;
//	}
//
//	// 一般全局都要使用单例对象，所以单例对象一般不需要显示释放
//	// 有些特殊场景，想显示释放一下，也可以手动释放。
//	static void DelInstance()
//	{
//		_imtx.lock();
//		if (_ins)
//		{
//			delete _ins;
//			_ins = nullptr;
//		}
//		_imtx.unlock();
//	}
//
//	// 单例对象回收
//	class GC
//	{
//	public:
//		~GC()
//		{
//			DelInstance();
//		}
//	};
//
//	static GC _gc;
//
//	void Add(const string& str)
//	{
//		_vmtx.lock();
//
//		_v.push_back(str);
//
//		_vmtx.unlock();
//	}
//
//	void Print()
//	{
//		_vmtx.lock();
//
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//
//		_vmtx.unlock();
//	}
//
//private:
//	// 限制类外面随意创建对象
//	Singleton() {}
//
//	// 防拷贝
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _vmtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//	static mutex _imtx; // 这里有锁，而锁是不能够进行拷贝的，因此这个单例就是无法拷贝的
//};
//
//Singleton* Singleton::_ins = nullptr; // 内置类型不会自己调用析构
//mutex Singleton::_imtx;
//Singleton::GC Singleton::_gc;

//int main()
//{
//	//Singleton s1;
//	//static Singleton s2;
//	Singleton::GetInstance();
//	return 0;
//}

//int main()
//{
//	srand(time(0));
//
//	size_t n = 30;
//	thread t1([n]() {
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t1线程:" + to_string(rand()));
//		}
//		});
//
//	thread t2([n]() {
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t2线程:" + to_string(rand()));
//		}
//		});
//
//	t1.join();
//	t2.join();
//
//	Singleton::GetInstance()->Print();
//
//	return 0;
//}

// 保证一些数据(一个进程中)全局只有唯一一份， 并且方便访问
// 1. 把这些数据放进一个类中，把这个类设计成单例类
// 2. 构造和拷贝构造都封死，提供静态公有获取单例对象的函数
// 3. 创建单例对象的方式：饿汉 懒汉


// 这种方法是可以的，但是
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// C++11之前不能保证出初始化静态成员的线程安全问题
		// C++11之后能保证出初始化静态成员的线程安全问题
		static Singleton inst; // 这个静态变量在第一次调用的时候初始化
		return &inst;
	}

	void Add(const string& str)
	{
		_vmtx.lock();

		_v.push_back(str);

		_vmtx.unlock();
	}

	void Print()
	{
		_vmtx.lock();

		for (auto& e : _v)
		{
			cout << e << endl;
		}
		cout << endl;

		_vmtx.unlock();
	}

private:
	// 限制类外面随意创建对象
	Singleton() 
	{
		cout << "Singleton()" << endl;
	}

	// 防拷贝
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;

private:
	mutex _vmtx;
	vector<string> _v;
};
