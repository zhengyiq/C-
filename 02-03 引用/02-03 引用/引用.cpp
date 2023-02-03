#include <iostream>
#include <assert.h>
using namespace std;

//void TestRef()
//{
//	int a = 10;
//	int& ra = a; // 定义引用类型
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
//void SLPushBack(Node** pphead, int x); // 在之前的学习的数据结构之中，使用了二级指针来进行尾插等操作
//void SLPushBack(Node*& phead, int x); // 同样学习了引用之后就可以理解一些数据结构书中的代码
//void SLPushBack(PNode& head, int x);

//int Count()
//{
//	int n = 0; // 没有static，n是临时变量存储在Count函数的栈帧中，返回时不能直接把n赋值给ret，出了作用域后就会被销毁，n的空间还在但是该空间的使用权已经不属于n，再次访问该空间属于非法行为。所以会产生临时变量来接受n的值，再将临时变量的值拷贝给ret。临时变量较小时会使用寄存器，较大时就会在main函数栈帧中开辟。
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
//	static int n = 0; // 有static时，数据n存储在静态区，栈帧销毁不会影响n，但是还是会与上述一致使用临时变量作为返回值。
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
//	static int n = 0; // 产生的是n的别名，相当于使用n直接返回
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
//	return ay.a[i]; // 出了作用域还存在，就可以使用引用作为返回值
//}
//// 引用返回
//// 1、减少拷贝
//// 2、调用者可以修改返回对象
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

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}