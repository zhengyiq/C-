#include "Date.h"

int Date::GetMonthDay(int year, int month) const
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
		cout << "���ڷǷ�" << endl;
	}

}

void Date::Print() const
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d) const
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

bool Date::operator<=(const Date& d) const
{
	return *this == d || *this < d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
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

Date Date::operator+(int day) const
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

//// ʹ��+ʵ��+=
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//	return *this;
//}

// ���ֺã���Ϊ+�������ĵģ���+=û�п�����Ϊ
// ��ʱ��Ҫ��д�� d1 = d2 += d3��������Ҫ����ֵ��
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
//// ʹ��+=��ʵ��+
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
// ����-����
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

// ����-����
int Date::operator-(const Date& d) const
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
// ǰ��--
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

// d--;
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

// ++d;
// ǰ��++������+1֮��Ľ��
// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// d++;
// ����++��
// ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����һ�ݣ�Ȼ���this + 1
// ��temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}


//ostream& Date::operator<<(ostream& out)
//{
//	out << _year << "��" << _month << "��" << _day << "��" << endl;
// 
//  return out;
//}

// ȫ�ֺ���
// ����������������ű�
ostream& operator<<(ostream& out, const Date& d)// ���������Ҫ�з���ֵ
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	
	return in;
}
