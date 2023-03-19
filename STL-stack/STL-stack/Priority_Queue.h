#pragma once

namespace zyq
{
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:

		priority_queue()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push(*first);
				++first;
			}
		}

		void adjust_up(int child)
		{
			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				// 建立大堆
				//if (_con[parent] < _con[child])
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(int parent)
		{
			size_t child = parent * 2 + 1;

			while (child < _con.size())
			{
				//if (child + 1 < _con.size() 
				//	&& _con[parent * 2 + 1] < _con[parent * 2 + 2])
				if (child + 1 < _con.size()
					&& Compare()(_con[parent * 2 + 1], _con[parent * 2 + 2]))
				{
					++child;
				}

				//if (_con[parent] < _con[child]) 
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_priority_queue1()
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(1);
		pq.push(0);
		pq.push(5);
		pq.push(2);
		pq.push(1);
		pq.push(7);
		pq.push(8);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

	void test_priority_queue2()
	{
		int a[] = { 1,2,3,4,5,6 };

		//vector<int> v(a, a + 4);

		//priority_queue<int> pq(v.begin(), v.end());
		priority_queue<int> pq(a, a + sizeof(a) / sizeof(a[0]));

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
		friend ostream& operator<<(ostream& _cout, const Date& d)
		{
			_cout << d._year << "-" << d._month << "-" << d._day;
			return _cout;
		}
	private:
		int _year;
		int _month;
		int _day;
	};

	struct PDateLess
	{
	public:
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 < *p2;
		}
	};

	struct PDateGreater
	{
	public:
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 > *p2;
		}
	};

	void TestPriorityQueue()
	{
		// 大堆，需要用户在自定义类型中提供<的重载
		priority_queue<Date> q1;
		q1.push(Date(2018, 10, 29));
		q1.push(Date(2018, 10, 28));
		q1.push(Date(2018, 10, 30));
		cout << q1.top() << endl;

		priority_queue<Date*, vector<Date*>, PDateLess> q2; // 结果会发生变化因为再比较时比较的是地址而不是指向的日期内容，没有构建Date*的仿函数
		q2.push(new Date(2018, 10, 29));
		q2.push(new Date(2018, 10, 28));
		q2.push(new Date(2018, 10, 30));
		cout << *(q2.top()) << endl;

		// 如果要创建小堆，需要用户提供>的重载
		//priority_queue<Date, vector<Date>, greater<Date>> q2;
		//q2.push(Date(2018, 10, 29));
		//q2.push(Date(2018, 10, 28));
		//q2.push(Date(2018, 10, 30));
		//cout << q2.top() << endl;
	}
}