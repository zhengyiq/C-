#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

// �������С�������ʺ��������ĺ�����ֱ�����������涨���
class Date
{
	//��Ԫ
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 2023, int month = 1, int day = 1);
	int GetMonthDay(int year, int month) const;
	void Print() const;
	bool operator==(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;
	Date& operator=(const Date& d);
	Date operator+(int day) const;
	Date& operator+=(int day);	
	Date operator-(int day) const;
	Date& operator-=(int day);
	int operator-(const Date& d) const;

	Date& operator++(); // ++d;
	// int���� ������Ϊ��ռλ����ǰ����������
	Date operator++(int); // d++;

	Date& operator--(); // --d;
	Date operator--(int); // d--;

	// ��Ա����
	//ostream& operator<<(ostream& out);

	Date* operator&()
	{
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}

 private:
	int _year;
	int _month;
	int _day;
};

// ȫ�ֺ���
ostream& operator<<(ostream& out, const Date& d);// ���ٿ���
istream& operator>>(istream& in, Date& d);// ����Ͳ���ʹ������