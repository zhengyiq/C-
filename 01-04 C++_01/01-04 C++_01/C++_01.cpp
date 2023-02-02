// 1、命名空间
// 
// 在C中会遇到的一个问题，因此在c++中提出了命名空间这个概念

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "List.h"
// 在C语言中有局部域/全局域
// 1、使用    2、声明周期
// error C2365 : “rand”: 重定义；以前的定义是“函数”

// int rand = 10;
//int a = 10;
//void func()
//{
//	int a = 20;
//	printf("%d", a);
//	printf("%d", ::a);// 域作用限定符
//}
//
//int main()
//{
//	func();
//	printf("%d", List::rand);
//	return 0;
//}

// 命名空间使用关键字namespace，后面跟命名空间的名字
// 命名空间中可以定义变量/函数/类型
// 命名空间中可以嵌套命名空间
// 同一个工程中存在多个相同名称的命名空间，编译器最后会合成一个命名空间

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

//// 命名空间的使用
//int main()
//{
//	// 命名空间的三种使用方式
//	// 1、加命名空间名称及作用域限定符
//	zyq::rand;
//	zyq::func();
//	zyq::zyq2::rand2;
//
//	// 2、使用using将命名空间中某个成员引入
//	using zyq::rand;
//	rand;
//
//	// 3、使用using namespace 命名空间名称引入
//	using namespace zyq;
//	rand;
//	func();
//	zyq2::rand2;
//}

// 2、c++的输入与输出
// std是c++标准库的命名空间，c++将标准库的定义实现都放到这个命名空间中

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> a >> b >> c;
//
//	cout << a << b << c << endl;
//	return 0;
//}

//3、缺省参数
#include <iostream>
using namespace std;

// 全缺省参数
void func(int a = 10, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << endl;
}

// 半缺省参数
// 半缺省参数必须从右往左依次给出，不能间隔着给
// 缺省参数不能在函数声明和定义中同时出现
// 缺省值必须是常量或者全局变量
// C语言不支持（编译器不支持)
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
