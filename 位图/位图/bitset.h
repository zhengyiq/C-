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