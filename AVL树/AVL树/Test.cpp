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
	// 3. arent == 1 || parent == -1��parent����������ƽ�⣬��Ҫ�����������(��ת����)  
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
	
	Node* _root = nullptr;
};