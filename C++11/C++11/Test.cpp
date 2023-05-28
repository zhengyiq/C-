#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

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

class Date
{
public:
	//explicit Date(int year, int month, int day)
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
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
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
int main()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret��������double
	decltype(&x) p; // p��������int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');

	// vector�洢�����͸�x*y���ʽ����ֵ����һ��
	// decltype�Ƶ����ʽ���ͣ����������ʵ����ģ��������߶������
	vector<decltype(x* y)> v;
	return 0;
}

// 1. ����֧��initialzer_list�Ĺ���ӿڡ�ʹ�ø����㣬��һ���ļ�ֵ
// 2. ����cbegin��cendϵ�е������Ľӿ�
// 3. �ƶ�������ƶ���ֵ