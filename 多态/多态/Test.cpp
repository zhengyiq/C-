#include <iostream>

using namespace std;

// 虚函数的重写 -- 三同（函数名、参数、返回值）
// 父类的指针或引用调用
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	 //void BuyTicket() { cout << "买票-全价" << endl; } // 隐藏
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	void BuyTicket() { cout << "买票-半价" << endl; }
//	
//	~Student() { cout << "~Student()" << endl; }
//};
//
////void Func(Person& p)
////{
////	// 不满足多态 -- 看调用者的类型，调用这个类型的成员函数
////	// 满足多态 -- 看指向对象的类型，调用这个类型的成员函数
////	p.BuyTicket();
////}
//
//void Func(Person* p)
//{
//	//p->BuyTicket();
//	delete p;
//}
//
//int main()
//{
//	//Person p;
//	//Student s;
//
//	//Func(p);
//	//Func(s);
//
//	//s.Person::BuyTicket();
//
//	Func(new Person);
//	Func(new Student);
//
//
//	return 0;
//}


//////协变(基类与派生类虚函数返回值类型不同)
//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};
//
//class Person {
//public:
//	//virtual Person* BuyTicket() 
//	//{ 
//	//	cout << "买票-全价" << endl; 
//	//	return this;
//	//}
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};

// 多态的条件：
// 1、虚函数的重写 -- 三同(函数名、参数、返回值) 
//    -- 例外(协变)：返回值可以不同，必须是父子关系指针或者引用
//    -- 例外：子类虚函数可以不加virtual
// 2、父类指针或者引用去调用

//// 协变：返回值可以不同，必须是父子关系指针挥着引用
//// 不一定是本身这个父子类，其余的父子类也可以，返回的必须是父子类关系
//class Student : public Person {
//public:
//	//virtual Student* BuyTicket()
//	//{
//	//	cout << "买票-半价" << endl;
//	//	return this;
//	//}
//	virtual B* BuyTicket()  
//	{  
//		cout << "买票-半价" << endl; 
//		return nullptr;
//	}
//};
//
//void Func(Person& p)
//{
//	// 不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 满足多态 -- 看指向对象的类型，调用这个类型的成员函数
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Func(p);
//	Func(s);
//
//	s.Person::BuyTicket();
//
//	return 0;
//}


//////////////////C++11 override 和 final
//final：修饰虚函数，表示该虚函数不能再被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


//override : 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。
//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

///////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }	
//};
//
//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}


//// 抽象类 -- 不能实例化出对象 强制子类进行重写
// 一个类在现实中没有对应的实体，就可以将一个类定义为抽象类
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//}; 
//
//void Test()
//{
//	Car car; // err
//	Benz car_benz; 
//}

// 抽象类与override的区别
// override 检查是否完成重写
// 抽象类 间接强制重写


//////////////////////////////////////////////////////////////////////////////////
//// 原理层
//// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bb;
//
//	return 0;
//}


// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void Func() { cout << "买票-全价" << endl; }
//
//	int _a = 0;
//
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	int _b = 1;
//};
//
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	//Person mike;
//	//Func(mike);
//
//	Student johnson;
//	Func(johnson);
//
//	Person mike = johnson;
//
//	return 0;
//}

////////////////////////////////////////////////////////////4月4日////////////////////////////////////////////

//class Base
//{
//public:
//	Base()
//		:_b(10)
//	{
//		++_b;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)(); // 声明一个函数指针，函数指针与一般的typedef不同，不能够写成这样的形式 typedef void(*)() VF_PTR
//
////void PrintVFTable(VF_PTR table[])
//void PrintVFTable(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base b;
//	Derive d;
//	
//	// 有两种方式：
//	// 第一种方式有缺陷只能在32位的系统下使用，若是转换到了64位的系统就需要使用一种占据八个字节的指针
//	// 第二种方式就是直接使用*(VF_PTR**)的方法
//	//PrintVFTable((VF_PTR*)*(int*)&b);
//	//PrintVFTable((VF_PTR*)*(int*)&d);
//	PrintVFTable(*(VF_PTR**)&b);
//	PrintVFTable(*(VF_PTR**)&d);
//
//	// 虚表是在什么时候生成？ -- 编译
//	// 对象中的虚表指针是在什么时候初始化的？ -- 构造函数的初始化列表
//	// 虚表存在哪里？-- 常量区，代码段
//
//	return 0;
//}

//int main()
//{
//	Base b;
//	Derive d;
//
//	int x = 0;
//	static int y = 0;
//	int* z = new int;
//	const char* p = "xxxxxxxxxxxxxxxxxx";
//
//	printf("栈对象：%p\n", &x);
//	printf("堆对象：%p\n", z);
//	printf("静态区对象：%p\n", &y);
//	printf("常量区对象：%p\n", p);
//	printf("b对象虚表：%p\n", *((int*)&b));
//	printf("d对象虚表：%p\n", *((int*)&d));
//	return 0;
//}


//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int bb;
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)(); // 声明一个函数指针，函数指针与一般的typedef不同，不能够写成这样的形式 typedef void(*)() VF_PTR
//
////void PrintVFTable(VF_PTR table[])
//void PrintVFTable(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Derive d;
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//	PrintVFTable((VF_PTR*)(*(int*)((char*)&d+sizeof(Base1)))); // 这里先要将&dDerive*类型的地址转换为char*的地址才能加上Base1的大小，在与之前一样转换为int*类型再解引用转换成VF_PTR*类型即可
//	//Base2* ptr2 = &d; // 简便的方法是我们可以对Derive类进行切片获得的自然就是Base2的地址。
//	//PrintVFTable((VF_PTR*)(*(int*)(ptr2)));
//	return 0;
//}

//int main()
//{
//	Derive d;
//	Base1* ptr1 = &d;
//	Base2* ptr2 = &d;
//	ptr1->func1();
// 
//	ptr2->func1();
//	return 0;
//}

class A
{
public:
	virtual void func1()
	{}
public:
	int _a;
};

class B : virtual public A
{
public:
	virtual void func1()
	{}

	virtual void func2()
	{}
public:
	int _b;
};

class C : virtual public A
{
public:
	virtual void func1()
	{}

	virtual void func3()
	{}
public:
	int _c;
};

class D : public B, public C
{
public:
	virtual void func1()
	{

	}
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}