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


//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void Func() { cout << "��Ʊ-ȫ��" << endl; }
//
//	int _a = 0;
//
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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

////////////////////////////////////////////////////////////4��4��////////////////////////////////////////////

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
//// �ó����ӡ���
//typedef void(*VF_PTR)(); // ����һ������ָ�룬����ָ����һ���typedef��ͬ�����ܹ�д����������ʽ typedef void(*)() VF_PTR
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
//	// �����ַ�ʽ��
//	// ��һ�ַ�ʽ��ȱ��ֻ����32λ��ϵͳ��ʹ�ã�����ת������64λ��ϵͳ����Ҫʹ��һ��ռ�ݰ˸��ֽڵ�ָ��
//	// �ڶ��ַ�ʽ����ֱ��ʹ��*(VF_PTR**)�ķ���
//	//PrintVFTable((VF_PTR*)*(int*)&b);
//	//PrintVFTable((VF_PTR*)*(int*)&d);
//	PrintVFTable(*(VF_PTR**)&b);
//	PrintVFTable(*(VF_PTR**)&d);
//
//	// �������ʲôʱ�����ɣ� -- ����
//	// �����е����ָ������ʲôʱ���ʼ���ģ� -- ���캯���ĳ�ʼ���б�
//	// ���������-- �������������
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
//	printf("ջ����%p\n", &x);
//	printf("�Ѷ���%p\n", z);
//	printf("��̬������%p\n", &y);
//	printf("����������%p\n", p);
//	printf("b�������%p\n", *((int*)&b));
//	printf("d�������%p\n", *((int*)&d));
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
//// �ó����ӡ���
//typedef void(*VF_PTR)(); // ����һ������ָ�룬����ָ����һ���typedef��ͬ�����ܹ�д����������ʽ typedef void(*)() VF_PTR
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
//	PrintVFTable((VF_PTR*)(*(int*)((char*)&d+sizeof(Base1)))); // ������Ҫ��&dDerive*���͵ĵ�ַת��Ϊchar*�ĵ�ַ���ܼ���Base1�Ĵ�С������֮ǰһ��ת��Ϊint*�����ٽ�����ת����VF_PTR*���ͼ���
//	//Base2* ptr2 = &d; // ���ķ��������ǿ��Զ�Derive�������Ƭ��õ���Ȼ����Base2�ĵ�ַ��
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

//class A
//{
//public:
//	virtual void func1()
//	{}
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func3()
//	{}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func1()
//	{
//
//	}
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}
//
//1. ʲô�Ƕ�̬���𣺲ο����ڿμ�����
// ��̬��̬ + ��̬��̬

//2. ʲô�����ء���д(����)���ض���(����)���𣺲ο����ڿμ�����

//3. ��̬��ʵ��ԭ���𣺲ο����ڿμ�����

//4. inline�����������麯���𣿴𣺿��ԣ������������ͺ���inline���ԣ���������Ͳ�����inline����Ϊ�麯��Ҫ�ŵ������ȥ��
//��������û�е�ַ����������������롣�麯���ĵ�ַ��Ҫ�ŵ������
//class A 
//{
//public:
//	inline virtual void func() // ���Ա���ͨ��������ֻ�ǶԱ�������һ�����鲻һ��Ҫִ��
//	{}
//};
//int main()
//{
//	A a;
//	a.func();
//}

//5. ��̬��Ա�������麯���𣿴𣺲��ܣ���Ϊ��̬��Ա����û��thisָ�룬ʹ������::��Ա�����ĵ��÷�ʽ�޷������麯�������Ծ�̬��Ա�����޷��Ž��麯����

//6. ���캯���������麯���𣿴𣺲��ܣ���Ϊ�����е��麯����ָ�����ڹ��캯����ʼ���б�׶βų�ʼ���ġ�
// ��������͹������� ��ֵ���������죬������һ�ֺϳɰ汾�����������ø��࣬��д֮���ǷǸ����ӵĹ�ϵ
// ��ֵ����ʹ�麯�����ǣ���ò�Ҫ

//7. ���������������麯����ʲô�����������������麯�����𣺿��ԣ�������ðѻ������������������麯�����ο����ڿμ�����

//8. ���������ͨ�����컹���麯�����죿�������������ͨ������һ����ġ������ָ�������������ö�������õ���ͨ�����죬��Ϊ���ɶ�̬������ʱ�����麯����Ҫ���麯������ȥ���ҡ�
class A 
{
public:
	virtual void func1()
	{
		cout << "func1()" << endl;
	}

	void func2()
	{
		cout << "func2()" << endl;
	}
};
int main()
{
	A a;
	a.func1();
	//a.func1();
	//	004626F7  lea         ecx, [a]
	//	004626FA  call        A::func1(04613C5h)
	a.func2();
	//a.func2();
	//	004626FF  lea         ecx, [a]
	//	00462702  call        A::func2(0461343h)

	A* ptr = &a;
	ptr->func1(); // ��̬���ã����ʶ�����ͨ���ã��ɱ�̫��

	//ptr->func1(); // ��̬����
	//	002D270D  mov         eax, dword ptr[ptr]
	//	002D2710  mov         edx, dword ptr[eax]
	//	002D2712  mov         esi, esp
	//	002D2714  mov         ecx, dword ptr[ptr]
	//	002D2717  mov         eax, dword ptr[edx]
	//	002D2719  call        eax
	//	002D271B  cmp         esi, esp
	//	002D271D  call        __RTC_CheckEsp(02D129Eh)
}



//9. �麯��������ʲô�׶����ɵģ������ĵģ����麯�������ڱ���׶ξ����ɵģ�һ������´��ڴ����(������)�ġ�
// ���ָ���ڹ��캯����ʼ���б��ʼ��


//10. C++���μ̳е����⣿��̳е�ԭ���𣺲ο��̳пμ���ע�����ﲻҪ���麯�������������ˡ�

//11. ʲô�ǳ����ࣿ����������ã��𣺲ο���3.�����ࣩ��������ǿ����д���麯����������������ֳ��˽ӿڼ̳й�ϵ��