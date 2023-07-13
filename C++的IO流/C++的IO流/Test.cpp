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
//	//// ctrl + c �ź�ǿɱ����
//	//// ctrl + z + ���� ��������ȡ��������־
//
//	//while (cin >> str) // ����ֵ��cin����istream��cin�������תbool ��Ϊistream�����-> explicit operator bool() const;֧���Զ�������ת�������ͣ�explicit��Ӻ�ͷ�ֹ��ʽ����ת���ķ�����Ҫǿ��ת��
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
//	// ��������ת�����Զ�������
//	const A& aa = 1; // ��ʽ����ת��, �������õĲ���1���ǵ��ù��캯���γɵ���ʱ����
//
//	// �Զ�����ת������������
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
		// ����������д�ģ���������_yearΪ0�������
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
	char _address[32]; // �����ƶ�д����д�����У�����ʹ��string ��Ϊ������д�����ʱ��д���ļ�����string��������ָ��ռ��ָ�룬�������ָ��ָ��Ŀռ����٣���ȥ�ļ��н��ж�д��ʱ���ȡstring��������һ��Ұָ��
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

	// �����ƶ�д����д�����У�������string
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

	// �ı���д C++�ı���д����
	// �ı���д���ʣ��ڴ����κ����Ͷ���ת���ַ�����д
	// c�����ı���д�ܲ����㣬��ΪҪ����ת�ַ���
	// c++��װ���Ժ���кܴ������
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " ";
		ofs << info._port << endl; // ���ֱ�ӽ���д��ͻᵼ��д�������ճ����һ����Ҫʹ�ÿո���߻��������зָ�
		ofs << info._date << endl; // �̳���ostream������������ؿ���ֱ�ӽ��в���
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address;
		ifs >> info._port;
		ifs >> info._date;
	}

private:
	string _filename; // �����ļ�
};
//
//int main()
//{
//	ServerInfo winfo = { "192.0.0.1xxxxxxxxxxxxxxxxxxxxx", 80, { 2023, 7, 11 } };
//
//	string str;
//	cin >> str;
//	if (str == "������д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);
//	}
//	else if (str == "�����ƶ�")
//	{
//		ServerInfo rinfo;
//		ConfigManager cm("test.txt");
//		cm.ReadBin(rinfo);
//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;
//	}
//	else if (str == "�ı�д")
//	{
//		ConfigManager cm("test.txt");
//		cm.WriteText(winfo);
//	}
//	else if (str == "�ı���")
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
//	stringstream oss; // ����һ��string������
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

// ���л��ͷ����л�

struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
};

//int main()
//{
//	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
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
//	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
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