#include <iostream>
#include <vector>
#include <thread>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//struct Goods
//{
//	string _name; // ����
//	double _price; // �۸�
//	int _evaluate; // ����
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	//sort(v.begin(), v.end(), ComparePriceGreater());
//
//	//lambda�ǿɵ��ö���
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr)->bool {
//			return gl._price > gr._price; 
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//}

//��׽�б� 
//int main() 
//{
//	auto add = [](int x, int y)->int {return x + y; };// ����lambda����
//
//	cout << [](int x, int y)->int {return x + y; }(1, 2) << endl;
//	cout << add(1, 2) << endl;
//
//	auto add2 = [](int x, int y)
//	{
//		return x + y; 
//	};
//
//	[] {};
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int x = 0; int y = 1;
//	auto swap1 = [](int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	};
//
//	swap1(x, y);
//	cout << "x:" << x << " y:" << y << endl;
//
//	auto func1 = [&x, y]() // ��ϲ�׽
//	{; };
//	auto func2 = [&]() // ȫ�����ò�׽
//	{; };
//	auto func3 = [=]() // ȫ����ֵ��׽
//	{; };
//	auto func4 = [&, x]() // ȫ����ֵ��׽, x��ֵ��׽
//	{; };
//	while (1)
//	{
//		int m = 0;
//		//auto swap2 = [x, y]()  //ʹ��ֵ��׽���Խ��в���
//		auto swap2 = [&x, &y, m, n]() // ��׽�б���Բ�׽����������ı��� // ���ò�׽
//		{
//			int tmp = x;
//			x = y;
//			y = tmp;
//		};
//	}
//	//swap2();
//	cout << "x:" << x << " y:" << y << endl;
//}


//int main()
//{
//	auto swap1 = [](int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	};
//
//	cout << sizeof(swap1) << endl;
//}

//class Rate
//{
//public:
//	Rate(double rate) : _rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//
//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//	// lamber
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year;
//	};
//	r2(10000, 2);// lambda+uuid ��� ÿ�����ɵ�������ƶ�����ͬ
//	return 0;
//}


//pthread
	// phread_create
	// C++98��linux��windows�¶�����֧�ֵĶ��̳߳���-- ��������
	
	//#ifdef _WIN32
	//	CreateThread
	//#else
	//	pthread_create
	//#endif

	// C++11,linux��windows�¶�����֧�ֵĶ��̳߳���-- thread��
//void Func(int n, int num)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << num << ":" << i << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	thread t1(Func, n1, 1); 
//	thread t2(Func, n2, 2);
//	
//	t1.join();
//	t2.join();
//	return 0;
//}

//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	thread t1([n1](int num)
//		{
//			for (int i = 0; i < n1; i++)
//
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 1);
//	
//	thread t2([n2](int num)
//		{
//			for (int i = 0; i < n2; i++)
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 2);
//
//	t1.join();
//	t2.join();
//	return 0;
//}
//

//int main()
//{
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m);
//	//Ҫ��m���̷ֱ߳��ӡn
//
//	for (size_t i = 0; i < m; i++)
//	{
//		size_t n;
//		cin >> n;
//
//		vthds[i] = thread([i, n]() // ��ֵ��������������ƶ���ֵ
//			{
//				for (int j = 0; j < n; ++j)
//				{
//					cout << i << ":" << j << endl;
//				}
//				cout << endl;
//			});
//		cout << vthds[i].get_id() << endl;
//	}
//
//	//for (auto t : vthds) // ��֧�ֿ������� ����
//	for (auto& t : vthds)
//	{
//		t.join();
//	}
//	return 0;
//}
//


//int main()
//{
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m);
//	//Ҫ��m���̷ֱ߳��ӡn
//
//	for (size_t i = 0; i < m; i++)
//	{
//		size_t n = 10;
//
//		vthds[i] = thread([n]() // ��ֵ��������������ƶ���ֵ
//			{
//				for (int j = 0; j < n; ++j)
//				{
//					cout << this_thread::get_id() << ":" << j << endl;
//					//this_thread::sleep_for(chrono::seconds(1));
//				}
//				cout << endl;
//
//			});
//		//cout << vthds[i].get_id() << endl;
//	}
//
//	//for (auto t : vthds) // ��֧�ֿ������� ����
//	for (auto& t : vthds)
//	{
//		t.join();
//	}
//	return 0;
//
//	// yield// ������� CAS
//	//int i = 0;
//	//i += 1;
//
//	// ԭ��
//	/*int old = i;
//	while (!__sync_bool_compare_and_swap(&i, old, old+1))
//	{
//		old = i;
//	}*/
//}
//

