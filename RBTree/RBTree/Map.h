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
		bool insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
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
	}
}