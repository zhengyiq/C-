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
//	cout << s1.length() << endl; // ��size�÷���ͬ
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1.empty() << endl;
//	s1.clear();
//	
//	// �۲�������� -- 1.5������
//	string s;
//	//s.reserve(100); // ʹ��reserve���Կ���100�Ŀռ�
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
//	// ����
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// ����+��ʼ��
//	s2.resize(100, '*'); // �Ὣsize��capacity���ı䣬����ʼ��Ϊ0��
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	// ��sizeС����ɾ�����ݣ����ǲ���ı�capacity����Ϊ����һ�㲻��ԭ���������пռ�Ŀ������ͷ�
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//}

//void func(const string& s)
//{
//	// ֻ�ܱ����Ͷ����������ݣ�����д
//	string::const_iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		//*it += 1;
//		++it;
//	}
//	cout << endl;
//
//	auto rit = s.rbegin(); // ����ʹ��auto�Զ��Ƶ�
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
//	auto rit = s1.rbegin(); // ����ʹ��auto�Զ��Ƶ�
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}


//int main()
//{
//	// insert/erase���Ƽ�����ʹ�ã������þ�����
//	// ��Ϊ���ǿ��ܶ�������ҪŲ������Ч�ʵ���
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
//	// ���ҿո��滻Ϊ%20
//	string s1("hello world i love you");
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	// ��ǰ���ռ䣬����repalceʱ����
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
//	// ��һ�ַ���
//	string s1("hello world i love you");
//	string newStr;
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//			++num;
//	}
//	// ��ǰ���ռ䣬����repalceʱ����
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
//	// string���еĽ�����ֻ��Ҫ����s1��s2��ָ��
//	s1.swap(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	
//	// ģ�巺�ͣ���Ҫ����һ����ʱ����
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
//	cout << s1 << endl; // �����������ӡ
//	cout << s1.c_str() << endl; // ����c�ַ���ӡ������C��ʽ���ַ���
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
//	std::size_t found = str.find_last_of("/\\"); // Ѱ������
//	//std::size_t found = str.rfind("\\"); // Ѱ������
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

