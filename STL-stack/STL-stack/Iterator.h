#pragma once

template<class Iterator, class Ref, class Ptr>
class Reverse_Iterator
{
public:

	typedef Reverse_Iterator<Iterator, Ref, Ptr> Self;

	Reverse_Iterator(Iterator it)
		:_cur(it)
	{}

	Ref operator*() // Ϊ�˶Գ���Ҫ����ǰһ����λ��
	{
		Iterator tmp = _cur;
		--tmp;
		return *tmp;
	}

	Self& operator++()
	{
		--_cur;
		return *this;
	}

	Self operator++(int)
	{
		Iterator tmp(*this);;
		--_cur;
		return tmp;
	}

	Self& operator--()
	{
		++_cur;
		return *this;
	}

	Self operator--(int)
	{
		Iterator tmp(*this);;
		++_cur;
		return tmp;
	}

	bool operator!=(const Self& s)
	{
		return _cur != s._cur;
	}

private:
	Iterator _cur;
};