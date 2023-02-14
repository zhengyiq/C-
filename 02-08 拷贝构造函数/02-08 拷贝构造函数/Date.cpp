#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Date::Date(int year, int month, int day)
{
	if ((month > 0 && month < 13)
		&& (day > 0 && day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}

}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d)
{
	return *this == d || *this < d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;

	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			++tmp._year;
		}
	}
	return tmp;
}

//// 使用+实现+=
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//	return *this;
//}

// 这种好，因为+是有消耗的，而+=没有拷贝行为
// 有时需要编写的 d1 = d2 += d3，所以需要返回值。
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}

//// 使用+=来实现+
//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//	tmp += day;
//	return tmp;
//}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

int Date::operator-(const Date& d) 
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}


// --d;
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

// d--;
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

// ++d;
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// d++;
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

//void Date::operator<<(ostream& out)
//{
//	out << _year << "年" << _month << "月" << _day << "日" << endl;
// 
//  return out;
//}

// 全局函数
ostream& operator<<(ostream& out, const Date& d)// 连续输出需要有返回值
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	
	return in;
}