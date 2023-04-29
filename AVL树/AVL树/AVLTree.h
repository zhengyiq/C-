#pragma once

template<class K, class V>
class AVLTreeNode
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

private:

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = sub_RL;
		if (subRL)
		{
			subRL->_parent = parent->_parent;
		}
		Node* ppNode = parent->_parent;
		
		subR->_left = parent;
		parent->_parent = subR;

		if (ppNode = nullptr)
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
		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
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

private:
	Node* _root = nullptr;
};