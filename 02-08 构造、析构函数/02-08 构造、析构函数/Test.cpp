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
			perror("malloc申请空间失败");
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
	// 成员变量
	int* _a;
	int _size;
	int _capacity;
};

//int main()
//{
//	Stack s1;// 调用无参构造函数
//	Stack s2(4);// 调用带参的构造函数
//	Stack s1();// err
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	// 以下代码的函数：声明了s3函数，该函数无参，返回一个Satck类型的对象
//	// warning C4930: “Stack s3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	s1.Push(1);
//	return 0;
//}

class Date
{
public:
	// 1.无参构造函数
	Date()
	{}
	// 2.带参构造函数
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
//	Date d1; // 调用无参构造函数
//	//Date d2(2015, 1, 1); // 调用带参的构造函数
//	d1.Print();
//}

class MyQueue 
{
	public:
		// 默认生成构造函数，对自定义类型成员，会调用他的默认构造函数
		// 默认生成析构函数，对自定义类型成员，会调用他的析构函数
	
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
