#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
#include "vector.h"

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};

int main()
{
	zyq::Testvector10();

	//A(); // ��������ֻ����һ�У���Ϊ����֮��û���˻�����
	//A a1;
	//const A& a = A(); // const���û��ӳ�����������������ڣ������ö��������
	////A& a = A(); // ��ʱ��������������г���
	//A a2;

}