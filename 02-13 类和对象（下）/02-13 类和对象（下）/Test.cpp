#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class B
//{
//public:
//	B(int b  = 2)
//		:_b(b)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _b;
//};
//
//class A
//{
//public:
//
//	// 1���ĸ�������ù��캯����ʼ���б������г�Ա���������λ��
//	// 2�������Ƿ���ʾ�ڳ�ʼ���б�д����ô������ÿ�����������ڳ�ʼ���б����ʼ��
//	A()
//		:_x(1)
//		//, _a1(1)
//		, _a2(1)
//		//, _a2(2) // ÿ����Ա����ֻ�����ڳ�ʼ���б��г���һ�� 
//		, ref(_a1)
//		, _bb(0)
//	{
//		_a1++; // 2
//		_a2--; // 0 û����ʾ��ֵ������ȱʡֵ����ʾ����ֵ�����ó�ʼ���б��е�ֵ��
//	}
//
//	int _a1 = 1; // ����
//	int _a2 = 2;
//
//	const int _x; // �����֮���޷�����Ĭ�ϵĹ��캯������Ϊconst���������ڶ����ʱ���ʼ��
//	// ����ʹ��const int _x = 1;ʹ��ȱʡ�����ķ�ʽ��C++11)����C++11֮ǰ�����������������Ҫʹ�ó�ʼ���б�
//	int& ref;
//	B _bb; // ֻ�ܵ���Ĭ�Ϲ��캯��
//};
//
//int main()
//{
//	A aa; // ��������Ķ��壬ÿ����Աʲôʱ���壿
//	// �����ÿ����Ա������һ�������λ�ã���Ȼ��const�����ĳ�Ա�޷���ʼ��
//
//	// const���������ڶ����ʱ���ʼ��
//	const int i = 0;
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a) // ���ʼ��
//		, _a2(_a1) // �ȳ�ʼ��
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl; // 1 ���ֵ
//	}
//private:
//	int _a2; // ������
//	int _a1; // ������
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}


//class A
//{
//public:
//	/*explicit*/ A(int a, int b)
//		:_a1(a)
//		, _a2(b)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//		, _a2(aa._a2)
//	{
//		cout << "A(const A & aa)" << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	// ���������캯�� C++98
//	//A aa1(1); // ���캯��
//	//A aa2 = 1; // ��ʽ����ת��������A���͵���ʱ���� ����+����+�Ż�->����
//	//const A& ref = 10;
//
//	// ��������캯�� C++11
//	A aa1(1, 2);
//	A aa2 = { 1, 2 };
//	const A& ref = { 2, 2 };
//
//	int i = 0;
//	double d = i; // ��ʽ����ת����i�м������ʱ�������г���,Ȼ��ת��Ϊdouble����
//
//	return 0;
//}

//class A
//{
//public:
//	A() 
//	{ 
//		++_scount; 
//	}
//	
//	A(const A& t) 
//	{ 
//		++_scount; 
//	}
//	~A() 
//	{ 
//		--_scount; 
//	}	
//
//	// ��̬��Ա���� -- û��thisָ��
//	static int GetACount() 
//	{
//		// _a++; // ���ܷ��ʷǾ�̬��Ա
//		return _scount; 
//	}
//private:
//	// ������ĳ�������������ж�������������
//	static int _scount; // ����
//};
//
//int A::_scount = 0; // �����ʼ��
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	A aa4[10];
//	A* ptr = nullptr;
//
//	cout << ptr->GetACount() << endl;
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	cout << A::GetACount() << endl;
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	// d1 << cout; -> d1.operator<<(&d1, cout); �����ϳ������
//	// ��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time
//{
//	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};



//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	// �ڲ��� -- �� A �Ƕ�����ֻ����A��������
//	class B // B��������A����Ԫ
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A aa;
//	cout << sizeof(A) << endl; // ֻ���ⲿ��
//
//	A::B b; // �����A���˽�����ⲿ�޷����ʵ�B��
//	b.foo(A());
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//A func()
//{
//	int n = 0;
//	cin >> n;
//	int ret = Solution().Sum_Solution(n);
//
//	// ֮ǰͨ������һ������������A���͵�ֵ
//	//A retA(ret);
//	//return retA;
//	return A(ret); // ֱ��ͨ���������󷵻�
//}
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << endl;
//	}
//};
//int main()
//{
//	// ����������������ֻ����һ��
//	Solution();
//	cout << Solution().Sum_Solution(1) << endl; // һ���ԣ���ʱʹ��
//
//	return 0;
//}


class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{}

void func2(const A& aa)
{}

//int main()
//{
//	A aa1 = 1; // ����+��������->�Ż�Ϊֱ�ӹ���
//
//	func1(aa1); // ���Ż�
//	cout << "--------------------" << endl;
//	func1(1); // ����+��������->�Ż�Ϊֱ�ӹ���
//	cout << "--------------------" << endl;
//	func1(A(2)); // ����+��������->�Ż�Ϊֱ�ӹ���
//	cout << "--------------------" << endl;
//	func2(aa1); // ���Ż�
//	cout << "--------------------" << endl;
//	func2(1); // ���Ż�
//	cout << "--------------------" << endl;
//	func2(A(2)); // ���Ż�
//	cout << "--------------------" << endl;
//	return 0;
//}

A func3()
{
	A aa;
	return aa; // ����������һ�������һ���������� 
}

int main()
{
	func3(); // func3�������������п��ܲ�������Ż�
	cout << "--------------------" << endl;
	A aa1 = func3(); // ����+��������+��������->����+��������
}