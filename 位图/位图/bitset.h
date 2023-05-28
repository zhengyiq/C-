#pragma once

// ����˼·������ + ���ֲ��� �ŵ���ϣ���л��ߺ���� �����ʣ��ڴ治��
// 40�ڸ�����ռ�õĿռ䣬4 ��ʮ��   ����һ���������ĸ��ֽ� Լ����16G
// 1 G = 1024 MB
// 1 MB = 1024 KB
// 1 KB = 1024 byte
// 1024 ^ 1024 ^ 1024 Լ����10��byte
// 
// ʹ��char������
// ��ϣֱ�Ӷ�ַ�� ʹ�� 01 ����λ�ķ������д��� ��ʱ����Ҫʹ��512M�Ŀռ� 16G / 4(char) / 8(bit)


template<size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N/8 + 1, 0); // Ϊ�˷�ֹ����Խ����������
	}

	void set(size_t x)
	{
		size_t i = x / 8; // ����xӳ���λ���ڵ�i��char�����λ��
		size_t j = x % 8; // ����xӳ���λ���ڵ�i������ĵ�j��λ��

		_bits[i] |= (1 << j); // ע���������Ƶ�����
	}

	void  reset(size_t x)
	{
		size_t i = x / 8; 
		size_t j = x % 8; 

		_bits[i] &= ~(1 << j); // ע���������Ƶ�����
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		return _bits[i] & (1 << j); // ����������ȼ������⣬λ��������ȼ��Ƚϵ�
		// (_bits[i] >> j) & 1; // 10%8 == 2
	}
private:
	vector<char> _bits;
};

void Test_bitset1()
{
	bitset<100> bs; // ���������޷��鿴����ı���λ��Ϣ����ҪѰ�ҵ���_Myfrist�еĵ�ַ�����ڴ�Ĳ鿴
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
	//bitset<-1> bs; // ���ٵĿռ��Ǹ������ݵķ�Χ���������е���������ͨ��-1����ʽ
	bitset<0xffffffff> bs;
}
// λͼӦ��
// 1. ʹ��һ��λͼ����ʽ���������ٵĿռ�任Ϊ�ĸ���ÿ������Ϊһ����Ͻ��б�� 00 01 10 11����������λͼ���д���ͬ���Ľ��б�� 00 01 10 11
// 2. �����е�һ���ļ�����λͼ֮�У��ڶ�ȡ�����һ���ļ����ھ��Ǵ��ڽ��� ���ֵ����⣺�����ظ���ֵ��Ҫ����ȥ�ز���������1�����Ѿ��ҵ��Ľ����ı���λ�����ֹ����ͳ�ƣ�����2���������ļ��ֱ��ȡ��������λͼ���бȽ�
// 3.
//�ŵ㣺�ٶȿ��ʡ�ռ�
//ȱ��: ֻ��ӳ������, �����������縡�������ܴ洢



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

// ��¡������ - ���ͳ�ͻ�ĸ��� - һ��ֵӳ��һ��λ���������У�ӳ����λ�þͿ��Խ���������
// ����Ϊ10���ַ�����256*10�Ŀ����� char�ķ�Χ��-128-127

// �� �ǲ�׼ȷ�ģ���������
// ���� ��׼ȷ�ģ����ھ���һ�����ڣ�һ������ӳ���λ�ö�����˳�ͻ��(����Ҳ�ڸ�λ�ý���ӳ��)����������
// ��¡��������ʹ�ó���
// 1. �ܹ����̴������еĳ��� ע��ʱ�����ж��ǳ��Ƿ�ʹ�ù� �����ʲ��߾Ϳ��Խ���
// �绰������Ҫ��ȷ������Ҳ����ʹ�ò�¡������ - ���ǲ����ھͿ���ֱ�ӷ��أ�������ʾ���ھͿ��������ݿ��н����ٴεıȶ�
// �ŵ㣺�졢��ʡ�ڴ�
// ȱ�㣺��������


// ���������ɾ��������������ֵ�������� - ���ü������жϵ�ǰ��λ���ܷ�ɾ���������ǹ��ڿ�����λ�����⣬��������λ�Ϳ�������ʾ������ 
// �������ݹ���

// �������ļ����ֱ���100�ڸ�query������ֻ��1G�ڴ棬����ҵ������ļ��������ֱ������ȷ�㷨�ͽ����㷨 query����һ���ַ��� - ���赥����ѯƽ��50�ֽڣ�100�ڸ�query��5000���ֽ� - ռ��500G
// �����ļ��Ĳ��Ȼ����д��������з�Ϊ1000��С�ļ� ���ǲ��ܹ�ƽ���з�ƽ���зֵ����������Ҫ���������ļ���ÿһ��С�ļ����бȽϣ������Ҫ���й�ϣ�з� - 
// ��ϣ�з� - i = HashFunc(query) % 1000 ÿ��query�����Ӧ��i�Ƕ��پͽ����i��С�ļ����д��� ���������ļ�����ͬ��query�ַ����ͻ������ͬ��С�ļ�
// ����ĳЩС�ļ���Ϊ����ƽ���зֻᵼ���ļ�����
// 1. �����ļ�����ĳ�������ظ���query
// 2. �����ļ����д�����ͬ��query
// ���������ʹ��unordered_map / set ���ζ�ȡ�ļ�query������set��
// 1. �����ȡ������С�ļ�query�����Գɹ�����set��ô��˵�����1
// 2. �����ȡ������С�ļ�query ����������쳣(���ڴ�)���������2�����������Ĺ�ϣ�������ٴηָ���󽻼���
// ˵����set����key����Ѿ����˷���false�����û���ڴ�ͻ��׳�bad_alloc���쳣


// �����չBloomFilterʹ����֧��ɾ��Ԫ�صĲ���
// ʹ�ü�������λȥӳ�������

// ��ͬ��IPһ��������ͬһ��С�ļ�
// ��һ������100G��С��log file, log�д���IP��ַ, ����㷨�ҵ����ִ�������IP��ַ��������������ͬ������ҵ�top K��IP�����ֱ����Linuxϵͳ����ʵ�֣�
// ��ϣ�и� - �зֳ�500��С�ļ������ζ�ȡ���ݣ�i= HashFunc(ip) % 500�����ip���ǵ�i��С�ļ������δ���ÿ��С�ļ�ʹ��map/unordered_mapͳ�Ƴ��ֵĴ�����1. ���ͳ�ƹ����г������ڴ��쳣��˵������С�ļ����󣬳�ͻ̫�࣬��Ҫ����ѡ���ϣ�������ٴι�ϣ�з����С�ļ���2. ���û�����쳣��������ͳ�ơ�ͳ����һ��С�ļ���¼���ֵ�����ν���ͳ��ÿһ��С�ļ��������һ��С����⡣

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

// N�����������ݸ���
//��ϣ�����ĸ���������һ��ֵӳ�伸��λ����ϣ����Խ�࣬������Խ�ͣ����ǹ�ϣ����Խ�ࡣƽ���Ŀռ�Խ��
template<size_t N, class K = string,
class Hash1 = BKDRHash,
class Hash2 = APHash,
class Hash3 = DJBRHash>

class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t len = _X * N; // ��¡�������ĳ���
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
	static const size_t _X = 4; // ��¡�������ĳ����������ݸ����ı�ֵ
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

	// v2��v1�������ַ����������ǲ�һ��
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
	cout << "�����ַ���������:" << (double)n2 / (double)N << endl;

	// �������ַ�����
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
	cout << "�������ַ���������:" << (double)n3 / (double)N << endl;
}