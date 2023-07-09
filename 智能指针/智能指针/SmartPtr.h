#pragma once
namespace zyq
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// ����Ȩת��
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto()
	{
		auto_ptr<int> ap1(new int(1));
		auto_ptr<int> ap2(ap1);

		*ap1 = 1; // ����Ȩת���Ժ���ap1���գ����ܷ���
		*ap2 = 1;

	}

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// C++11˼·���﷨ֱ��֧��
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;


		// ������
		// ��������͸�ֵ��Ĭ�ϳ�Ա���������ǲ�д���Զ����ɣ��������Ǳ���д
		// C++98˼·��ֻ������ʵ�֣������õ��˿��ܻ�������ǿ�ж��壬�����ټ�һ��������Ϊ˽��
	private:
		// unique_ptr(const unique_ptr<T>& up);
		// unique_ptr<T>& operator=(const unique_ptr<T>& up);
	private:
		T* _ptr;
	};

	void test_unique()
	{
		unique_ptr<int> up1(new int(1));
		//unique_ptr<int> up2(up1);
	}


	// 1. RAII
	// 2. ��ָ��һ��ʹ��
	// 3. ����
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		template<class D>
		shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
			, _del(del)
		{}

		~shared_ptr()
		{
			Release();
		}

		void Release()
		{
			_pmtx->lock();

			bool deleteFlag = false;

			if (--(*_pcount) == 0)
			{
				if (_ptr)
				{
					//cout << "delete:" << _ptr << endl;
					//delete _ptr;

					_del(_ptr);
				}
				delete _pcount;
				deleteFlag = true;
			}

			_pmtx->unlock();

			if (deleteFlag == true)
			{
				delete _pmtx;
			}
		}

		void AddCount()
		{
			_pmtx->lock();

			++(*_pcount);

			_pmtx->unlock();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			AddCount();
		}

		// sp1 = sp4
		// sp1 = sp1;
		// sp1 = sp2;
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr) // �������Դ�ĵ�ַ��һ�µ�
			{
				Release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddCount();
			}

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}


	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
		function<void(T*)> _del = [](T* ptr) {
			cout << "lambda delete:" << ptr << endl;
			delete ptr;
		};
	};

	void test_shared()
	{
		shared_ptr<int> sp1(new int(1));
		shared_ptr<int> sp2(sp1);
		shared_ptr<int> sp3(sp2);

		shared_ptr<int> sp4(new int(10));

		//sp1 = sp4;
		sp4 = sp1;

		sp1 = sp1;
		sp1 = sp2;
	}

	struct Date
	{
		int _year = 0;
		int _month = 0;
		int _day = 0;

		~Date()
		{}
	};

	// shared_ptr �������̰߳�ȫ�ģ���Ϊ�����Ǽ���������
	// shared_ptr ����Ķ��󲢲����̰߳�ȫ��
	void SharePtrFunc(zyq::shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		//cout << sp.get() << endl;

		for (size_t i = 0; i < n; ++i)
		{
			// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
			zyq::shared_ptr<Date> copy(sp);

			mtx.lock();
			sp->_day++;
			sp->_month++;
			sp->_year++;
			mtx.unlock();
		}
	}

	void test_shared_safe()
	{
		zyq::shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		const size_t n = 100000;
		mutex mtx;
		thread t1(SharePtrFunc, ref(p), n, ref(mtx)); // ref �������ñ��������ô��� �̶߳��󴫵ݵ�ʱ��ֱ�Ӵ��ᷢ����������Ϊ�Ǵ�ֵ����
		thread t2(SharePtrFunc, ref(p), n, ref(mtx)); // ���ȴ����̵߳Ĺ��캯��,Ȼ���ٽ��������ݸ�SharePtrFunc, ���Եõ����������p�������sp�ĵ�ַ�ǲ�ͬ��

		//cout << &p << endl;

		t1.join();
		t2.join();

		cout << p->_day << endl;
		cout << p->_month << endl;
		cout << p->_year << endl;

		cout << p.use_count() << endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	// weak_ptr
	// 1�������ǳ��������ָ�룬��֧��RAII
	// 2��֧����ָ��һ��
	// 3��ר����Ƴ������������shared_ptr��ѭ����������
	//    weak_ptr����ָ����Դ��������������������������ü���

// ѭ������ -> �ڴ�й©
	struct ListNode
	{

		//ListNode* _next;
		//ListNode* _prev;

		zyq::shared_ptr<ListNode> _next;
		zyq::shared_ptr<ListNode> _prev;

		//zyq::weak_ptr<ListNode> _next;
		//zyq::weak_ptr<ListNode> _prev;
		int _val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};




	void test_shared_cycle()
	{
		/*ListNode* n1 = new ListNode;
		ListNode* n2 = new ListNode;

		n1->_next = n2;
		n2->_prev = n1;

		delete n1;
		delete n2;*/

		zyq::shared_ptr<ListNode> n1(new ListNode);
		zyq::shared_ptr<ListNode> n2(new ListNode);

		//cout << n1.use_count() << endl;
		//cout << n2.use_count() << endl;

		n1->_next = n2;
		//n2->_prev = n1;

		//cout << n1.use_count() << endl;
		//cout << n2.use_count() << endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// ����ɾ���� -- �ɵ��ö���
	template<class T>
	struct DeleteArray
	{
		void operator()(T* ptr)
		{
			cout << "void operator()(T* ptr)" << endl;
			delete[] ptr;
		}
	};

	//void test_shared_deletor()
	//{
	//	std::shared_ptr<Date> spa1(new Date[10], DeleteArray<Date>());
	//	std::shared_ptr<Date> spa2(new Date[10], [](Date* ptr) {
	//		cout << "lambda delete[]" << ptr << endl;
	//		delete[] ptr;
	//		});

	//	std::shared_ptr<FILE> spF3(fopen("Test.cpp", "r"), [](FILE* ptr) {
	//		cout << "lambda fclose" << ptr << endl;
	//		fclose(ptr);
	//		});
	//}

	void test_shared_deletor()
	{
		zyq::shared_ptr<Date> sp0(new Date);

		zyq::shared_ptr<Date> spa1(new Date[10], DeleteArray<Date>());
		zyq::shared_ptr<Date> spa2(new Date[10], [](Date* ptr) {
			cout << "lambda delete[]:" << ptr << endl;
			delete[] ptr;
			});

		zyq::shared_ptr<FILE> spF3(fopen("Test.cpp", "r"), [](FILE* ptr) {
			cout << "lambda fclose:" << ptr << endl;
			fclose(ptr);
			});
	}
} 