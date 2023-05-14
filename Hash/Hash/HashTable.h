#pragma once

namespace OpenAddress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// 负载因此超过0.7就进行扩容
			// 这里还需注意要把size == 0考虑进判断中
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) // 负载因子/载荷因子 反应表存储数据量的百分比 // 整数进行相处是没有小数的，需要转换成double或者将被除数*10
			{
				//_tables.reserve(_tables.capacity()) 未处理表为空的情况 光扩容量无法访问

				//size_t newsize = _tables.size() == 0 ? 10 : tables.size() * 2;
				//_tables.resize(newsize);

				// 代码重复的写法
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//vector<HashData<K, V>> newtable;
				//newtable.resize(newsize);
				//// 遍历旧表，重新映射到新表
				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	if (_tables[i]._state == EXIST)
				//	{

				//		size_t hashi = _tables[i]._kv.first % newtable.size();

				//		size_t j = 0;
				//		size_t index = hashi;
				//		while (newtable[index]._state == EXIST)
				//		{
				//			index = hashi + j;
				//			index %= newtable.size();
				//			++j;
				//		}
				//		newtable[index]._kv = _tables[i]._kv;
				//		newtable[index]._state = EXIST;
				//	}
				//}
				//_tables.swap(newtable);

				// 构建新的HashTable来接收旧表
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}
				_tables.swap(newht._tables);
			}
			size_t hashi = kv.first % _tables.size();

			// 线性探测
			size_t i = 0;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				index = hashi + i;
				//index = hashi + i*i; // 二次探测
				index %= _tables.size(); // 防止一直加出现越界的问题出现
				++i;
			}
			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			++_n;
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key % _tables.size();

			// 线性探测
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state != DELETE
					&& key == _tables[index]._kv.first)
				{
					return &_tables[index];
				}

				index = hashi + i;
				index %= _tables.size();
				++i;

				// 已经查找了一圈说明全是存在与删除
				if (hashi == index)
				{
					break;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n; // 存储的数据个数
		//HashData* _tables; 
		//size_t size;
		//size_t capacity;
	};

	void TestHashTable1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(15, 15));

		if (ht.Find(13))
		{
			cout << "13在" << endl;
		}
		else
		{
			cout << "13不在" << endl;
		}

		ht.Erase(13);

		if (ht.Find(13))
		{
			cout << "13在" << endl;
		}
		else
		{
			cout << "13不在" << endl;
		}
	}

}

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V> kv)
			:_next(nullptr)
			,_kv(kv)
		{}
 	};

	template<class K, class V>
	class HashTable 
	{
		typedef HashNode<K, V> Node;

	public:
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				cur = nullptr;
			}
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t hashi = key % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 扩容
			// 负载因子==1时扩容平均每个桶下面挂一个
			if (_n == _tables.size())
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size()*2;
				//HashTable<K, V> newht;
				//newht.resize(newsize);
				//for (auto cur : _tables)
				//{
				//	while (cur)
				//	{
				//		newht.Insert(cur->_kv);
				//		cur = cur->_next;
				//	}
				//}

				//_tables.swap(newht._tables);

				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtable(newsize, nullptr);

				//for (Node*& cur : _tables)
				
				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	Node* cur = _tables[i];
				for (auto& cur : _tables) 
				{
					while (cur)
					{
						Node* next = cur->_next; // 记录下一个结点
						size_t hashi = cur->_kv.first % newtable.size();

						// 插入
						cur->_next = newtable[hashi]; // 桶的第一个节点是存储在桶中的
						newtable[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newtable);
			}


			size_t hashi = kv.first % _tables.size();
			
			// 插入
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0; // 存储的有效数据个数
	};

	void TestHashTable1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 25));
		ht.Insert(make_pair(35, 35));
		ht.Insert(make_pair(45, 45));
	}

	void TestHashTable2()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(12);
		ht.Erase(3);
		ht.Erase(33);
	}
} 
