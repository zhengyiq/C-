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

		vector()
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{}

		// vector<int> v1(10, 5);
		vector(size_t n, const T& val = T())
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			//reserve(n);
			_start = new T[n];
			_end_of_storage = _start + n;
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
			_finish = _start + n;
		}

		vector(int n, const T& val = T()) // ���û��ʵ������ģ�庯������ʹ��vector<int> v1(10, 5);��ʱ��ᷢ��������ʹ�õ���������汾�Ĺ��캯��
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		// [first, last)
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			//:_start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			while (first != last) // ������Ҫʹ��!=
			{
				push_back(*first);
				++first;
			}
		}

		//vector(const vector<T>& v)
		//	//:_start(nullptr)
		//	//, _finish(nullptr)
		//	//, _end_of_storage(nullptr)
		//{
		//	//_start = new T[v.capacity()];
		//	//_end_of_storage = _start + v.capacity();
		//	reserve(v.capacity());
		//	for (auto e : v)
		//	{
		//		push_back(e);
		//	}
		//}

		//vector(const vector<T>& v)
		//	//:_start(nullptr)
		//	//, _finish(nullptr)
		//	//, _end_of_storage(nullptr)
		//{
		//	_start = new T[v.capacity()];
		//	for (size_t i = 0; i < v.size(); ++i)
		//	{
		//		_start[i] = v._start[i]; // �����=��Ҫ���������
		//	}
		//	_finish = _start + v.size();
		//	_end_of_storage = _start + v.capacity();
		//}

		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

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

		// insert��Ĭ��posʧЧ��������ʹ��
		// insertӵ�з���ֵ�����ص����²���Ԫ�ص�λ��
		iterator insert(iterator pos, const T& val) // ���ﲻ��ʹ�����ô��Σ� v1.begin()���ص�����ʱ������ʱ������г��ԡ�
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//if (size() + 1 > capacity())
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start; // ������������Ҫ���ݵ�����posָ���ָ��ᷢ���仯ʧЧ����Ҫ�м�¼��ȷ���䲻��ʧЧ
				reserve(size() + 1);
				// ���ݺ����pos�����posʧЧ������
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
			return pos;
		}

		iterator erase(iterator pos)
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
			return pos;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				// ɾ������
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
					//memcpy(tmp, _start, sizeof(T) * size());
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
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

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//reserve(v.capacity());
			//for (auto e : v)
			//{
			//	push_back(e);
			//}
			//return *this;
			swap(v);

			return *this; 
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
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
	void Testvector2()
	{
		// ����������û�й��캯��
		int x = int();
		int y = int(1);
		//int* z = int* (); // err
		
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
			v1.erase(pos);
		}
		for (auto num : v1)
		{
			cout << num << " ";
		}
		cout << endl;
	}

	void Testvector6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(88);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		// Ҫ��ɾ����������

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				it = v1.erase(it); // vs�����ǿ�Ƽ�飬erase�Ժ���������ܷ��ʣ�g++û��ǿ�Ƽ�飬�������������������δ����
			}
			else 
			{
				++it;
			}
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Testvector7()
	{
		//vector<int> v1(10u, 5);
		vector<int> v1(10, 5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		//vector<int> v2(++v1.begin(), --v1.end()) // ��ֵ���أ�������ʱ�������г��Բ����޸�
		vector<int> v2(v1.begin() + 1, v1.end() - 1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		std::string s1("hello");
		vector<char> v3(s1.begin(), s1.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		int a[] = { 10, 20, 30 };
		vector<int> v4(a, a + 3);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.insert(v1.begin(), 10);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(v1.begin(), v1.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(a, a + 3, greater<int>());
		for (auto e : a)
		{
			cout << e << " ";
		}
		cout << endl;
	}

		void Testvector8()
		{
			vector<int> v1(10, 5);
			for (auto e : v1)
			{
				cout << e << " ";
			}
			cout << endl;

			vector<int> v2(v1);
			for (auto e : v2)
			{
				cout << e << " ";
			}
			cout << endl;

			vector<string> v3(3, "1111111111");
			for (auto e : v3)
			{
				cout << e << " ";
			}
			cout << endl;

			vector<string> v4(v3);
			for (auto e : v4)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		class Solution {
		public:
			vector<vector<int>> generate(int numRows) {
				vector<vector<int>> vv;
				vv.resize(numRows, vector<int>()); // ��ʼ������Ĵ�vector
				for (size_t i = 0; i < vv.size(); ++i)
				{
					vv[i].resize(i + 1, 0); // ��ʼ���ڲ���vector
					// vv[i].front() = 1;
					// vv[i].back() = 1;
					vv[i][0] = vv[i][vv[i].size() - 1] = 1;
				}

				for (int i = 2; i < vv.size(); ++i)
				{
					for (int j = 1; j < vv[i].size() - 1; ++j)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
				return vv;
			}
		};

		void Testvector9()
		{
			vector<int> v1(10, 5);
			for (auto e : v1)
			{
				cout << e << " ";
			}
			cout << endl;

			vector<int> v2;
			v2 = v1;
			for (auto e : v2)
			{
				cout << e << " ";
			}
			cout << endl;

			vector<vector<int>> ret = Solution().generate(5);
			for (int i = 0; i < ret.size(); ++i)
			{
				for (int j = 0; j < ret[i].size(); ++j)
				{
					cout << ret[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void Testvector10()
		{
			std::vector<int> v1(10, 5);
			for (auto e : v1)
			{
				cout << e << " ";
			}
			cout << endl;

			v1.reserve(2);

			for (auto e : v1)
			{
				cout << e << " ";
			}
			cout << endl;
		
		}
}