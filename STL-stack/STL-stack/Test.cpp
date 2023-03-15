#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

#include "queue.h"
#include "stack.h"

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
	test_stack();
	zyq::test_queue();

	return 0;
}