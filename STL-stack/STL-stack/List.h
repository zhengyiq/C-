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

	// 1��������Ҫô����ԭ��ָ��
	// 2��������Ҫô�����Զ������Ͷ�ԭ��ָ��ķ�װ��ģ��ָ�����Ϊ
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

	//template <class T, class Ref, class Ptr>
	//struct __list_reverse_iterator {
	//	typedef list_node<T> node;
	//	typedef __list_reverse_iterator<T, Ref, Ptr> self;

	//	node* _node;

	//	__list_reverse_iterator(node* n)
	//		:_node(n)
	//	{}

	//	//T& operator*()
	//	//{
	//	//	return _node->_data;
	//	//}

	//	Ref operator*()
	//	{
	//		return _node->_data;
	//	}

	//	Ptr operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	self& operator++()
	//	{
	//		_node = _node->_prev;

	//		return *this;
	//	}

	//	self operator++(int)
	//	{
	//		self* tmp(*this);
	//		_node = _node->_prev;

	//		return tmp;
	//	}

	//	self& operator--()
	//	{
	//		_node = _node->_next;

	//		return *this;
	//	}

	//	self operator--(int)
	//	{
	//		self* tmp(*this);
	//		_node = _node->_next;

	//		return tmp;
	//	}

	//	bool operator!=(const self& s)
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const self& s)
	//	{
	//		return _node == s._node;
	//	}
	//};

	template <class T>
	class list
	{
	public:
		typedef list_node<T> node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef const __list_iterator<T> const_iterator; // �������µ������������޸��޷�++ ������Ҫconst T* ������T* const

		typedef Reverse_Iterator<iterator, T&, T*>  reverse_iterator;
		typedef Reverse_Iterator<iterator, const T&, const T*>  const_reverse_iterator;

		//typedef __list_reverse_iterator<T, T&, T*> reverse_iterator;
		//typedef __list_reverse_iterator<T, const T&, const T*> const_reverse_iterator;

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

		reverse_iterator rbegin()
		{
			//iterator it(_head->_next);
			//return it;
			return reverse_iterator(_head->_prev);
		}

		reverse_iterator rend()
		{
			//iterator it(_head);
			//return it;
			return reverse_iterator(_head);
		}

		const_iterator begin() const // ����*this�� ���Ա�����
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

		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_init();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// lt2(lt1)
		//list(const list<T>& lt)
		//{
		//	empty_init();

		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}

		void swap(list<T>& tmp)
		{
			empty_init(); // ������Ҫע��ͷ��ַ�Ƿ������������

			std::swap(_head, tmp._head);
		}

		list(const list<T>& lt)
		{
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase(it++); // ����Ҳ����it++���ص���it�Ŀ���
			}
		}

		void empty()
		{
			return _head->_next == _head;
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

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			return iterator(next);
		}

		// ���ﲻ��ʹ��&�����ԭ���ݽ����޸ģ����Ǳ�����Ҫ��
		list<T>& operator=(list<T> lt) // �����swap��Ҫ���ڲ���ͷָ������޸����Բ���ʹ��const����
		{
			swap(lt);
			
			return *this;
		}

	private:
		node* _head;
	};

	void print(const list<int>& l1) // ֻ��begin���������constû��Ч���������޸ĵ����������ǿ�����ĵ��������ɿ��Զ��ڲ������޸�
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
		
		const list<int> l2; // const�����ڶ����ʱ��û��const����
		const int i = 10;


		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin(); // ������Ҫ�������캯�������������û���������� ��ǳ����û������
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
			cout << it->_a1 << ":" << it->_a2 << endl; // ����Ӧ����->->���Ǳ������Ż��ˣ�Ϊ�����ӿɶ��ԣ�ʡ����һ��->
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

	void test_list4()
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
	
		lt.clear();

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list5()
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

		list<int> lt2(lt);
	
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	
		list<int> lt3;

		lt3.push_back(10);
		lt3.push_back(10);
		lt3.push_back(10);
		lt3.push_back(10);

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

		lt3 = lt;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list6()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);

		auto rit = l1.rbegin();
		while (rit != l1.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}