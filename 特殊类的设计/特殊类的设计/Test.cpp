#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <time.h>
using namespace std;

// �����һ���࣬���ܱ�����

// �����һ���ֻ࣬���ڶ��ϴ�������
// ˼·һ��
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

// ˼·����
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
	// HeapOnly p2(*p1); // ����Ҫ������������
	delete p1;
}

// �����һ���ֻ࣬����ջ�ϴ�������
class StackOnly
{
public:
	static StackOnly CreateObj(int x = 0)
	{
		return StackOnly(x);
	}

	StackOnly(StackOnly&& st) // ��ʾ��д�˿������죬�Ͳ����������ƶ�����
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
//	// �����캯��������������Ĵ�������ķ�ʽ��û����
//	/*StackOnly st1;
//	static StackOnly st2;
//	StackOnly* st3 = new StackOnly;*/
//
//	StackOnly st1 = StackOnly::CreateObj(1);
//	//StackOnly st2 = st1;
//	//static StackOnly st2 = st1; // ������������֮�󣬾�̬����Ͳ����ڴ����ˣ����ǵ���CreateObj�ķ�ʽҲʧЧ�ˣ����ǵ�StackOnly::CreateObj(1);����ʱ����������ʹ���ƶ����������й�������
//	//static StackOnly st2 = move(st1);
//
//	return 0;
//}

// �����һ���࣬���ܱ��̳�

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �����һ���ֻ࣬�ܴ���һ������(����ģʽ)

// ������
// ������
// ����
// ��չ ���� �۲���

//// ����ģʽ��һ��ʼ(main����֮ǰ)�ʹ�������
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
//	// �������������ⴴ������
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


// ����ģʽ����һ�η���ʵ������ʱ����

// �����������Ͷ�������ȱ��
// ������ȱ�㣺
// 1�������������ܴ�main����֮ǰ��Ҫ���룬��һ����ʱ����Ҫʹ��ȷռ����Դ���ڶ�������������Ӱ�졣
// 2����������������Ƕ�����������������ϵ��Ҫ����1�ٴ���������2�ٴ����������޷�����˳�������ſ��ԡ�
// �������ŵ㣺
// �򵥣�����������ԣ�

// ���������Ľ����������������⣬���Ǿ�����Ը���һ���

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// ˫������
//		if (_ins == nullptr)
//		{
//			_imtx.lock(); // ֻ��Ҫ������һ��
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
//	// һ��ȫ�ֶ�Ҫʹ�õ����������Ե�������һ�㲻��Ҫ��ʾ�ͷ�
//	// ��Щ���ⳡ��������ʾ�ͷ�һ�£�Ҳ�����ֶ��ͷš�
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
//	// �����������
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
//	// �������������ⴴ������
//	Singleton() {}
//
//	// ������
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//private:
//	mutex _vmtx;
//	vector<string> _v;
//
//	static Singleton* _ins;
//	static mutex _imtx; // ���������������ǲ��ܹ����п����ģ����������������޷�������
//};
//
//Singleton* Singleton::_ins = nullptr; // �������Ͳ����Լ���������
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
//			Singleton::GetInstance()->Add("t1�߳�:" + to_string(rand()));
//		}
//		});
//
//	thread t2([n]() {
//		for (size_t i = 0; i < n; ++i)
//		{
//			Singleton::GetInstance()->Add("t2�߳�:" + to_string(rand()));
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

// ��֤һЩ����(һ��������)ȫ��ֻ��Ψһһ�ݣ� ���ҷ������
// 1. ����Щ���ݷŽ�һ�����У����������Ƴɵ�����
// 2. ����Ϳ������춼�������ṩ��̬���л�ȡ��������ĺ���
// 3. ������������ķ�ʽ������ ����


// ���ַ����ǿ��Եģ�����
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// C++11֮ǰ���ܱ�֤����ʼ����̬��Ա���̰߳�ȫ����
		// C++11֮���ܱ�֤����ʼ����̬��Ա���̰߳�ȫ����
		static Singleton inst; // �����̬�����ڵ�һ�ε��õ�ʱ���ʼ��
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
	// �������������ⴴ������
	Singleton() 
	{
		cout << "Singleton()" << endl;
	}

	// ������
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;

private:
	mutex _vmtx;
	vector<string> _v;
};
