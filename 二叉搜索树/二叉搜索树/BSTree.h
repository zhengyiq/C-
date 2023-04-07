#pragma once

template <class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template <class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else // key < parent->key
		{
			parent->_left = cur;
		}
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur; // ���ﲻ��Ϊ�գ�����ɾ�����ڵ��ʱ��ͻᷢ������
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// Ҫɾ���Ľڵ���ڵ�Ϊ��ֵ
				if (cur->_left == nullptr)
				{
					if (cur == parent)
					{
						//cur = cur->_right; // err
						_root = cur->_right;
						delete parent;
						return true;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
					return true;
				}
				// Ҫɾ���Ľڵ��ҽڵ�Ϊ��ֵ
				else if (cur->_right == nullptr)
				{
					if (cur == parent)
					{
						_root = cur->_left;
						delete parent;
						return true;
					}
					if (parent->_right == cur)
					{
						parent->_right = cur->_left;
					}
					else
					{
						parent->_left = cur->_left;
					}
					delete cur;
					return true;
				}
				// Ҫɾ���Ľڵ����ҽڵ㶼��Ϊ��
				else
				{
					// �ҵ������������ֵ������������СֵȻ����Ҫɾ�������ݽ����滻

					// �������������ֵ - ��������Ϊ��
					Node* pmaxLeft = cur; // ?
					Node* maxLeft = cur->_left;

					while (maxLeft->_right)
					{
						pmaxLeft = maxLeft;
						maxLeft = maxLeft->_right;
					}
					cur->_key = maxLeft->_key;

					if (pmaxLeft->_right == maxLeft)
					{
						pmaxLeft->_right = maxLeft->_left;
					}
					else // pmaxLeft->left == maxLeft;
					{
						pmaxLeft->_left = maxLeft->_left;
					}

					delete maxLeft;
					return true;
				}
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}


private:
	Node* _root = nullptr;
	
	void _InOrder(Node* root) // ��ǰ�������õ��ã�����ʹ��ȱʡ����ӦΪȱʡ��������ʽ��Node* root = _root ��Ϊû��thisָ���޷�����_root�� // ȱʡֵ�����ǳ���������ȫ�ֱ���
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
};