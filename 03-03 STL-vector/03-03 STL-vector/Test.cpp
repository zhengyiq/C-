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

	//A(); // 生命周期只在这一行，因为这行之后没有人会用它
	//A a1;
	//const A& a = A(); // const引用会延长匿名对象的生命周期，到引用对象域结束
	////A& a = A(); // 临时对象，匿名对象具有常性
	//A a2;

}