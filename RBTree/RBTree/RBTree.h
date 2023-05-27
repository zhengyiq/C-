#pragma once

enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED) // �²���Ľڵ����ʱ��ɫһ����Υ�������ģ����������Ǻ�ɫ���п��ܻ�Υ�������������������ѡ��ͷ����ʽ�С�Ĺ�������ѡ����������Ľ��Ϊ��ɫ
	{}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;	

	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

	// 1��typedef __RBTreeIterator<T, T&, T*> itertaor;  ��������
	// 2�� typedef __RBTreeIterator<T, const T&, const T*> const_itertaor;
	//  ֧����ͨ����������const�������Ĺ��캯��
	
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	//__RBTreeIterator(const iterator& it)
	//	:_node(it._node)
	//{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// �Ҳ�Ϊ�գ���һ������������������ڵ�
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// ������Ϊ�գ����Ÿ��Ľ�㣬�Һ����Ǹ�������Ǹ�����
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			// ��Ϊ�գ��������������ҽڵ�
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}
		else
		{
			// ��Ϊ�գ������Ǹ����ҵ��Ǹ�����
			Node* parent = _node->_parent;
			while (parent && _node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}
};

template<class T, class Ref, class Ptr>
struct __RBReverse_TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBReverse_TreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	__RBReverse_TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator--()
	{
		if (_node->_right)
		{
			// �Ҳ�Ϊ�գ���һ������������������ڵ�
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// ������Ϊ�գ����Ÿ��Ľ�㣬�Һ����Ǹ�������Ǹ�����
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}

	Self& operator++()
	{
		if (_node->_left)
		{
			// ��Ϊ�գ��������������ҽڵ�
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}
		else
		{
			// ��Ϊ�գ������Ǹ����ҵ��Ǹ�����
			Node* parent = _node->_parent;
			while (parent && _node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}
};

		//// ������Ϊ�գ����Ÿ��Ľ�㣬�Һ����Ǹ�������Ǹ�����
		//else if (_node == _node->_parent->_right)
		//{
		//	_node = _node->_parent->_parent;
		//}
		//else/* if (_node == _node->_parent->_left)*/
		//{
		//	_node = _node->_parent;
		//}

// ͨ���º���������map��set
template<class K, class T, class KeyofT>
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;
	typedef __RBReverse_TreeIterator<T, T&, T*> reverse_iterator;

	iterator begin() 
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end() 
	{
		return iterator(nullptr); // end�����һ���ڵ����һ������
	}


	const_iterator begin() const 
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	const_iterator end() const 
	{
		return iterator(nullptr); // end�����һ���ڵ����һ������
	}

	reverse_iterator rbegin()
	{
		Node* cur = _root;
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}

		return reverse_iterator(cur);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(nullptr); // end�����һ���ڵ����һ������
	}

public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		KeyofT kot;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK; // �����ڵ�����Ϊ��ɫ
			return make_pair(iterator(_root), true);
		}

		KeyofT kot;
		Node* parent = nullptr; 
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// ��Բ�����������з��� 
		// �������Ľڵ�ĸ��ڵ��Ǻ�ɫ�ĸú�����Ͳ���������⣬������������
		// �������Ľڵ�ĸ��ڵ��Ǻ�ɫ�ľ���Ҫ���е���
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				// ���1��u������Ϊ�죬��ɫ�������������ϴ���
				if (uncle && uncle->_col == RED)
				{
						//     g
						//   p   u
						// c       
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2+3��u������/u������Ϊ�ڣ���ת+��ɫ ����������¾��޷��������·���������Ǵ����·������������������Ҫ������ת��������AVL���п��Ե�֪��ת���������������Ҫ�ֱ������д���
				{
						//     g
						//   p   u
						// c 
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // cur == parent->_right
					{
						//     g
						//   p   u
						//     c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						//parent->_col = RED;
						grandfather->_col = RED;
					}

					break;
				}
			}

			else // (grandfather->_right == parent)
			{
						//    g
						//  u   p
						//        c
				Node* uncle = grandfather->_left;
				// ���1��u������Ϊ�죬��ɫ�������������ϴ���
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2+3��u������/u������Ϊ�ڣ���ת+��ɫ
				{
						//    g
						//  u   p
						//        c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						//    g
						//  u   p
						//    c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(iterator(newnode), true);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalance()
	{
		// �����ڵ����ɫ
		if (_root && _root->_col == RED) 
		{
			cout << "���ڵ���ɫ�Ǻ�ɫ" << endl;
			return false;
		}

		// ������·����Ϊ��׼ֵ���к�ɫ�ڵ�ıȽ�
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		// ������ɫ�ڵ�
		return _Check(_root, 0, benchmark);
	}

	int Height()
	{
		return _Height(_root);
	}

private:
	void _Destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _Check(Node* root, int blackNum, int benchmark)
	{
		// ����ɫ����������DFS�ߵ���ʱ��blackNum������¼��ɫ����������benchmark���бȽ�
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "ĳ��·����ɫ�ڵ�����������" << endl;
				return false;
			}
			//cout << blackNum << endl; // ��ÿ��·����ɫ��������
			return true;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		// ��������ĺ�ɫ��㣬�Ӹ��׿�ʼ���������ַ������Ǻܺ�(�������п��ܲ����ڵ�)���Ӷ��ӿ�ʼ��鸸�׸��ӵı��
		if (root->_col == RED
			&& root->_parent
			&& root->_parent->_col == RED)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _Check(root->_left, blackNum, benchmark)
			&& _Check(root->_right, blackNum, benchmark);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}

			subR->_parent = ppnode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}

private:
	Node* _root = nullptr;
};