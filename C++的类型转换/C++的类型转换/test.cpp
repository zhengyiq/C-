#include <iostream>
#include <functional>
#include <set>
using namespace std;
// 类型转换

//void Test()
//{
//	int i = 1;
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换
//	int address = (int)p;
//
//	printf("%x, %d\n", p, address);
//}
//
//int main()
//{
//	Test();
//}

// pos == 0时就会出问题
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
//	int a = static_cast<int>(d); // 用于相似类型的转换
//	cout << a << endl;
//
//	// int* p = static_cast<int*>(a); // err
//
//	int* p = reinterpret_cast<int*>(a); // 用于不相关类型的转换
//	
//	return 0;
//}

//void main()
//{
//	volatile const int a = 2; // 被编译器优化
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
	cout <<"pa指向"<<s << endl;

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = (B*)pa;			   // 不安全的
	B* pb2 = dynamic_cast<B*>(pa); // 安全的

	cout << "[强制转换]pb1:" << pb1 << endl; // p强制转化成B*，存在风险，因为如果B有自己的成员，那么使用指针就可以访问这些成员，但是这种访问是越界的
	cout << "[dynamic_cast转换]pb2:" << pb2 << endl << endl;
}

void main()
{
	// 子类转父类是天然支持的 对象、指针、引用；赋值兼容规则语法直接支持

	// 父类转子类，对象是不可以的，指针和引用可以进行转换

	A a;
	B b;
	fun(&a, "指向父类对象");
	fun(&b, "指向子类对象");

	cout << typeid(a).name() << endl;

	function<bool(int, int)> gt = [](int x, int y) {return x > y; };
	set<int, decltype(gt)> s;
}