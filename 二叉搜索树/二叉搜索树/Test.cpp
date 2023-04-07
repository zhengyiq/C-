#include <iostream>

using namespace std;

#include "BSTree.h"


void TestBSTree()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t1;
	t1.Insert(8);
	t1.Insert(3);
	t1.Insert(1);
	t1.Insert(10);
	t1.Insert(6);
	t1.Insert(4);
	t1.Insert(7);
	t1.Insert(14);
	t1.Insert(13);
	t1.InOrder();
	cout << endl;

	//t1.Erase(4);
	//t1.InOrder();
	//cout << endl;

	//t1.Erase(14);
	//t1.InOrder();
	//cout << endl;

	//t1.Erase(3);
	//t1.InOrder();
	//cout << endl;

	//t1.Erase(8);
	//t1.InOrder();
	//cout << endl;

	for (auto e : a)
	{
		t1.Erase(e);
		t1.InOrder();
		cout << endl;
	}
}

int main()
{
	TestBSTree();
	return 0;
}