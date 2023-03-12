#include "string.h"

//int main()
//{
//	try
//	{
//		zyq::test_string12();
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


int main()
{
	/*try
	{
		bit::test_string10();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}*/

	zyq::string s1;
	std::string s2;
	cout << sizeof(s1) << endl; //12
	cout << sizeof(s2) << endl; // 28 


	zyq::string s3("11111");  // 12 
	std::string s4("1111111"); // 28
	std::string s5("111111111111111111111111111111111"); // 28

	cout << sizeof(s3) << endl;
	cout << sizeof(s4) << endl;
	cout << sizeof(s5) << endl;


	return 0;
}