#include <mutex>
#include <list>
///////////////////////////////////////////////////////////////////////////////////////////
//list<int> lt;
//mutex mtx;
//int x = 0;

//void Func(int n) // ÿ���߳����Լ�������ջ
//{
//	//cout << &n << endl;
//	//cout << &x << endl;
//	//for (int i = 0; i < n; i++) // �д������л������ĵĲ���
//	//{
//	//	mtx.lock();
//	//	++x; // ����̫С
//	//	mtx.unlock();
//		//cout << i << endl;
//		//cout << i << endl;
//		//cout << i << endl;
//	//}
//
//	mtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		++x;
//	}
//	mtx.unlock();
//}

//int main()
//{
//	int n = 10000000;
//	size_t begin = clock();
//	thread t1(Func, n);
//	thread t2(Func, n);
//
//	t1.join();
//	t2.join();
//	size_t end = clock();
//
//	cout << x << endl;
//	cout << end - begin << endl;
//
//
//	return 0;
//}


//int main()
//{
//	mutex mtx;
//	int n = 10000000;
//	size_t begin = clock();
//	thread t1([&, n]()
//		{
//			mtx.lock();
//			for (int i = 0; i < n; ++i)
//			{
//				++x;
//			}
//			mtx.unlock();
//
//		});
//	thread t2([&, n]()
//		{
//			mtx.lock();
//			for (int i = 0; i < n; ++i)
//			{
//				++x;
//			}
//			mtx.unlock();
//
//		});
//
//	t1.join();
//	t2.join();
//	size_t end = clock();
//
//	cout << x << endl;
//	cout << end - begin << endl;
//
//
//	return 0;
//}

//recursive_mutex mtx;
////mutex mtx;
//void Func(int n) // ջ�Ŀռ�ᱬ
//{
//	if (n == 0)
//		return;
//	mtx.lock();
//	++x;
//
//	Func(n - 1);
//	mtx.unlock(); // �����Ļ���������
//}
//
//int main()
//{
//	int n = 10000;
//	thread t1(Func, n);
//	thread t2(Func, n);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//
//	return 0;
//}

//template<class Lock>
//class LockGard
//{
//public:
//	LockGard(Lock& lk) // ��û���ƶ�����
//		:_lk(lk)
//	{
//		_lk.lock();
//	}
//	~LockGard()
//	{
//		_lk.unlock();
//	}
//private:
//	Lock& _lk;
//};
//int x = 0;
//mutex mtx;
//void Func(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		try
//		{
//			//mtx.lock();
//			//LockGard<mutex> lock(mtx);
//			//lock_guard<mutex> lock(mtx);
//			unique_lock<mutex> lock(mtx);
//			
//			++x;
//			
//			lock.unlock();
//			//...
//			lock.lock();
//
//			// ���쳣... 
//			if (rand() % 5 == 0)
//			{
//				throw exception("���쳣"); 
//			}
//			//mtx.unlock(); 
//		}
//		catch (const std::exception& e)
//		{
//			cout << e.what() << endl; // ���쳣ʱ��������������ٴν���ʱ�ͻᵼ����������
//		}
//	}
//}
//
//int main()
//{
//	int n = 10;
//	thread t1(Func, n);
//	thread t2(Func, n);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//
//	return 0;
//}


//ԭ�Ӳ���
//int main()
//{
//	//�ײ�CAS
//	int n = 100000;
//	atomic<int> x = 0;
//	//atomic<int> x = {0};
//	//atomic<int> x{0};
//	//int x = 0;
//
//	mutex mtx;
//	size_t begin = clock();
//
//	thread t1([&, n](){
//			for (int i = 0; i < n; i++)
//			{
//				++x;
//			}
//		});
//
//	thread t2([&, n]() {
//			for (int i = 0; i < n; i++)
//			{
//				++x;
//			}
//		});
//
//	t1.join();
//	t2.join();
//	size_t end = clock();
//
//	cout << x << endl;
//	cout << end - begin << endl;
//	
//	//Func(x);
//	//printf("%d\n", x.load()); // ֱ��ʹ�ûᱨ��
//
//	return 0;
//}

