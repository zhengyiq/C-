//#include <iostream>
//#include <string>
//#include <unordered_set>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <vector>
//#include <time.h>
//using namespace std;
//
//void test_unordered_set1()
//{
//	unordered_set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(2);
//	s.insert(7);
//	s.insert(2);
//
//	unordered_set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_unordered_map()
//{
//	string arr[] = { "苹果", "苹果", "梨", "苹果", "梨", "梨", "苹果", "梨", "西瓜", "梨", "西瓜", "苹果" };
//	map<string, int> countMap;
//	for (auto& e : arr)
//	{
//		countMap[e]++;
//	}
//
//	for (auto& kv : countMap)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//}
////
////int main()
////{
////	test_unordered_set1();
////	test_unordered_map();
////
////	return 0;
////}
//
//int main()
//{
//	const size_t N = 1000000;
//
//	unordered_set<int> us;
//	set<int> s;
//
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		v.push_back(rand());
//		//v.push_back(rand()+i);
//		//v.push_back(i);
//	}
//
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		s.find(e);
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << endl;
//
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		us.find(e);
//	}
//	size_t end4 = clock();
//	cout << "unordered_set find:" << end4 - begin4 << endl << endl;
//
//	cout << s.size() << endl;
//	cout << us.size() << endl << endl;;
//
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//S
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
#include "HashTable.h"
int main()
{
	//OpenAddress::TestHashTable1();
	//HashBucket::TestHashTable1();
	HashBucket::TestHashTable2();
}