// 1�������ռ�
// 
// ��C�л�������һ�����⣬�����c++������������ռ��������

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "List.h"
// ��C�������оֲ���/ȫ����
// 1��ʹ��    2����������
// error C2365 : ��rand��: �ض��壻��ǰ�Ķ����ǡ�������

// int rand = 10;
//int a = 10;
//void func()
//{
//	int a = 20;
//	printf("%d", a);
//	printf("%d", ::a);// �������޶���
//}
//
//int main()
//{
//	func();
//	printf("%d", List::rand);
//	return 0;
//}

// �����ռ�ʹ�ùؼ���namespace������������ռ������
// �����ռ��п��Զ������/����/����
// �����ռ��п���Ƕ�������ռ�
// ͬһ�������д��ڶ����ͬ���Ƶ������ռ䣬����������ϳ�һ�������ռ�

//namespace zyq
//{
//	int rand = 10;
//
//	int func()
//	{
//		return 0;
//	}
//
//	namespace zyq2
//	{
//		int rand2;
//	}
//}

//// �����ռ��ʹ��
//int main()
//{
//	// �����ռ������ʹ�÷�ʽ
//	// 1���������ռ����Ƽ��������޶���
//	zyq::rand;
//	zyq::func();
//	zyq::zyq2::rand2;
//
//	// 2��ʹ��using�������ռ���ĳ����Ա����
//	using zyq::rand;
//	rand;
//
//	// 3��ʹ��using namespace �����ռ���������
//	using namespace zyq;
//	rand;
//	func();
//	zyq2::rand2;
//}

// 2��c++�����������
// std��c++��׼��������ռ䣬c++����׼��Ķ���ʵ�ֶ��ŵ���������ռ���

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	// �����Զ�ʶ�����������
//	cin >> a;
//	cin >> a >> b >> c;
//
//	cout << a << b << c << endl;
//	return 0;
//}

//3��ȱʡ����
#include <iostream>
using namespace std;

// ȫȱʡ����
void func(int a = 10, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << endl;
}

// ��ȱʡ����
// ��ȱʡ������������������θ��������ܼ���Ÿ�
// ȱʡ���������ں��������Ͷ�����ͬʱ����
// ȱʡֵ�����ǳ�������ȫ�ֱ���
// C���Բ�֧�֣���������֧��)
void func2(int a, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << endl;
}

int main()
{
	func(1, 2, 3);
	func(1, 2);
	func(1);
	func();
	
	func2(1, 2, 3);
	func2(1, 2);
	func2(1);
	//func2();

}
