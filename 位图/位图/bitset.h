#pragma once

// 解题思路：排序 + 二分查找 放到哈希表中或者红黑树 不合适，内存不够
// 40亿个整数占用的空间，4 个十亿   乘上一个整数，四个字节 约等于16G
// 1 G = 1024 MB
// 1 MB = 1024 KB
// 1 KB = 1024 byte
// 1024 ^ 1024 ^ 1024 约等于10亿byte
// 
// 使用char的数组
// 哈希直接定址法 使用 01 比特位的方法进行处理 此时就需要使用512M的空间 16G / 4(char) / 8(bit)


template<size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N/8 + 1, 0); // 为了防止访问越界的问题出现
	}

	void set(size_t x)
	{
		size_t i = x / 8; // 计算x映射的位置在第i个char数组的位置
		size_t j = x % 8; // 计算x映射的位置在第i个数组的第j个位置

		_bits[i] |= (1 << j); // 注意左移右移的区别
	}

	void  reset(size_t x)
	{
		size_t i = x / 8; 
		size_t j = x % 8; 

		_bits[i] &= ~(1 << j); // 注意左移右移的区别
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		return _bits[i] & (1 << j); // 运算符的优先级的问题，位运算的优先级比较低
		// (_bits[i] >> j) & 1; // 10%8 == 2
	}
private:
	vector<char> _bits;
};

void Test_bitset1()
{
	bitset<100> bs; // 由于我们无法查看具体的比特位信息，需要寻找的是_Myfrist中的地址进行内存的查看
	bs.set(10);
	bs.set(11);
	bs.set(15);
	
	cout << bs.test(10) << endl; 
	cout << bs.test(15) << endl;

	bs.reset(10);
		
	cout << bs.test(10) << endl;
	cout << bs.test(15) << endl;
}
void Test_bitset2()
{
	//bitset<-1> bs; // 开辟的空间是根据数据的范围，开辟所有的整数可以通过-1的形式
	bitset<0xffffffff> bs;
}
// 位图应用
// 1. 使用一个位图的形式，不过开辟的空间变换为四个，每两个作为一个组合进行标记 00 01 10 11；给定两个位图进行处理同样的进行标记 00 01 10 11
// 2. 将其中的一个文件读进位图之中，在读取另外的一个文件，在就是存在交集 出现的问题：存在重复的值需要进行去重操作，方法1：将已经找到的交集的比特位归零防止二次统计；方法2：将两个文件分别读取进入两个位图进行比较
// 3.
//优点：速度快节省空间
//缺点: 只能映射整形, 其他的类型如浮点数不能存储



template<size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		// 00 -> 01
		if (_bs1.test(x) == false
			&& _bs2.test(x) == false)
		{
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false
			&& _bs2.test(x) == true)
		{
			// 01 -> 10
			_bs1.set(x);
			_bs2.reset(x);
		}
		// 10
	}

	void Print()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (_bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}
private:
	bitset<N> _bs1;
	bitset<N> _bs2;
};

void test_twobitset()
{
	int a[] = { 3, 45, 53, 32, 32, 43, 3, 2, 5, 2, 32, 55, 5, 53,43,9,8,7,8 };
	twobitset<100> bs;
	for (auto e : a)
	{
		bs.set(e);
	}

	bs.Print();
}