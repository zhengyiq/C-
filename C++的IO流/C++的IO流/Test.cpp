#include <iostream>

using namespace std;

//class A
//{
//public:
//	operator int() const
//	{
//		return _a--;
//	}
//	static int _a;
//};
//
//int A::_a = 10;

class A
{
public:
	A (int a): _a(a)
	{}

	operator int() const
	{
		return _a;
	}

private:
	int _a;
	//int _b;
};

//int main()
//{
//	//string str;
//	//// ctrl + c 信号强杀进程
//	//// ctrl + z + 换行 流对象提取到结束标志
//
//	//while (cin >> str) // 返回值是cin对象，istream的cin对象可以转bool 因为istream的这个-> explicit operator bool() const;支持自定义类型转内置类型，explicit添加后就防止隐式类型转换的发生需要强制转换
//	//{
//	//	cout << str << endl;
//	//}
//
//	A a(1);
//	int i = 10;
//	while (a)
//	{
//		if (i < 0)
//		{
//			break;
//		}
//		cout << i-- << ' ';
//	}
//	
//	// 内置类型转换成自定义类型
//	const A& aa = 1; // 隐式类型转换, 这里引用的不是1，是调用构造函数形成的临时对象
//
//	// 自定义类转换成内置类型
//	int a1;
//	a1 = aa;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool() const
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}

private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

//int main()
//{
//	ofstream ofs("test.txt", ofstream::out | ofstream::app);
//	ofs << "hello world";
//}

struct ServerInfo
{
	char _address[32]; // 二进制读写，读写对象中，不能使用string 因为二进制写对象的时候，写到文件的是string对象及里面指向空间的指针，程序结束指针指向的空间销毁，再去文件中进行读写的时候读取string读到的是一个野指针
	//string _address;

	int _port;
	Date _date;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	// 二进制读写，读写对象中，不能有string
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&info, sizeof(info));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ofstream::in | ofstream::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	// 文本读写 C++文本读写更简单
	// 文本读写本质，内存中任何类型都是转成字符串在写
	// c语言文本读写很不方便，因为要不断转字符串
	// c++封装了以后就有很大的优势
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " ";
		ofs << info._port << endl; // 如果直接进行写入就会导致写入的内容粘连在一起，需要使用空格或者换行来进行分割
		ofs << info._date << endl; // 继承了ostream的流插入的重载可以直接进行操作
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address;
		ifs >> info._port;
		ifs >> info._date;
	}

private:
	string _filename; // 配置文件
};
//
//int main()
//{
//	ServerInfo winfo = { "192.0.0.1xxxxxxxxxxxxxxxxxxxxx", 80, { 2023, 7, 11 } };
//
//	string str;
//	cin >> str;
//	if (str == "二进制写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "二进制读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "文本写")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//	else if (str == "文本读")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadText(rinfo);
//
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <sstream>

//int main()
//{
//	//ostringstream oss;
//	stringstream oss; // 放入一个string对象中
//	oss << 100 << " ";
//	oss << 11.22 << " ";
//	oss << "hello";
//
//	string str = oss.str();
//	cout << str << endl;
//
//	//istringstream iss(str);
//	stringstream iss(str);
//	int i;
//	double d;
//	string s;
//	iss >> i >> d >> s;
//	cout << i << endl;
//	cout << d << endl;
//	cout << s << endl;
//
//	return 0;
//}

// 序列化和反序列化

struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

//int main()
//{
//	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
//	stringstream oss;
//	oss << winfo._name << " ";
//	oss << winfo._id << " ";
//	oss << winfo._date << " ";
//	oss << winfo._msg;
//	string str = oss.str();
//	cout << str << endl;
//
//	stringstream iss(str);
//	ChatInfo rinfo;
//	iss >> rinfo._name;
//	iss >> rinfo._id;
//	iss >> rinfo._date;
//	iss >> rinfo._msg;
//
//	cout << "-------------------------------------------------------" << endl;
//	cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
//	cout << rinfo._date << endl;
//	cout << rinfo._name << ":>" << rinfo._msg << endl;
//	cout << "-------------------------------------------------------" << endl;
//
//	return 0;
//}

int main()
{
	stringstream oss;
	oss << "first : " << " " << " second";
	cout << oss.str();
}