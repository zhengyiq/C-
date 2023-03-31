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


class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
	virtual void Func() { cout << "买票-全价" << endl; }

	int _a = 0;

};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

	int _b = 1;
};

void Func(Person p)
{
	p.BuyTicket();
}

int main()
{
	//Person mike;
	//Func(mike);

	Student johnson;
	Func(johnson);

	Person mike = johnson;

	return 0;
}