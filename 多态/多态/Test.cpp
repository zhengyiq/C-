#include <iostream>

using namespace std;

// �麯������д -- ��ͬ��������������������ֵ��
// �����ָ������õ���
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	 //void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; } // ����
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	
//	~Student() { cout << "~Student()" << endl; }
//};
//
////void Func(Person& p)
////{
////	// �������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
////	// �����̬ -- ��ָ���������ͣ�����������͵ĳ�Ա����
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


//////Э��(�������������麯������ֵ���Ͳ�ͬ)
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
//	//	cout << "��Ʊ-ȫ��" << endl; 
//	//	return this;
//	//}
//	virtual A* BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//		return nullptr;
//	}
//};

// ��̬��������
// 1���麯������д -- ��ͬ(������������������ֵ) 
//    -- ����(Э��)������ֵ���Բ�ͬ�������Ǹ��ӹ�ϵָ���������
//    -- ���⣺�����麯�����Բ���virtual
// 2������ָ���������ȥ����

//// Э�䣺����ֵ���Բ�ͬ�������Ǹ��ӹ�ϵָ���������
//// ��һ���Ǳ�����������࣬����ĸ�����Ҳ���ԣ����صı����Ǹ������ϵ
//class Student : public Person {
//public:
//	//virtual Student* BuyTicket()
//	//{
//	//	cout << "��Ʊ-���" << endl;
//	//	return this;
//	//}
//	virtual B* BuyTicket()  
//	{  
//		cout << "��Ʊ-���" << endl; 
//		return nullptr;
//	}
//};
//
//void Func(Person& p)
//{
//	// �������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
//	// �����̬ -- ��ָ���������ͣ�����������͵ĳ�Ա����
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


//////////////////C++11 override �� final
//final�������麯������ʾ���麯�������ٱ���д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};


//override : ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
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


//// ������ -- ����ʵ���������� ǿ�����������д
// һ��������ʵ��û�ж�Ӧ��ʵ�壬�Ϳ��Խ�һ���ඨ��Ϊ������
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
//		cout << "Benz-����" << endl;
//	}
//}; 
//
//void Test()
//{
//	Car car; // err
//	Benz car_benz; 
//}

// ��������override������
// override ����Ƿ������д
// ������ ���ǿ����д


//////////////////////////////////////////////////////////////////////////////////
//// ԭ���
//// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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


// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
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
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual void Func() { cout << "��Ʊ-ȫ��" << endl; }

	int _a = 0;

};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

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