#include <iostream>
#include <assert.h>
using namespace std;

//void TestRef()
//{
//	int a = 10;
//	int& ra = a; // ������������
//	int& rb = ra;
//	cout << "&a:" << &a << endl;
//	cout << "&ra:" << &ra << endl;
//	cout << "&rb:" << &rb << endl;
//}
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	//TestRef();
//	int i = 0;
//	int j = 2;
//
//	Swap(i, j);
//
//	return 0;
//}
//
//typedef struct Node
//{
//	struct Node* next;
//	int val;
//}Node, *PNode;
//
//void SLPushBack(Node** pphead, int x); // ��֮ǰ��ѧϰ�����ݽṹ֮�У�ʹ���˶���ָ��������β��Ȳ���
//void SLPushBack(Node*& phead, int x); // ͬ��ѧϰ������֮��Ϳ������һЩ���ݽṹ���еĴ���
//void SLPushBack(PNode& head, int x);

//int Count()
//{
//	int n = 0; // û��static��n����ʱ�����洢��Count������ջ֡�У�����ʱ����ֱ�Ӱ�n��ֵ��ret�������������ͻᱻ���٣�n�Ŀռ仹�ڵ��Ǹÿռ��ʹ��Ȩ�Ѿ�������n���ٴη��ʸÿռ����ڷǷ���Ϊ�����Ի������ʱ����������n��ֵ���ٽ���ʱ������ֵ������ret����ʱ������Сʱ��ʹ�üĴ������ϴ�ʱ�ͻ���main����ջ֡�п��١�
//	n++;
//	// ...
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	return 0;
//}
//
//int Count()
//{
//	static int n = 0; // ��staticʱ������n�洢�ھ�̬����ջ֡���ٲ���Ӱ��n�����ǻ��ǻ�������һ��ʹ����ʱ������Ϊ����ֵ��
//	n++;
//	// ...
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	return 0;
//}

//int& Count()
//{
//	static int n = 0; // ��������n�ı������൱��ʹ��nֱ�ӷ���
//	n++;
//	// ...
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	return 0;
//}

//#define N 10
//
//typedef struct Array
//{
//	int a[N];
//	int size;
//}AY;
//
//int& PosAT(AY& ay,int i)
//{
//	assert(i < N);
//
//	return ay.a[i]; // ���������򻹴��ڣ��Ϳ���ʹ��������Ϊ����ֵ
//}
//// ���÷���
//// 1�����ٿ���
//// 2�������߿����޸ķ��ض���
//int main()
//{
//	AY ay;
//	for (int i = 0; i < N; ++i)
//	{
//		PosAT(ay, i) = i * 10;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		cout << PosAT(ay, i) << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int Count();
//int main()
//{
//	int a = 1;
//    int& b = a;
//	// ָ������ã���ֵ/��ʼ����Ȩ�޿�����С�����ǲ��ܷŴ�
//	
//	// Ȩ�޷Ŵ�
//	const int c = 2;
//	int& d = c;
//
//	const int* p1 = NULL;
//	int* p2 = p1;
//
//	// Ȩ�ޱ���
//	const int c = 2;
//	const int& d = c;
//
//	const int* p1 = NULL;
//	const int* p2 = p1;
//
//	// Ȩ����С
//	int c = 2;
//	const int& d = c;
//
//	int* p1 = NULL;
//	const int* p2 = p1;
//
//	int& ret = Count(); // ��ʱ��������ֵ���г���
//	const int& ret = Count();
//
//	int i = 0; 
//
//	double& j = i;// ����ת���������ʱ����
//	const double& j = i;
//
//}

int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	return 0;
}