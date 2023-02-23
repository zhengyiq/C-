//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2, 6, 3);
//	string s4(s2, 6);
//	string s5("hello world", 3);
//	string s6(10, '*');
//
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl; // 与size用法相同
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1.empty() << endl;
//	s1.clear();
//	
//	// 观察扩容情况 -- 1.5倍扩容
//	string s;
//	//s.reserve(100); // 使用reserve可以开好100的空间
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	cout << "capacity changed: " << sz << '\n';
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//
//	
	//string s2("hello");
	//s2.push_back(' ');
	//s2.push_back('!');
	//cout << s2 << endl;

	//s2.append("world");
	//cout << s2 << endl;


	//string s3("hello");
	//s3 += " !world";
	//cout << s3 << endl;
//}


//int main()
//{
//	string s1("hello world");
//	string s2("hello world");
//	// 扩容
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// 扩容+初始化
//	s2.resize(100, '*'); // 会将size与capacity都改变，并初始化为0。
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	// 比size小可以删除数据，但是不会改变capacity，因为缩容一般不会原地缩，会有空间的开辟与释放
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//}

//void func(const string& s)
//{
//	// 只能遍历和读容器的数据，不能写
//	string::const_iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		//*it += 1;
//		++it;
//	}
//	cout << endl;
//
//	auto rit = s.rbegin(); // 可以使用auto自动推导
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto ch : s1)
//	{
//		cout << ch << endl;
//	}
//	cout << endl;
//
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin(); // 可以使用auto自动推导
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}


//int main()
//{
//	// insert/erase不推荐经常使用，能少用就少用
//	// 因为他们可能都存在需要挪动数据效率低下
//	string s1("world");
//	s1.insert(0, "hello");
//	cout << s1 << endl;
//	s1.insert(0, "hello");
//	cout << s1 << endl;
//	s1.insert(5, " ");
//	cout << s1 << endl; 
//	s1.insert(s1.begin()+5, ' ');
//	cout << s1 << endl;
//	
//	string s2("hello world");
//	//s2.erase(5, 1);
//	s2.erase(s2.begin() + 5);
//	cout << s2 << endl;
//	//s2.erase(5, 30);
//	s2.erase(5);
//	cout << s2 << endl;
//
//	return 0;
//}

//int main()
//{
//	//string s1("hello world");
//	//s1.replace(5, 1, "%%d");
//	//cout << s1 << endl;
//
//	// 查找空格并替换为%20
//	string s1("hello world i love you");
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	// 提前开空间，避免repalce时扩容
//	s1.reserve(s1.size() + 2 * num);
//
//	size_t pos = s1.find(' ');
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "%20");
//		pos = s1.find(' ', pos + 3);
//	}
//	cout << s1 << endl;
//
//	// 另一种方法
//	string s1("hello world i love you");
//	string newStr;
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	// 提前开空间，避免repalce时扩容
//	newStr.reserve(s1.size() + 2 * num);
//
//	for (auto ch : s1)
//	{
//		if (ch != ' ')
//			newStr += ch;
//		else
//			newStr += "%20";
//	}
//
//	s1 = newStr;
//	cout << newStr << endl;
//}

//int main()
//{
//	string s1("*****");
//	string s2("xxxxx");
//
//	// string类中的交换，只需要交换s1与s2的指针
//	s1.swap(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	
//	// 模板泛型，需要开辟一个临时变量
//	swap(s1, s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	//cout << s1 << endl;
//	//cout << s1.c_str() << endl;
//	//cout << (void*)s1.c_str() << endl;
//
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//	s1 += '\0';
//	s1 += '\0';
//	s1 += "xxxxx";
//	cout << s1 << endl; // 按照流插入打印
//	cout << s1.c_str() << endl; // 按照c字符打印，返回C形式的字符串
//
//	string filename("Test.cpp");
//	FILE* fout = fopen(filename.c_str(), "r");
//	if (fout == nullptr)
//		perror("fopen fail");
//
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//
//	fclose(fout);
//
//	return 0;
//}

//int main()
//{
//	string file("string.cpp.tar.zip");
//	size_t pos = file.rfind('.');
//	if (pos != string::npos)
//	{
//		//string suffix = file.substr(pos, file.size() - pos);
//		string suffix = file.substr(pos);
//		cout << suffix << endl;
//	}
//
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//	}
//
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	return 0;
//}

//int main()
//{
//	// find_first_of - find_any_of
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::size_t found = str.find_first_of("aeiou");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_of("aeiou", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	return 0;
//}

//void SplitFilename(const std::string& str)
//{
//	std::cout << "Splitting: " << str << '\n';
//	std::size_t found = str.find_last_of("/\\"); // 寻找任意
//	//std::size_t found = str.rfind("\\"); // 寻找整体
//	std::cout << " path: " << str.substr(0, found) << '\n';
//	std::cout << " file: " << str.substr(found + 1) << '\n';
//}
//
//int main()
//{
//	// find_last_of - find_last_any_of
//	std::string str1("/usr/bin/man");
//	std::string str2("c:\\windows\\winhelp.exe"); 
//
//	SplitFilename(str1);
//	SplitFilename(str2);
//
//	//string s("/\\");
//	//cout << s << endl;
//	return 0;
//}

