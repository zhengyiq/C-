#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// �������С�������ʺ��������ĺ�����ֱ�����������涨���
class Date
{
	// ��Ԫ
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year, int month, int day)
	{
		cout << "Date(int year, int month, int day)" << endl;

		if (month > 0 && month < 13
			&& (day > 0 && day <= GetMonthDay(year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "���ڷǷ�" << endl;
		}
	}

	Date(const Date& d)
	{
		cout << "Date(const Date& d)" << endl;
		//...
	}

	Date& operator=(const Date& d)
	{
		cout << "Date& operator=(const Date& d)" << endl;
		//...

		return *this;
	}

	Date(Date&& d)
	{
		cout << "Date(Date&& d)" << endl;
		//...
	}

	Date& operator=(Date&& d)
	{
		cout << "Date& operator=(Date&& d)" << endl;
		//...

		return *this;
	}

	void Print() const;
	int GetMonthDay(int year, int month) const;

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;


	Date& operator-=(int day);
	Date operator-(int day) const;

	// d1 - d2;
	int operator-(const Date& d) const;

	// ++d1
	Date& operator++();

	// d1++
	// int���� ������Ϊ��ռλ����ǰ����������
	Date operator++(int);

	// --d1 -> d1.operator--()
	Date& operator--();

	// d1-- -> d1.operator--(1)
	Date operator--(int);

	//void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}