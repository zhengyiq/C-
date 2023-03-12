#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <cstring>
#include <iostream>
#include <assert.h>
using namespace std;

namespace zyq
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//string() 
		//	:_str(nullptr)
		//	, _size(0)
		//	, _capacity(0)
		//{}

		//string (const char* str)
		//	:_str(str) 
		//	,_size(strlen(str))
		//	, _capacity(strlen(str))
		//{}

		//string() 
		//	:_str(new char[1]) // 不能不添加[]，在析构时可以统一管理
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	_str[0] = '\0';
		//}

		//string(const char* str = nullptr) // 缺省参数：1、nullptr 崩溃 会解引用
		//string(const char* str = '\0') // 2、类型不匹配，char被转换成为int，str也被当做空指针，崩溃
		//string(const char* str = "\0") // 3、可以当时没有必要
		string(const char* s = "") // 常量字符串默认以"\0"结束
			//:_str(str) // 权限的放大不能将 char* 的变量赋给const char*
			:_size(strlen(s))
			//, _capacity(strlen(str)) // strlen是一个O(N)的接口不宜连续调用
		{
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, s);
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		// 不修改成员变量数据的函数最好都加上const 
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s) const
		{
			return *this == s || *this > s;
			//return *this == s || s > *this;
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				// 删除数据保留前N个
				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2); // 空间越界的问题
			}
			_str[_size] = ch;
			++_size;
			_str[_size + 1] = '\0';
		}

		void append(const char* s)
		{
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			//strcat(_str, s); // 不好需要遍历字符串寻找"\0"
			_size += len;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}

			size_t end = _size + 1;
			while (end > pos) // 当end = -1时由于是无符号整形数据因此会变为无符号整形的最大值，这里也不可以使用int类型，会有整形提升的问题
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end > pos + len - 1) // 当len = 1 时就会与插入字符一致
			{
				_str[end] = _str[end - len];
				--end;
			}

			//size_t end = _size;
			//for (size_t i = 0; i < _size + 1; ++i)
			//{
			//	_str[end + len] = _str[end];
			//	--end;
			//}

			// 拷贝插入
			strncpy(_str + pos, s, len);
			_size += len;
		}

		void earse(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if ((len == npos) || (pos + len >= _size))
			{
				_str[pos] = '\0';
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}


		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		// swap(s1, s2);
		// s1.swap(s2);
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* s, size_t pos = 0)
		{
			assert(pos < _size);
			char* ret = strstr(_str, s);
			if (ret == nullptr)
			{
				return npos;
			}
			else
			{
				return ret - _str;
			}
		}

		void clear()
		{
			_str[0];
			_size = 0;
		}

	private:
		//const char* _str;
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
		// 可以
		//static const size_t npos = -1;

		/*	static const size_t N = 10;
			int _a[N];*/

			// 不可以
			//static const double dpos = 1.1;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch; // '\0'可能不会打出来
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		//s.clear();

		//char ch = in.get();
		////in >> ch;
		//while (ch != ' ' && ch != '\n') // 空格和换行没有进入缓冲区，空格和换行被视为多个值之间的间隔
		//{
		//	s += ch; // 当输入的字符串比较长时，需要频繁的扩容
		//	//in >> ch;
		//	ch = in.get();
		//}

		s.clear();

		char ch = in.get();
		char buff[128];
		size_t i = 0;
		//in >> ch;
		while (ch != ' ' && ch != '\n') // 空格和换行没有进入缓冲区，空格和换行被视为多个值之间的间隔
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl; // 会崩溃的问题是，cout自动识别类型const char* 会对字符串进行解引用就会露出null报错
		cout << s2.c_str() << endl;

		s2[0]++;
		cout << s2.c_str() << endl;

		string s3(s2);
		cout << s3.c_str() << endl;
	}

	void test_string2()
	{
		string s1;
		string s2("hello world");

		string s3(s2);
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		s2[0]++;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

		s1 = s1;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void Print(const string& s) // const对象
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i] << " ";
		}
		cout << endl;

		string::const_iterator it = s.begin(); // 只能读不能写
		while (it != s.end())
		{
			//*it = 'x';
			++it;
		}
		cout << endl;

		for (auto ch : s)// 范围for的基底为迭代器， 不支持范围for因为是const对象，不能调用非const的函数
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		Print(s1);

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)--;
			++it;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : s1) // 范围for的基底为迭代器
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("hello world");
		string s3("xx");

		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 >= s2) << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		//s1.push_back(' ');
		//cout << s1.c_str() << endl;
		//s1.append("xxxxxxxxxxxxxxxxxxxx");
		//cout << s1.c_str() << endl;

		//string s2;
		//s2.push_back(' ');
		//cout << s2.c_str() << endl;
		//s2.append("xxxxxxxxxxxxxxxxxxxx");
		//cout << s2.c_str() << endl;

		//s1 += ' ';
		//s1 += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

		//cout << s1.c_str() << endl;

		//string s2;
		//s2 += 'a';
		//s2 += 'b';
		//s2 += 'c';
		//s2 += 'c';
		//s2 += 'c';
		//s2 += 'c';
		//s2 += 'c';
		//s2 += 'c';
		//cout << s2.c_str() << endl;

		//s1.insert(5, 'x');
		//cout << s1.c_str() << endl;

		//s1.insert(0, 'x');
		//cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		s1.insert(5, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
	}

	void test_string7()
	{
		string s1;
		s1.resize(10, 'y');
		cout << s1.c_str() << endl;

		s1.resize(20, 'x');
		cout << s1.c_str() << endl;

		s1.resize(15, 'x');
		cout << s1.c_str() << endl;
	}

	void test_string8()
	{
		string s1("0123456789");
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;

		s1.insert(3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(3, "yyy");
		cout << s1.c_str() << endl;

		s1.insert(0, "yyy");
		cout << s1.c_str() << endl;
	}

	void test_string9()
	{
	 	string s1("0123456789");
		s1.earse(4, 3);
		cout << s1.c_str() << endl;

		s1.earse(4, 30);
		cout << s1.c_str() << endl;

		s1.earse(2);
		cout << s1.c_str() << endl;
	}

	void test_string10()
	{
		string s1("0123456789");
		s1 += '\0';
		s1 += "++++++++";
		cout << s1 << endl; 	
	}

	void test_string11()
	{
		string s1("asdadadadsa");
		cin >> s1;
		cout << s1 << endl;
	}

	void test_string12()
	{
		string s1("0123456789");
		s1.reserve(15);
		cout << s1.c_str() << endl;

		s1.reserve(5);
		cout << s1.c_str() << endl;

		//s1.reserve(5);
		//cout << s1.c_str() << endl;
	}
}

