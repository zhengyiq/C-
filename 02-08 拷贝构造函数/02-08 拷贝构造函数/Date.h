#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

// 类里面短小函数，适合做内联的函数，直接是在类里面定义的
class Date
{
	//友元
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 2023, int month = 1, int day = 1);
	int GetMonthDay(int year, int month);
	void Print();
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int day);
	Date& operator+=(int day);	
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);

	Date& operator++(); // ++d;
	// int参数 仅仅是为了占位，跟前置重载区分
	Date operator++(int); // d++;

	Date& operator--(); // --d;
	Date operator--(int); // d--;

	//// 成员函数
	//ostream& operator<<(ostream& out);

 private:
	int _year;
	int _month;
	int _day;
};

// 全局函数
ostream& operator<<(ostream& out, const Date& d);// 减少拷贝
istream& operator>>(istream& in, Date& d);// 输出型参数使用引用