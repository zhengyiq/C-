#include <iostream>
#include <vector>
#include <thread>
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
//	{}
//	auto func2 = [&]() // ȫ�����ò�׽
//	{}
//	auto func3 = [=]() // ȫ����ֵ��׽
//	{}
//	auto func4 = [&, x]() // ȫ����ֵ��׽, x��ֵ��׽
//	{}
//
//	//auto swap2 = [x, y]() mutable //ʹ��ֵ��׽���Խ��в���
//	auto swap2 = [&x, &y]() // ��׽�б���Բ�׽����������ı��� // ���ò�׽
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap2();
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


int main()
{
	size_t m;
	cin >> m;
	vector<thread> vthds(m);
	//Ҫ��m���̷ֱ߳��ӡn

	for (size_t i = 0; i < m; i++)
	{
		size_t n = 10;

		vthds[i] = thread([n]() // ��ֵ��������������ƶ���ֵ
			{
				for (int j = 0; j < n; ++j)
				{
					cout << this_thread::get_id() << ":" << j << endl;
					//this_thread::sleep_for(chrono::seconds(1));
				}
				cout << endl;

			});
		//cout << vthds[i].get_id() << endl;
	}

	//for (auto t : vthds) // ��֧�ֿ������� ����
	for (auto& t : vthds)
	{
		t.join();
	}
	return 0;

	// yield// ������� CAS
	//int i = 0;
	//i += 1;

	// ԭ��
	/*int old = i;
	while (!__sync_bool_compare_and_swap(&i, old, old+1))
	{
		old = i;
	}*/
}

