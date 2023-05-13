#pragma once

#include "RBTree.h"

namespace zyq
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::reverse_iterator reverse_iterator;

		
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};

	void test_map1()
	{
		map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(3, 3));
		m.insert(make_pair(2, 2));
		
		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << " : " << it->second << endl;;
			++it;
		}
		cout << endl;

		map<int, int>::reverse_iterator rit = m.rbegin();
		while (rit != m.rend())
		{
			cout << rit->first << " : " << rit->second << endl;;
			++rit;
		}
		cout << endl;
	}

	void test_map2()
	{
		map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("count", "计数"));
		dict.insert(make_pair("string", "(字符串)")); // ʧ

		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			/*it->first = "1111";
			it->second = "111";*/

			++it;
		}
		cout << endl;

		for (auto& kv : dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	void test_map3()
	{
		string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "西瓜", "香蕉", "梨" };
		map<string, int> countMap;
		for (auto& e : arr)
		{ 
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}