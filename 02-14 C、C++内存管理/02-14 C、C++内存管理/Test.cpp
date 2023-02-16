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
	char char2[] = "abcd";// ��ջ�Ͽ�����һ�����飬�������ַ�����������
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}

//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
//globalVar�����__C__ staticGlobalVar�����__C__
//staticVar�����__C__ localVar�����__A__
//num1 �����__A__�����飩
//char2�����__A__�����飩 * char2�����__A__����Ԫ�أ�
//pChar3�����__A__��ָ�룩 * pChar3�����__D__���������ַ�����
//ptr1�����__A__��ָ�룩 * ptr1�����__B__��ָ��Ŀռ䣩
//2. ����⣺
//sizeof(num1) = __40__;
//sizeof(char2) = __5__; strlen(char2) = __4__;
//sizeof(pChar3) = __4/8__; strlen(pChar3) = __4__;
//sizeof(ptr1) = __4/8__;
//3. sizeof �� strlen ����


void Test2()
{
	// ��̬����һ��int���͵Ŀռ�
	int* ptr4 = new int;
	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* ptr5 = new int(10);
	// ��̬����10��int���͵Ŀռ�
	int* ptr6 = new int[3];
	// ��̬����10��int���͵Ŀռ䲢��ʼ��Ϊ1 2 3 4 0 0 ...
	int* ptr7 = new int[10]{ 1, 2, 3, 4 };
	delete ptr4;
	delete ptr5;
	delete[] ptr6;
	delete[] ptr7;
}

//int main()
//{
//	//// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//	//A* p1 = (A*)malloc(sizeof(A));
//	//A* p2 = new A(1);
//	//free(p1);
//	//delete p2;
//
//	//// ���������Ǽ�����һ����
//	//int* p3 = (int*)malloc(sizeof(int)); // C
//	//int* p4 = new int;
//	//free(p3);
//	//delete p4;
//	////free(p4);
//	////delete p3; �����齻��ʹ��
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
//	// ʧ�������쳣
//	int* p1 = (int*)operator new(sizeof(int*));
//
//	// ʧ�ܷ���nullptr
//	int* p2 = (int*)malloc(sizeof(int*));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	 // ����ռ� operator new -> ��װmalloc
//	 // ���ù��캯��
//	A* p5 = new A;
//
//	// �ȵ�����������
//	// ��operator delete p5ָ��Ŀռ�
//	delete p5;
//	
//	// ����ռ� operator new [] -> operator new -> ��װmalloc
//	A* p6 = new A[10];
//
//	// �ȵ�����������
//	// ��operator delete [] p6ָ��Ŀռ�
//	delete[] p6;
//
//	// ���ֲ��ᱨ����Ϊ���õ�int����������
//	int* p7 = new int[10];
//	free(p7);// �����ͷ�
//
//	// ���ֲ��ᱨ����Ϊ��A�е���������û����Դ���ͷţ�û���ڴ�й©�����freeû�е�������������Ҳ�����б���
//	A* p8 = new A;
//	delete p8;
//	//free(p8);// �ٵ������������������ڴ�й©
//
//	Stack st;// �Զ������ͻ��Զ�������������
//	Stack* pst = new Stack;// ָ�����������Ͳ������������������Ҫʹ��delete
//	delete pst;// �����delete������ռ���Ҫ�ͷţ����Դ������ͼƬ�п���
//
//	A* p9 = new A[10];
//	//free(p9);// ��ƥ�䣬freeʱָ��λ�ò���
//	//delete p9;// ��ƥ�䣬freeʱָ��λ�ò���
//	delete[] p9;//  ��Ϊnewʱ�Ѿ�֪����Ҫ����10�ι��캯���������Ҫ����10��������������������ô֪����Ҫ����10�Σ���������࿪��һЩ�ռ䣬��ͷ���Ŀռ���ռ���˿�ʼ�ĸ��ֽ�����¼��������֪��������Ҫ���ö��ٴ���������������ͷ�ʱָ���λ�ò����ʼ�����ʼ����һ�㡣
//	// ��������������Ҫ������ʱ�����������
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

	// ��һ�����еĿռ��ʼ�� -- ����new
	//new(p1)A;
	new(p1)A(1);

	A* p2 = new A;

	p1->~A();
	free(p1);

	delete p2;

	return 0;
}