// ֧�������߳̽����ӡ��t1��ӡ������t2һ����ӡż��
//#include <condition_variable>
//int main()
//{
//	mutex mtx;
//	int n = 100;
//	int x = 1;
//	condition_variable cv;
//	// ����1����α�֤t1�����У�t2������
//	// ����2����η�ֹһ���̲߳������У�
//	thread t1([&, n]() {
//		//while(x < n)
//		while(1)
//		{ 
//			unique_lock<mutex> lock(mtx);
//			if (x >= 100) break; // �ų�t2�ӵ�100֮��t1�Ѿ�����ѭ���жϻᵼ��101�ķ���
//			//if (x % 2 == 0) // ż����������������������ֹһ���̲߳��ϵ�����
//			//{
//			//	cv.wait(lock);
//			//}
//			cv.wait(lock, [&x]() {return x % 2 != 0; });
//			//mtx.lock();
//			cout << this_thread::get_id() << ":" << x << endl;
//			++x;
//			//mtx.unlock();
//			cv.notify_one();
//		}
//		});
//
//	thread t2([&, n]() {
//		//while (x < n)
//		while (1)
//		{
//			unique_lock<mutex> lock(mtx);
//			if (x > 100) break;
//			//if (x % 2 == 1) // ��������
//			//{
//			//	cv.wait(lock); // ��֤t1�����У�t2������
//			//}
//			cv.wait(lock, [&x]() {return x % 2 == 0; });
//			//mtx.lock();
//			cout << this_thread::get_id() << ":" << x << endl;
//			++x;
//			//mtx.unlock();
//			cv.notify_one();
//		}
//		});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}
// t1����������t2����������t1�����У�t2����������
// t2����������t1����������t2�����У�t1���������ϣ�����t2��һ���ᱻwait����������waitʱ���������֤��t1�����С�

//thread t1([&, n]() {
//	while (1)
//	{
//		unique_lock<mutex> lock(mtx);
//
//		cout << this_thread::get_id() << ":" << x << endl;
//
//	}
//	});
//
//thread t2([&, n]() {
//	//while (x < n)
//	while (1)
//	{
//		unique_lock<mutex> lock(mtx);
//		cv.wait(lock);
//		cout << this_thread::get_id() << ":" << x << endl;
//	}



///////////////////////////////////////////////////////////////////////////////////////////
#include <functional>
//#include <map>
//// ��װ��function - ��ģ��
//// �Կɵ��ö������ͽ����ٷ�װ����
//// ����ָ��
//// �º���
//// lambda(�º���)
//
//int f(int a, int b)
//{
//	cout << "int f(int a, int b)" << endl;
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		cout << "int operator() (int a, int b)" << endl;
//
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//
//	Plus(int rate = 2)
//		:_rate(rate)
//	{}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b * _rate;
//	}
//private:
//	int _rate = 2;
//};
//
//int main()
//{
//	//int(*pf1)(int, int) = f;
//
//	//map<string, > //û�а취��������ָ���������
//
//
//	// ��װ��ͳһ������
//	//function<int(int, int)> f1 = f;
//	//function<int(int, int)> f2 = Functor();
//	//function<int(int, int)> f3 = [](int x, int y) {
//	//	return x + y;
//	//};
//
//	//cout << f1(1, 2) << endl;
//	//cout << f2(10, 20) << endl;
//	//cout << f3(1, 3) << endl;
//
//	//map<string, function<int(int, int)>> opFuncMap;
//	//opFuncMap["����ָ��"] = f;
//	//opFuncMap["�º���"] = Functor();
//	//opFuncMap["lambda"] = [](int a, int b) {
//	//	cout << "[](int a, int b) {return a + b;}" << endl;
//	//	return a + b;
//	//};
//
//	//cout << opFuncMap["lambda"](1, 2) << endl;
//
//	 
//	//function<int(int, int)> f1 = Plus::plusi;//��ͨ�����뾲̬��Ա��������������ָ�룬 �Ǿ�̬��Ҫ���&
//	function<int(int, int)> f1 = &Plus::plusi; 
//	function<double(Plus, double, double)> f2 = &Plus::plusd; // ������ӵ���Plus�� ʹ�ö�ȥ����
//	function<double(Plus*, double, double)> f3 = &Plus::plusd; // ������ӵ���Plus*
//	
//	cout << f1(1, 2) << endl;
//	cout << f2(Plus(), 20, 20) << endl;
//	cout << f2(Plus(3), 30, 20) << endl;
//
//	Plus pl1(3);
//	cout << f2(pl1, 20, 20) << endl;
//
//	Plus pl2(3);
//	cout << f3(&pl2, 20, 20) << endl; // ָ�벻��ʹ������������Ϊ����ȡ��ַ
//
//	return 0;
//}
// ʹ�����ܹ����õı��
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> s;
//		map<string, function<int(int, int)>> oFuncMap =
//		{
//			{"+", [](int x, int y) {return x + y; }},
//			{"-", [](int x, int y) {return x - y; }},
//			{"*", [](int x, int y) {return x * y; }},
//			{"/", [](int x, int y) {return x / y; }}
//		};
//		for (auto str : tokens)
//		{
//			if (oFuncMap.count(str))
//			{
//				int right = s.top();
//				s.pop();
//				int left = s.top();
//				s.pop();
//				s.push(oFuncMap[str](left, right));
//			}
//			else
//			{
//				s.push(stoi(str));
//			}
//		}
//		return s.top();
//	}
//};


