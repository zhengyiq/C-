//#include <iostream>
//
//using namespace std;

//// ����/����
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected: // ������ɼ���(������) ֻ�ܷ�����
//private:  // �������ǲ��ɼ�(������)  ���������Է����˻����Է�����
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//// class Student : public Person
//class Student :  Person // class Ĭ��˽�� struct Ĭ�Ϲ���
//{
//public:
//	void func()
//	{
//		// ���ɼ�
//		// cout <<_name << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//



//��������������ĸ�ֵת��

//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	double d = 1.7;
//	int i = d; // ��ʽ����ת�����������ʱ����
//	const int& ri = d;
//
//	// ��Ȼ֧�֣�����������ת�������������ʱ����
//	Student s;
//	Person p = s; // һ�����������Ը�ֵ��һ���������
//	Person& rp = s;
//	Person* ptrp = &s;
//
//	return 0;
//}

//void Test()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.��������ܸ�ֵ�����������
//	sobj = pobj;
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &sobj
//	Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}

// �̳��е�������

//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 		// ���֤��
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
//	// ����͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�������������أ�Ҳ���ض��塣
//	int _num = 999; // ѧ��
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
// A������fun���ɺ������� // ����������Ҫ��ͬһ��������
// B������fun��������
// C�����뱨��
// D������˵��������
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

// �������е�Ĭ�ϳ�Ա

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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num = 10) // ����ĳ�Ա��Ҫ���ø���Ĺ��캯������ʼ���������һ����
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
//			Person::operator=(s); // ���ø����еĸ�ֵ����
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	// ���������ᱻ�����destructor
//	~Student()
//	{
//		Person::~Person(); // ����������Ҫ��֤ѭ��������student������person
//
//		cout << "~Student()" << endl;
//	}
//	// ���������������ʱ�����Զ����ø���������������֤����������������
//protected:
//	int _num; //ѧ��
//}; // ���Կ�������Ѹ��൱����Ա
//
//int main()
//{
//	//Student s; // ������Զ����ø���Ĺ���������
//
//	Student s1("����", 10);
//	//Student s2 = s1;
//
//	//Person p = s1;
//	//s1 = s2;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
////��Ԫ
////class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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


// ��̬��Ա

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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


// ʵ��һ�����ܱ��̳е���
// 1�����캯��/��������˽�л�
// 2��final

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
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter"; // err
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
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



//// Car��BMW Car��Benz����is-a�Ĺ�ϵ
//class Car {
//protected:
//	string _colour = "��ɫ"; // ��ɫ
//	string _num = "��ABIT00"; // ���ƺ�
//};
//class BMW : public Car {
//public:
//	void Drive() { cout << "�ÿ�-�ٿ�" << endl; }
//};
//class Benz : public Car {
//public:
//	void Drive() { cout << "����-����" << endl; }
//};
//// Tire��Car����has-a�Ĺ�ϵ
//class Tire {
//protected:
//	string _brand = "Michelin"; // Ʒ��
//	size_t _size = 17; // �ߴ�
//};
//class Car {
//protected:
//	string _colour = "��ɫ"; // ��ɫ
//	string _num = "��ABIT00"; // ���ƺ�
//	Tire _t; // ��̥
//};

