#include <iostream>
#include <string>
using namespace std;

#include "BSTree.h"


void TestBSTree()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;
	t1.InsertR(8);
	t1.InsertR(3);
	t1.InsertR(1);
	t1.InsertR(10);
	t1.InsertR(6);
	t1.InsertR(4);
	t1.InsertR(7);
	t1.InsertR(14);
	t1.InsertR(13);
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
		t1.EraseR(e);
		t1.InOrder();
		cout << endl;
	}
}

void TestBSTree4()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("left", "���");
	dict.Insert("right", "�ұ�");
	dict.Insert("string", "�ַ���");
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "�޴˵���" << endl;
		}
	}
}

void TestBSTree5()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };

	key_value::BSTree<string, int> countTree;
	for (auto str : arr)
	{
		//key_value::BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}

int main()
{
	TestBSTree();
	//TestBSTree4();
	//TestBSTree5();
	return 0;
}