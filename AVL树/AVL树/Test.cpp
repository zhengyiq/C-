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
	// 3. arent == 1 || parent == -1，parent所在子树不平衡，需要处理这棵子树(旋转处理)  
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