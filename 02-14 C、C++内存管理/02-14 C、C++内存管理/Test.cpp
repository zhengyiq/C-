#include <iostream>
using namespace std;

class Stack
{
public:
	Stack()
	{
		cout << "Stack()" << endl;
		_a = new int[4];
		_top = 0;
		_capacity = 4;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[] _a;
		_top = _capacity = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

int globalVar = 1;
static int staticGlobalVar = 1;
void Test1()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";// 在栈上开辟了一个数组，将常量字符串拷贝过来
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}

//1. 选择题：
//选项 : A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
//globalVar在哪里？__C__ staticGlobalVar在哪里？__C__
//staticVar在哪里？__C__ localVar在哪里？__A__
//num1 在哪里？__A__（数组）
//char2在哪里？__A__（数组） * char2在哪里？__A__（首元素）
//pChar3在哪里？__A__（指针） * pChar3在哪里？__D__（常量区字符串）
//ptr1在哪里？__A__（指针） * ptr1在哪里？__B__（指向的空间）
//2. 填空题：
//sizeof(num1) = __40__;
//sizeof(char2) = __5__; strlen(char2) = __4__;
//sizeof(pChar3) = __4/8__; strlen(pChar3) = __4__;
//sizeof(ptr1) = __4/8__;
//3. sizeof 和 strlen 区别？


void Test2()
{
	// 动态申请一个int类型的空间
	int* ptr4 = new int;
	// 动态申请一个int类型的空间并初始化为10
	int* ptr5 = new int(10);
	// 动态申请10个int类型的空间
	int* ptr6 = new int[3];
	// 动态申请10个int类型的空间并初始化为1 2 3 4 0 0 ...
	int* ptr7 = new int[10]{ 1, 2, 3, 4 };
	delete ptr4;
	delete ptr5;
	delete[] ptr6;
	delete[] ptr7;
}

//int main()
//{
//	//// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//	//A* p1 = (A*)malloc(sizeof(A));
//	//A* p2 = new A(1);
//	//free(p1);
//	//delete p2;
//
//	//// 内置类型是几乎是一样的
//	//int* p3 = (int*)malloc(sizeof(int)); // C
//	//int* p4 = new int;
//	//free(p3);
//	//delete p4;
//	////free(p4);
//	////delete p3; 不建议交叉使用
//
//	//A* p5 = (A*)malloc(sizeof(A) * 10);
//	//A* p6 = new A[10];
//	//free(p5);
//	//delete[] p6;
//	////delete p5;
//	////free(p6);
//	//return 0;
//
//
//	// 失败了抛异常
//	int* p1 = (int*)operator new(sizeof(int*));
//
//	// 失败返回nullptr
//	int* p2 = (int*)malloc(sizeof(int*));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	 // 申请空间 operator new -> 封装malloc
//	 // 调用构造函数
//	A* p5 = new A;
//
//	// 先调用析构函数
//	// 再operator delete p5指向的空间
//	delete p5;
//	
//	// 申请空间 operator new [] -> operator new -> 封装malloc
//	A* p6 = new A[10];
//
//	// 先调用析构函数
//	// 再operator delete [] p6指向的空间
//	delete[] p6;
//
//	// 这种不会报错因为调用的int是内置类型
//	int* p7 = new int[10];
//	free(p7);// 正常释放
//
//	// 这种不会报错，因为类A中的析构函数没有资源的释放，没有内存泄漏，因此free没有调用析构函数，也不会有报错
//	A* p8 = new A;
//	delete p8;
//	//free(p8);// 少调用了析构函数，有内存泄漏
//
//	Stack st;// 自定义类型会自动调用析构函数
//	Stack* pst = new Stack;// 指针是内置类型不会调用析构函数，需要使用delete
//	delete pst;// 这里的delete有两块空间需要释放，可以从下面的图片中看出
//
//	A* p9 = new A[10];
//	//free(p9);// 不匹配，free时指针位置不对
//	//delete p9;// 不匹配，free时指针位置不对
//	delete[] p9;//  因为new时已经知道需要调用10次构造函数，因此需要调用10次析构函数，那我们怎么知道需要调用10次？编译器会多开批一些空间，在头部的空间中占据了开始四个字节来记录个数，来知道到底需要调用多少次析构函数，因此释放时指针的位置不在最开始而在最开始往后一点。
//	// 当析构函数不需要被调用时，不会崩溃。
//}

//int main()
//{
//	size_t size = 0;
//	while (1)
//	{
//		int* p1 = (int*)malloc(1024 * 1024 * 4);
//		if (p1 == nullptr)
//		{
//			break;
//		}
//
//		size += 1024 * 1024 * 4;
//		cout << p1 << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}


//int main()
//{
//	size_t size = 0;
//
//	try
//	{
//		while (1)
//		{
//			int* p1 = new int[1024 * 1024 * 4];
//			size += 1024 * 1024 * 4;
//			cout << p1 << endl;
//		}
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << size << endl;
//	cout << size / 1024 / 1024 << "MB" << endl;
//
//
//	return 0;
//}

int main()
{
	A aa;

	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == nullptr)
	{
		perror("malloc fail");
	}

	// 对一块已有的空间初始化 -- 定义new
	//new(p1)A;
	new(p1)A(1);

	A* p2 = new A;

	p1->~A();
	free(p1);

	delete p2;

	return 0;
}


