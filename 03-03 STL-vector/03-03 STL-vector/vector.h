#pragma once
#include <string.h>
#include <assert.h>


namespace zyq
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}

		// insert后默认pos失效，不能再使用
		void insert(iterator pos, const T& val) // 这里不能使用引用传参， v1.begin()返回的是临时对象，临时对象具有常性。
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (size() + 1 > capacity())
			{
				size_t len = pos - _start; // 若是遇到了需要扩容的问题pos指针的指向会发生变化失效，需要有记录来确保其不会失效
				reserve(size() + 1);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = val;
			++_finish;
		}

		void earse(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			
			iterator end = pos + 1;
			while (end < _finish) // end != _finish
			{
				*(end - 1) = *end;
				++end;
			}

			--_finish;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				// 删除数据
				_finish = _start + n;
			}
			else 
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n) 
		{
			if (n > capacity())
			{
				size_t sz = size(); 
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
				}
				delete[] _start;
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;
			}
		}
		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = val;
			++_finish;
		}
		void pop_back() const
		{
			assert(!empty());
			--_finish;
		}

		bool empty() const
		{
			return _finish == _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void func(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void Testvector1()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();


		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;
	}

	template<class T>
	void f()
	{
		T x = T();
		cout << x << endl;
	}
	void Testvecror2()
	{
		// 内置类型有没有构造函数
		int x = int();
		int y = int(1);
		//int* z = int* ();
		
		f<int>();
		f<int*>();
		f<double>();
	}

	void Testvector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(10);
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.resize(3);
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
	}

	void Testvector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);
		
		//v1.insert(v1.begin(), 0);

		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

		auto pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.insert(pos, 30);
		}
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;
	}

	void Testvector5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);

		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

		auto pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.earse(pos);
		}
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;
	}
}
