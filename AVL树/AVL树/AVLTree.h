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

	// ����֮����Ҫ����ƽ������
	// ���������֮��ƽ��û�г�������(|bf| <= 1)��ƽ��ṹû���ܵ�Ӱ�죬����Ҫ����
	// ���������֮��ƽ���������(|bf| > 1)��ƽ��ṹ�ܵ�Ӱ�죬��Ҫ����(��ת)
	// 
	// ���������ڵ㣬��Ӱ�����ȵ�ƽ����(ȫ�����߲���)
	// cur == parent->right parent->bf++
	// cur == parent->left parent->bf--
	// parent���ڵ������߶��Ƿ�仯�����˼������£��������ٸ���
	// 1. parent == 1 || parent == -1��parent�������߶ȷ����˱仯����Ҫ�������ϸ��£���Ϊ1��-1�Ǵ�0ת�������ģ�����֮ǰ��parent->bf == 0��˵���������߸߶���ȣ�������һ�߸�1��˵��parent��һ�߸�һ�ߵͣ��߶ȷ����˱仯;
	// 2. parent == 0��parent�������߶Ȳ��䣬���ü������ϸ��£���һ�����������Ϊ0�Ǵ�1��-1ת�������ģ�����֮ǰ��parent->bf == 1 || parent->bf == -1��˵������֮ǰһ�߸�һ�ߵͣ�����ڵ����ϰ����Ǳߣ��߶Ȳ��䡣
	// 3. parent == 1 || parent == -1��parent����������ƽ�⣬��Ҫ�����������(��ת����)  
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

		// ����ƽ������
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
				// ��������
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��Ҫ��ת���� -- 1�����������ƽ�� 2��������������ĸ߶�
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

	void RotateR(Node* parent) // ������Ҫ������ת�ĸ����(parent)��ƽ������Ϊ-2�Ľӵ���
	{
		Node* subL = parent->_left; // ����������(subL)�ڵ㼴ƽ������Ϊ-1�Ľ��
		Node* subLR = subL->_right; // ��Ҫ������ת��ƽ������Ϊ-1���Һ���(subLR)

		parent->_left = subLR; // �ø�������������Ϊ��ԭ����������������
		if (subLR) // ������Ҫע�⸸������������������(subLR)�ǿ���Ϊ�յģ���Ҫ���ж�����ж�
		{
			subLR->_parent = parent; // ����subLR����parentָ��
		}
		
		Node* ppNode = parent->_parent; // ������Ҫ��parent���ĸ������б���
		
		subL->_right = parent; 
		parent->_parent = subL;
		
		if (ppNode == nullptr) // ������Ҫע����ǣ�parent������п���Ϊroot���ģ����Ϊ���ڵ㣬֮ǰ���Ǳ����ppNode������Ϊ�գ���Ҫ���¸�����㣬������Ǿ���Ҫ�������µ����ӣ���������ʱ��Ҫ���бȽ�ȷ����ppNode��������������������Ȼ��subL��ppNode���ำֵ��
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
		parent->_bf = subL->_bf = 0; // �������Ҫ��parent��subL��ƽ�����ӽ�������
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = parent->_left->_right;
		
		int bf = subLR->_bf; // ������Ҫ��¼subLR��ƽ�����ӣ�����ȷ��������ת֮���ƽ�����ӱ仯��

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

		int bf = subRL->_bf; // ������Ҫ��¼subLR��ƽ�����ӣ�����ȷ��������ת֮���ƽ�����ӱ仯��

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1) // ��������������λ��
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1) // ��������������λ��
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
			cout << "�ڵ�ƽ�������쳣" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2 
			&& _IsBalance(root->_left) // ������Ҫ�ݹ���������������ж��Ƿ�ƽ�� 
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
		cout << e << "���룺" << t1.IsBalance() << endl;
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