#pragma once
namespace zyq
{
	// 适配器模式/配接器
	//template<class T, class Container = list<T>>
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
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

	void test_queue()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;

	}
}

// deque 优点
// 相比vector，扩容代价低 
// 头插头删，尾插尾删效率高
// 支持随机访问

// 缺点
// 中间插入删除很难搞，每个buffer大小不同（影响随机访问），或者每个buffer数组固定大小（保证随机访问影响插入）；效率高会影响随机访问效率变低，牺牲中间插入删除的效率，随机访问效率变高
// SGI选择固定大小
// 没有vector和list极致
 
