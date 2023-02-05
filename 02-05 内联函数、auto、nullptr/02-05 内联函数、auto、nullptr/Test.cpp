#include <iostream>
using namespace std;

//#define add(x,y) ((x)+(y))
// 如果去掉外面的括号
// Add(1, 2) * 3 等价于 1 + 2 * 3
// 如果去掉操作数的括号
// Add(a | b, a & b) 等价于 a | b + a & b
// 宏结束不能添加分号也会出现错误
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
//	const pstring p1 = nullptr; // 编译成功还是失败？
//	const pstring* p2; // 编译成功还是失败？
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