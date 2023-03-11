#pragma once

namespace zyq
{
	template <class T>
	struct list_node {
	
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& x = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}

	};

	// 1、迭代器要么就是原生指针
	// 2、迭代器要么就是自定义类型对原生指针的封装，模拟指针的行为
	template <class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;

		node* _node;

		__list_iterator(node* n)
			:_node(n)
		{}

		//T& operator*()
		//{
		//	return _node->_data;
		//}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;

			return *this;
		}
		
		self operator++(int)
		{
			self* tmp(*this);
			_node = _node->_next;
			
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;

			return *this;
		}

		self operator--(int)
		{
			self* tmp(*this);
			_node = _node->_prev;

			return tmp; 
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	template <class T>
	class list
	{
	public:
		typedef list_node<T> node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef const __list_iterator<T> const_iterator; // 这样导致迭代器本身不能修改无法++ 这里需要const T* 而不是T* const

		iterator begin()
		{
			//iterator it(_head->_next);
			//return it;
			return iterator(_head->_next);
		}

		iterator end()
		{
			//iterator it(_head);
			//return it;
			return iterator(_head);
		}

		const_iterator begin() const // 修饰*this， 可以被复制
		{
			//iterator it(_head->_next);
			//return it;
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			//iterator it(_head);
			//return it;
			return const_iterator(_head);
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			//node* tail = _head->_prev;
			//node* newnode = new node(x);
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* new_node = new node(x);

			prev->_next = new_node;
			new_node->_prev = prev;
			new_node->_next = cur;
			cur->_prev = new_node;
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
		}

	private:
		node* _head;
	};

	void print(const list<int>& l1) // 只在begin函数中添加const没有效果，不能修改迭代器，但是拷贝后的迭代器依旧可以对内部进行修改
	{
		list<int>::const_iterator it = l1.begin();
		while (it != l1.end())
		{
			//(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> l1;

		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin(); // 本来需要拷贝构造函数，这里迭代器没有析构函数 ，浅拷贝没有问题
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << endl;

		print(l1);
	}
	
	class AA
	{
	public:
		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
		int _a1;
		int _a2;
	};

	void test_list2()
	{
		list<AA> l1;
		l1.push_back(AA(1, 1));
		l1.push_back(AA(2, 2));
		l1.push_back(AA(3, 3));
		
		// AA* ptr
		list<AA>::iterator it = l1.begin();
		while (it != l1.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;		
			cout << it->_a1 << ":" << it->_a2 << endl; // 本来应该是->->但是编译器优化了，为了增加可读性，省略了一个->
			cout << it.operator->()->_a1 << ":" << it.operator->()->_a1 << endl;
			++it;
		}
		cout << endl;
	}
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = lt.begin();
		++pos;
		lt.insert(pos, 20);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(100);
		lt.push_front(1000);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_front();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}