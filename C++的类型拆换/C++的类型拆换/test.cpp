#include <iostream>
#include <functional>
#include <set>
using namespace std;
// ����ת��

//void Test()
//{
//	int i = 1;
//	// ��ʽ����ת��
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// ��ʾ��ǿ������ת��
//	int address = (int)p;
//
//	printf("%x, %d\n", p, address);
//}
//
//int main()
//{
//	Test();
//}

// pos == 0ʱ�ͻ������
//void insert(size_t pos, char ch)
//{
//	int end = _size;
//	while (end >= pos)
//	{
//		//...
//		--end;
//	}
//}

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d); // �����������͵�ת��
//	cout << a << endl;
//
//	// int* p = static_cast<int*>(a); // err
//
//	int* p = reinterpret_cast<int*>(a); // ���ڲ�������͵�ת��
//	
//	return 0;
//}

//void main()
//{
//	volatile const int a = 2; // ���������Ż�
//	int* p = const_cast<int*>(&a);
//	//int* p = (int*)&a;
//	*p = 3;
//	cout << a << endl;
//	cout << *p << endl;
//}

class A
{
public:
	virtual void f() {}
};

class B : public A
{
	//int _b;
};

void fun(A* pa, const string& s)
{
	cout <<"paָ��"<<s << endl;

	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = (B*)pa;			   // ����ȫ��
	B* pb2 = dynamic_cast<B*>(pa); // ��ȫ��

	cout << "[ǿ��ת��]pb1:" << pb1 << endl; // pǿ��ת����B*�����ڷ��գ���Ϊ���B���Լ��ĳ�Ա����ôʹ��ָ��Ϳ��Է�����Щ��Ա���������ַ�����Խ���
	cout << "[dynamic_castת��]pb2:" << pb2 << endl << endl;
}

void main()
{
	// ����ת��������Ȼ֧�ֵ� ����ָ�롢���ã���ֵ���ݹ����﷨ֱ��֧��

	// ����ת���࣬�����ǲ����Եģ�ָ������ÿ��Խ���ת��

	A a;
	B b;
	fun(&a, "ָ�������");
	fun(&b, "ָ���������");

	cout << typeid(a).name() << endl;

	function<bool(int, int)> gt = [](int x, int y) {return x > y; };
	set<int, decltype(gt)> s;
}