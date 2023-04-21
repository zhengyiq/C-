#pragma once
// 增删查改的时间复杂度为:O(N)(极端情况)->平衡搜索二叉树
namespace key
{
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

		/*BSTree()
			:_root(nullptr)
		{}*/

		BSTree() = default; // 强制生成默认构造

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree <K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			Destory(_root);
		}


		bool Insert(const K& key) {
			if (_root == nullptr) {
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;// 需要记录父节点的位置，将要插入的节点链接在父节点之后
			Node* cur = _root;
			while (cur) {
				if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					return false;
				}
			}

			cur = new Node(key);
			if (key > parent->_key) {
				parent->_right = cur;
			}
			else { // key < parent->key
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
			Node* parent = cur; // 这里不能为空，否则删除根节点的时候就会发生报错
			//Node* parent = nullptr; // 这里为空时在删除根节点的时候需要进行处理
			while (cur) {
				if (cur->_key < key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					// 要删除的节点左节点为空值
					if (cur->_left == nullptr) {
						// 如果要删除的结点是根结点，且根结点的左子树为空，那么就需要对_root进行修改
						if (cur == parent) { // cur == _root
							//cur = cur->_right; // err
							_root = cur->_right;
						}

						if (parent->_left == cur) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
						delete cur;
					}
					// 要删除的节点右节点为空值
					else if (cur->_right == nullptr) {
						// 如果要删除的结点是根结点，且根结点的右子树为空，那么就需要对_root进行修改
						if (cur == parent) { // cur == _root
							_root = cur->_left;
						}

						if (parent->_right == cur) {
							parent->_right = cur->_left;
						}
						else {
							parent->_left = cur->_left;
						}
						delete cur;
					}
					// 要删除的节点左右节点都不为空
					else
					{
						// 找到左子树的最大值与右子树的最小值然后与要删除的数据进行替换

						// 找右树最小节点替代，也可以是左树最大节点替代
						//Node* pminRight = cur;
						//Node* minRight = cur->_right;
						//while (minRight->_left)
						//{
						//	pminRight = minRight;
						//	minRight = minRight->_left;
						//}

						//cur->_key = minRight->_key;

						//if (pminRight->_left == minRight)
						//{
						//	pminRight->_left = minRight->_right;
						//}
						//else
						//{
						//	pminRight->_right = minRight->_right;
						//}

						//delete minRight;

						// 找左子树的最大值 - 左子树不为空
						Node* pmaxLeft = cur; // ?
						Node* maxLeft = cur->_left;

						while (maxLeft->_right) {
							pmaxLeft = maxLeft;
							maxLeft = maxLeft->_right;
						}
						cur->_key = maxLeft->_key;

						if (pmaxLeft->_right == maxLeft) {
							pmaxLeft->_right = maxLeft->_left;
						}
						else { // pmaxLeft->left == maxLeft; 
							pmaxLeft->_left = maxLeft->_left;
						}

						delete maxLeft;
					}
					return true;
				}
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	protected:

		Node* Copy(Node* root) {
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(root->_key);

			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;
		}

		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;
			root = nullptr;
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr) { // 根节点为空就直接插入返回
				root = new Node(key);
				return true;
			}

			if (root->_key < key) { // 比根节点大在右树中进行递归查找
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key) { // 比根节点小在左树中进行查找
				return _InsertR(root->_left, key);
			}
			else {
				return false; // 查找失败
			}
		}

		bool _FindR(Node* root, const K& key)// 在递归的版本中我们需要编写两个函数因为我们需要传入头结点，而正常情况下头结点是私有的再类外无法访问到的，因此需要我们创建子函数进行处理。
		{
			if (root == nullptr)
				return false;

			if (root->_key == key)
				return true;

			if (root->_key < key)
				return _FindR(root->_left, key);
			else
				return _FindR(root->_right, key);
		}

		 // 缺省值必须是常量或者是全局变量
		
		void _InOrder(Node* root) // 当前函数不好调用，不能使用缺省参数应为缺省参数的形式：Node* root = _root 因为没有this指针无法调用_root。_root是一个变量而缺省参数需要的是常量
		{
			if (root == nullptr)
				return;
		
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		// 这里特别需要注意的一点就是这里的Node*添加了一个引用，这样的话就可以让我们在删除的时候在该函数栈帧中传入root->_left或者root->_right，在这种情况下虽然我们操作的是要删除的节点，但是这个结点是链接在整棵二叉搜索树中的
		bool _EraseR(Node*& root, const K& key) {
			if (root == nullptr)
				return false;

			if (root->_key < key){
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key) {
				return _EraseR(root->_left, key);
			}
			else { // root->_key = key
				Node* del = root;
				// 开始准备删除
				// 左节点为空
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// 右节点为空
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				else { // 左右节点都不为空 
					Node* maxleft = root->_left;
					while (maxleft->_right) {
						maxleft = maxleft->_right;
					}
					 
					swap(root->_key, maxleft->_key); // 要删除的节点与左子树的最大值

					//return _EraseR(root->_left, key); // 转换成子树去删除
					return _EraseR(maxleft, key); // maxleft是一个局部变量，使用引用传入会发生报错
				}
				delete del;
				return true;
			}
		}
	private:
		Node* _root = nullptr;
	};
}

namespace key_value
{
	// BinarySearchTree -- BSTree
	// SearchBinaryTree

	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;


		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
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
					return false;
				}
			}

			cur = new Node(key, value);
			// 链接
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		Node* Find(const K& key)
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
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

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
					// 删除
					// 1、左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;

					} // 2、右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{
						// 找右树最小节点替代，也可以是左树最大节点替代
						Node* pminRight = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							pminRight = minRight;
							minRight = minRight->_left;
						}

						cur->_key = minRight->_key;

						if (pminRight->_left == minRight)
						{
							pminRight->_left = minRight->_right;
						}
						else
						{
							pminRight->_right = minRight->_right;
						}

						delete minRight;
					}

					return true;
				}
			}

			return false;
		}


		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	protected:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}