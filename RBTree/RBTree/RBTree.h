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
		, _col(RED) // 新插入的节点如果时黑色一定会违反规则四，如果插入的是红色，有可能会违反规则三，因此在这里选择惩罚概率较小的规则三，选择新增插入的结点为红色
	{}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;	

	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

	// 1、typedef __RBTreeIterator<T, T&, T*> itertaor;  拷贝构造
	// 2、 typedef __RBTreeIterator<T, const T&, const T*> const_itertaor;
	//  支持普通迭代器构造const迭代器的构造函数
	
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
			// 右不为空，下一个就是右子树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// 右子树为空，沿着根的结点，找孩子是父亲左的那个祖先
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
			// 左不为空，找左子树的最右节点
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}
		else
		{
			// 左为空，孩子是父亲右的那个祖先
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
			// 右不为空，下一个就是右子树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			// 右子树为空，沿着根的结点，找孩子是父亲左的那个祖先
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
			// 左不为空，找左子树的最右节点
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}
		else
		{
			// 左为空，孩子是父亲右的那个祖先
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

		//// 右子树为空，沿着根的结点，找孩子是父亲左的那个祖先
		//else if (_node == _node->_parent->_right)
		//{
		//	_node = _node->_parent->_parent;
		//}
		//else/* if (_node == _node->_parent->_left)*/
		//{
		//	_node = _node->_parent;
		//}

// 通过仿函数来区分map与set
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
		return iterator(nullptr); // end是最后一个节点的下一个数据
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
		return iterator(nullptr); // end是最后一个节点的下一个数据
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
		return reverse_iterator(nullptr); // end是最后一个节点的下一个数据
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
			_root->_col = BLACK; // 将根节点设置为黑色
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

		// 针对插入后的情况进行分析 
		// 如果插入的节点的父节点是黑色的该红黑树就不会产生问题，可以正常插入
		// 如果插入的节点的父节点是红色的就需要进行调整
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				// 情况1：u存在且为红，变色处理，并继续往上处理
				if (uncle && uncle->_col == RED)
				{
						//     g
						//   p   u
						// c       
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2+3：u不存在/u存在且为黑，旋转+变色 在这种情况下就无法满足最短路径的两倍是大于最长路径的这个条件，因此需要进行旋转操作，从AVL树中可以得知旋转是有四种情况，需要分别对其进行处理
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
				// 情况1：u存在且为红，变色处理，并继续往上处理
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2+3：u不存在/u存在且为黑，旋转+变色
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
		// 检查根节点的颜色
		if (_root && _root->_col == RED) 
		{
			cout << "根节点颜色是红色" << endl;
			return false;
		}

		// 将最左路径作为基准值进行黑色节点的比较
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		// 连续红色节点
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
		// 检查黑色结点的数量，DFS走到空时将blackNum用来记录黑色结点的数量与benchmark进行比较
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}
			//cout << blackNum << endl; // 求每条路径黑色结点的数量
			return true;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		// 检查连续的红色结点，从父亲开始检查儿子这种方法不是很好(孩子是有可能不存在的)，从儿子开始检查父亲更加的便捷
		if (root->_col == RED
			&& root->_parent
			&& root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
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