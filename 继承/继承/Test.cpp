//#include <iostream>
//
//using namespace std;

//// 基类/父类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected: // 在子类可见的(不能用) 只能防外面
//private:  // 在子类是不可见(不能用)  不仅仅可以放外人还可以防儿子
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//// class Student : public Person
//class Student :  Person // class 默认私有 struct 默认公有
//{
//public:
//	void func()
//	{
//		// 不可见
//		// cout <<_name << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//



//基类和派生类对象的赋值转换

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	double d = 1.7;
//	int i = d; // 隐式类型转换，会产生临时变量
//	const int& ri = d;
//
//	// 天然支持，不存在类型转换，不会产生临时变量
//	Student s;
//	Person p = s; // 一个子类对象可以赋值给一个父类对象
//	Person& rp = s;
//	Person* ptrp = &s;
//
//	return 0;
//}

//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.基类对象不能赋值给派生类对象
//	sobj = pobj;
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj
//	Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}

// 继承中的作用域

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 		// 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << Person::_num << endl;
//		cout << _num << endl;
//	}
//
//protected:
//	// 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。
//	int _num = 999; // 学号
//};

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
// A：两个fun构成函数重载 // 函数重载需要在同一个作用域
// B：两个fun构成隐藏
// C：编译报错
// D：以上说法都不对
//void Test()
//{
//	/*B b;
//	b.fun(10);*/
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//int main()
//{
//	Test();
//	return 0;
//}

// 派生类中的默认成员

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num = 10) // 父类的成员需要调用父类的构造函数，初始化父类的那一部分
//		: _num(num)
//		//: Person(name)
//		//, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: _num(s._num) 
//		//:Person(s)
//		//, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s); // 调用父类中的赋值函数
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	// 析构函数会被处理成destructor
//	~Student()
//	{
//		Person::~Person(); // 析构函数需要保证循序先析构student在析构person
//
//		cout << "~Student()" << endl;
//	}
//	// 子类析构函数完成时，会自定调用父类析构函数，保证先析构子再析构父
//protected:
//	int _num; //学号
//}; // 可以看做子类把父类当做成员
//
//int main()
//{
//	//Student s; // 子类会自动调用父类的构造与析构
//
//	Student s1("张三", 10);
//	//Student s2 = s1;
//
//	//Person p = s1;
//	//s1 = s2;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
////友元
////class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._name << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


// 静态成员

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	//cout << &(p._name) << endl;
//	//cout << &(s._name) << endl;
//
//	//cout << &(p._count) << endl;
//	//cout << &(s._count) << endl;
//
//	Graduate g1;
//	Graduate g2;
//
//	cout << Person::_count << endl;
//	cout << Graduate::_count << endl;
//
//	return 0;
//}


// 实现一个不能被继承的类
// 1、构造函数/析构函数私有化
// 2、final

//class A
//{
//public:
//	static A CreateObj()
//	{
//		return A();
//	}
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A::CreateObj();
//
//	//B bb;
//
//	return 0;
//}


//class A
//{
//private:
//	int _aa;
//};
//
//class B : public A
//{
//private:
//	int _bb;
//};
//
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//
//	return 0;
//}



//#include <iostream>
//
//using namespace std;

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter"; // err
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class A
//{
//public:
//	int _a1;
//	int* _a3;
//};
//
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	int n = 2;
//	D d, d1, d2;
//	d.B::_a1 = 1;
//	d.C::_a3 = &n;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//
//	//B b;
//	//b._a = 10;
//	//b._b = 20;
//	return 0;
//}
#include <iostream>
using namespace std;
class A
{
public:
	A(const char* s) { cout << s << endl; }
	~A(){}
};
class B : virtual public A
{
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C : virtual public A
{
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class D : public B, public C
{
public:
	D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1) { cout << s4 << endl; }
};

int main()
{
	D* p = new D("A", "B", "C", "D");
	delete p;
	return 0;
}



//// Car和BMW Car和Benz构成is-a的关系
//class Car {
//protected:
//	string _colour = "白色"; // 颜色
//	string _num = "陕ABIT00"; // 车牌号
//};
//class BMW : public Car {
//public:
//	void Drive() { cout << "好开-操控" << endl; }
//};
//class Benz : public Car {
//public:
//	void Drive() { cout << "好坐-舒适" << endl; }
//};
//// Tire和Car构成has-a的关系
//class Tire {
//protected:
//	string _brand = "Michelin"; // 品牌
//	size_t _size = 17; // 尺寸
//};
//class Car {
//protected:
//	string _colour = "白色"; // 颜色
//	string _num = "陕ABIT00"; // 车牌号
//	Tire _t; // 轮胎
//};

