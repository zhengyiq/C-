#include "string.h"

int main()
{
	try
	{
		zyq::test_string11();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}