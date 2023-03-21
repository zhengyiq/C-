#pragma once

#include <iostream>
#include <array>
#include <vector>
using namespace std;

// Func.h
template<class T>
T Add(const T& left, const T& right);

template<class T>
T Add(const T& left, const T& right) // 声明和定义 放在一起不需要链接
{
	return left + right;
}

void func();