#include <iostream>
using namespace std;

//#define add(x,y) ((x)+(y))
// ���ȥ�����������
// Add(1, 2) * 3 �ȼ��� 1 + 2 * 3
// ���ȥ��������������
// Add(a | b, a & b) �ȼ��� a | b + a & b
// �����������ӷֺ�Ҳ����ִ���
//int main()
//{
//	int ret = add(1, 2);
//}

//inline int Add(int& x, int& y)
//{
//	int z = x + y;
//	z = x + y;
//
//	return z;
//}
//
//int main()
//{
//	int a = 1, b = 2; 
//
//	int ret = Add(a, b);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	auto b = a;
//	auto c = &a;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//}

//typedef char* pstring;
//int main()
//{
//	const pstring p1 = nullptr; // ����ɹ�����ʧ�ܣ�
//	const pstring* p2; // ����ɹ�����ʧ�ܣ�
//	return 0;
//}



//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";
//}
//int main()
//{
//	TestFor();
//}



//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}