#pragma once

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf; // balance factor

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:

	// 插入之后需要更新平衡因子
	// 如果更新完之后，平衡没有出现问题(|bf| <= 1)，平衡结构没有受到影响，不需要处理
	// 如果更新完之后，平衡出现问题(|bf| > 1)，平衡结构受到影响，需要处理(旋转)
	// 
	// 插入新增节点，会影响祖先的平因子(全部或者部分)
	// cur == parent->right parent->bf++
	// cur == parent->left parent->bf--
	// parent所在的子树高度是否变化？变了继续更新，不变则不再更新
	// 1. parent == 1 || parent == -1，parent的子树高度发生了变化，需要继续往上更新，因为1和-1是从0转换过来的，插入之前是parent->bf == 0，说明左右两边高度相等，现在有一边高1，说明parent有一边高一边低，高度发生了变化;
	// 2. parent == 0，parent的子树高度不变，不用继续往上更新，这一插入结束。因为0是从1和-1转换过来的，插入之前是parent->bf == 1 || parent->bf == -1，说明插入之前一边高一边低，插入节点填上矮的那边，高度不变。
	// 3. parent == 1 || parent == -1，parent所在子树不平衡，需要处理这棵子树(旋转处理)  
	// 
	//

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续更新
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 需要旋转处理 -- 1、让这颗子树平衡 2、降低这颗子树的高度
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}


	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

private:

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		Node* ppNode = parent->_parent;
		
		subR->_left = parent;
		parent->_parent = subR;

		if (ppNode == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else // ppNode->_right = parent
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent) // 传入需要进行旋转的父结点(parent)即平衡因子为-2的接地那
	{
		Node* subL = parent->_left; // 父结点的左孩子(subL)节点即平衡因子为-1的结点
		Node* subLR = subL->_right; // 需要进行旋转的平衡因子为-1的右孩子(subLR)

		parent->_left = subLR; // 让父结点的左子树变为其原来左子树的右子树
		if (subLR) // 这里需要注意父结点的左子树的右子树(subLR)是可能为空的，需要进行额外的判断
		{
			subLR->_parent = parent; // 链接subLR结点的parent指针
		}
		
		Node* ppNode = parent->_parent; // 这里需要将parent结点的父结点进行保存
		
		subL->_right = parent; 
		parent->_parent = subL;
		
		if (ppNode == nullptr) // 这里需要注意的是，parent结点是有可能为root结点的，如果为根节点，之前我们保存的ppNode结点就是为空，需要重新赋根结点，如果不是就需要进行重新的链接，重新链接时需要进行比较确定是ppNode的左子树还是右子树。然后将subL与ppNode互相赋值。
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else // ppNode->_right = parent
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0; // 这里就需要将parent、subL的平衡因子进行修正
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = parent->_left->_right;
		
		int bf = subLR->_bf; // 这里需要记录subLR的平衡因子，用来确定后面旋转之后的平衡因子变化。

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = parent->_right->_left;

		int bf = subRL->_bf; // 这里需要记录subLR的平衡因子，用来确定后面旋转之后的平衡因子变化。

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1) // 插入在右子树的位置
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1) // 插入在左子树的位置
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		
		if (rightH - leftH != root->_bf)
		{
			cout << "节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2 
			&& _IsBalance(root->_left) // 这里需要递归进入子树来进行判断是否平衡 
			&& _IsBalance(root->_right);
	}

private:
	Node* _root = nullptr;
};

void Test_AVLTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		/*if (e == 14)
		{
			int x = 0;
		}*/

		t1.Insert(make_pair(e, e));
		cout << e << "插入：" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	cout << t1.IsBalance() << endl;
}

void Test_AVLTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}