//int sub(int a, int b)
//{
//	return a - b;
//}
//
//class Sub {
//public:
//	Sub(int rate = 3)
//		:_rate(rate)
//	{}
//
//	int operator()(int a, int b)
//	{
//		return (a - b) * _rate;
//	}
//private:
//	int _rate;
//};
//
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		map<string, function<int(int, int)>> opFuncMap =
//		{
//			{ "+", [](int i, int j) {return i + j; } },
//			{ "-", sub },
//			{ "*", [](int i, int j) {return i * j; } },
//			{ "/", [](int i, int j) {return i / j; } },
//			{ "#", Sub() }
//		};
//		for (auto& str : tokens)
//		{
//			if (opFuncMap.find(str) != opFuncMap.end())
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//				st.push(opFuncMap[str](left, right));
//			}
//			else
//			{
//				// 1��atoi itoa
//				// 2��sprintf scanf
//				// 3��stoi to_string C++11
//				st.push(stoi(str));
//			} 
//		}
//		return st.top();
//	}
//};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// bind ����ģ�壬���ڵ���������˳�������

// ����������˳��
//void Print(int a, int b)
//{
//	cout << a << " " << b << endl;
//	cout << "void Print(int a, int b)" << endl;
//}
//
//
//int main()
//{
//	Print(1, 2);
//	function<void(int, int)> RPrint = bind(Print, placeholders::_2, placeholders::_1);
//	//auto RPrint = bind(Print, placeholders::_2, placeholders::_1);
//	RPrint(10, 20);
//}

// ������������
using namespace placeholders;
class Sub {
public:
	Sub(int rate)
		:_rate(rate)
	{}
	int func(int a, int b) // ���ں������������� thisָ��
	{
		return (a - b) * _rate;
	} 
private:
	int _rate;
};

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		map<string, function<int(int, int)>> opFuncMap =
		{
			{ "+", [](int i, int j) {return i + j; } },
			//{ "-", Sub::func },
			{ "-", bind(&Sub::func, Sub(3), placeholders::_1, placeholders::_2) },
			{ "*", [](int i, int j) {return i * j; } },
			{ "/", [](int i, int j) {return i / j; } }
		};
		for (auto& str : tokens)
		{
			if (opFuncMap.find(str) != opFuncMap.end())
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(opFuncMap[str](left, right));
			}
			else
			{
				// 1��atoi itoa
				// 2��sprintf scanf
				// 3��stoi to_string C++11
				st.push(stoi(str));
			}
		}
		return st.top();
	}
};

int main()
{

	function<int(Sub, int, int)> fSub = &Sub::func;

	// �󶨿��Խ�ĳ����������
	function<int(int, int)> func = bind(&Sub::func, Sub(3), _1, _2);
	function<int(Sub, int)> func1 = bind(&Sub::func, _1, 10, _2);

	return 0;
}