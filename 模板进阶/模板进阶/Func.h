#pragma once

#include <iostream>
#include <array>
#include <vector>
using namespace std;

// Func.h
template<class T>
T Add(const T& left, const T& right);

template<class T>
T Add(const T& left, const T& right) // �����Ͷ��� ����һ����Ҫ����
{
	return left + right;
}

void func();