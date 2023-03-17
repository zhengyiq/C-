#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <assert.h>

using namespace std;
#include "Iterator.h"
#include "queue.h"
#include "stack.h"
#include "priority_queue.h"
#include "List.h"
#include "vector.h"

void test_stack()
{
	zyq::stack<int> st;

	st.top();

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	//test_stack();
	//zyq::test_queue();
	//zyq::test_priority_queue1();
	//zyq::TestPriorityQueue();
	//zyq::test_list6();
	zyq::Testvector11();
	return 0;
}