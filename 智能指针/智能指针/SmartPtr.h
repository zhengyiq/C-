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

		// 管理权转移
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

		*ap1 = 1; // 管理权转移以后导致ap1悬空，不能访问
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

		// C++11思路：语法直接支持
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;


		// 防拷贝
		// 拷贝构造和赋值是默认成员函数，我们不写会自动生成，所以我们必须写
		// C++98思路：只声明不实现，但是用的人可能会在外面强行定义，所以再加一条，声明为私有
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
	// 2. 像指针一样使用
	// 3. 拷贝
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
			if (_ptr != sp._ptr) // 管理的资源的地址是一致的
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

	// shared_ptr 本身是线程安全的，因为计数是加锁保护的
	// shared_ptr 管理的对象并不是线程安全的
	void SharePtrFunc(zyq::shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		//cout << sp.get() << endl;

		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
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
		thread t1(SharePtrFunc, ref(p), n, ref(mtx)); // ref 作用是让变量是引用传递 线程对象传递的时候直接传会发生报错，会认为是传值传参
		thread t2(SharePtrFunc, ref(p), n, ref(mtx)); // 首先传给线程的构造函数,然后再将变量传递给SharePtrFunc, 可以得到在这这里的p与上面的sp的地址是不同的

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
	// 1、他不是常规的智能指针，不支持RAII
	// 2、支持像指针一样
	// 3、专门设计出来，辅助解决shared_ptr的循环引用问题
	//    weak_ptr可以指向资源，但是他不参与管理，不增加引用计数

// 循环引用 -> 内存泄漏
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
	// 定制删除器 -- 可调用对象
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