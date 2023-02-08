#include <iostream>
using namespace std;

class Stack
{
public:
	Stack()
	{
		cout << "Stack()" << endl;

		_a = nullptr;
		_size = _capacity = 0;
	}

	Stack(int n)
	{
		cout << "Stack(int n)" << endl;

		_a = (int*)malloc(sizeof(int) * n);
		if (nullptr == _a)
		{
			perror("malloc����ռ�ʧ��");
			return;
		}

		_capacity = n;
		_size = 0;
	}

	void Push(int x)
	{
		//...
		_a[_size++] = x;
	}

	bool Empty()
	{
		// ...
		return _size == 0;
	}

	int Top()
	{
		//...
		return _a[_size - 1];
	}

	//...
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	// ��Ա����
	int* _a;
	int _size;
	int _capacity;
};

//int main()
//{
//	Stack s1;// �����޲ι��캯��
//	Stack s2(4);// ���ô��εĹ��캯��
//	Stack s1();// err
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//	// ���´���ĺ�����������s3�������ú����޲Σ�����һ��Satck���͵Ķ���
//	// warning C4930: ��Stack s3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	s1.Push(1);
//	return 0;
//}

class Date
{
public:
	// 1.�޲ι��캯��
	Date()
	{}
	// 2.���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};
//int main()
//{
//	Date d1; // �����޲ι��캯��
//	//Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//	d1.Print();
//}

class MyQueue 
{
	public:
		// Ĭ�����ɹ��캯�������Զ������ͳ�Ա�����������Ĭ�Ϲ��캯��
		// Ĭ�������������������Զ������ͳ�Ա�������������������
	
		void push(int x) {
	
		}
		//....
	
		Stack _pushST;
		Stack _popST;
		int _size = 0;
};
	
	int main()
	{
		MyQueue q;
	
		return 0;
	}
