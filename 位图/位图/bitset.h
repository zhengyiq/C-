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

// 布隆过滤器 - 降低冲突的概率 - 一个值映射一个位置容易误判，映射多个位置就可以降低误判率
// 长度为10的字符串有256*10的可能性 char的范围是-128-127

// 在 是不准确的，存在误判
// 不在 是准确的，不在就是一定不在，一个数据映射的位置都与别人冲突了(别人也在该位置进行映射)，存在误判
// 布隆过滤器的使用场景
// 1. 能够容忍存在误判的场景 注册时快速判断昵称是否使用过 误判率不高就可以接受
// 电话号码需要精确，但是也可以使用布隆过滤器 - 若是不存在就可以直接返回，若是显示存在就可以在数据库中进行再次的比对
// 优点：快、节省内存
// 缺点：存在误判


// 不能随意的删除，会造成其余的值出现问题 - 引用计数来判断当前的位置能否被删除。这里是关于开几个位的问题，若是两个位就可以最多表示三个数 
// 用于数据过滤

// 给两个文件，分别有100亿个query，我们只有1G内存，如何找到两个文件交集？分别给出精确算法和近似算法 query就是一个字符串 - 假设单个查询平均50字节，100亿个query是5000亿字节 - 占用500G
// 进行文件的拆分然后进行处理，假设切分为1000个小文件 但是不能够平均切分平均切分的问题就是需要将两个大文件的每一个小文件进行比较，因此需要进行哈希切分 - 
// 哈希切分 - i = HashFunc(query) % 1000 每个query算出对应的i是多少就进入第i个小文件进行处理 这样两个文件中相同的query字符串就会进入相同的小文件
// 问题某些小文件因为不是平均切分会导致文件过大
// 1. 单个文件中有某个大量重复的query
// 2. 单个文件中有大量不同的query
// 解决方案：使用unordered_map / set 依次读取文件query，插入set中
// 1. 如果读取中整个小文件query都可以成功插入set那么就说明情况1
// 2. 如果读取中整个小文件query 插入过程中异常(无内存)，则是情况2，换用其他的哈希函数，再次分割，再求交集。
// 说明：set插入key如果已经有了返回false；如果没有内存就会抛出bad_alloc的异常


// 如何扩展BloomFilter使得它支持删除元素的操作
// 使用几个比特位去映射的问题

// 相同的IP一定进入了同一个小文件
// 给一个超过100G大小的log file, log中存着IP地址, 设计算法找到出现次数最多的IP地址？与上题条件相同，如何找到top K的IP？如何直接用Linux系统命令实现？
// 哈希切割 - 切分成500个小文件，依次读取数据，i= HashFunc(ip) % 500，这个ip就是第i个小文件；依次处理每个小文件使用map/unordered_map统计出现的次数；1. 如果统计过程中出现抛内存异常，说明单个小文件过大，冲突太多，需要重新选择哈希函数，再次哈希切分这个小文件；2. 如果没有抛异常，则正常统计。统计完一个小文件记录最大值。依次进行统计每一个小文件。最后建立一个小堆求解。

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); ++i)
		{
			size_t ch = s[i];
			if ((i & 1) == 0)
			{
				hash^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= ~(((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

// N最多会插入的数据个数
//哈希函数的个数，代表一个值映射几个位，哈希函数越多，误判率越低；但是哈希函数越多。平均的空间越多
template<size_t N, class K = string,
class Hash1 = BKDRHash,
class Hash2 = APHash,
class Hash3 = DJBRHash>

class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t len = _X * N; // 布隆过滤器的长度
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);

		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);

		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);

		//cout << hash1 << " " << hash2 << " " << hash3 << " " << endl << endl;
	}

	bool test(const K& key)
	{
		size_t len = _X * N;
		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
		{
			return false;
		}
	}

private:
	static const size_t _X = 4; // 布隆过滤器的长度与存放数据个数的比值
	bitset<N*_X> _bs;
};

void test_bloomfilter1()
{
	BloomFilter<100> bs;
	bs.set("sort");
	bs.set("bloom");
	bs.set("hello world hello bit");
	bs.set("test");
	bs.set("etst");
	bs.set("estt");

	cout << bs.test("sort") << endl;
	cout << bs.test("bloom") << endl;
	cout << bs.test("hello world hello bit") << endl;
	cout << bs.test("etst") << endl;
	cout << bs.test("test") << endl;
	cout << bs.test("estt") << endl;

	cout << bs.test("ssort") << endl;
	cout << bs.test("tors") << endl;
	cout << bs.test("ttes") << endl;
}

void test_bloomfilter2()
{
	srand(time(0));
	const size_t N = 10000;
	BloomFilter<N> bf;

	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		//string url = "https://www.cctalk.com/m/statistics/live/16845432622875";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}