#pragma once
// ��ɾ��ĵ�ʱ�临�Ӷ�Ϊ:O(N)(�������)->ƽ������������
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

		BSTree() = default; // ǿ������Ĭ�Ϲ���

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

			Node* parent = nullptr;// ��Ҫ��¼���ڵ��λ�ã���Ҫ����Ľڵ������ڸ��ڵ�֮��
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
			Node* parent = cur; // ���ﲻ��Ϊ�գ�����ɾ�����ڵ��ʱ��ͻᷢ������
			//Node* parent = nullptr; // ����Ϊ��ʱ��ɾ�����ڵ��ʱ����Ҫ���д���
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
					// Ҫɾ���Ľڵ���ڵ�Ϊ��ֵ
					if (cur->_left == nullptr) {
						// ���Ҫɾ���Ľ���Ǹ���㣬�Ҹ�����������Ϊ�գ���ô����Ҫ��_root�����޸�
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
					// Ҫɾ���Ľڵ��ҽڵ�Ϊ��ֵ
					else if (cur->_right == nullptr) {
						// ���Ҫɾ���Ľ���Ǹ���㣬�Ҹ�����������Ϊ�գ���ô����Ҫ��_root�����޸�
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
					// Ҫɾ���Ľڵ����ҽڵ㶼��Ϊ��
					else
					{
						// �ҵ������������ֵ������������СֵȻ����Ҫɾ�������ݽ����滻

						// ��������С�ڵ������Ҳ�������������ڵ����
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

						// �������������ֵ - ��������Ϊ��
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
			if (root == nullptr) { // ���ڵ�Ϊ�վ�ֱ�Ӳ��뷵��
				root = new Node(key);
				return true;
			}

			if (root->_key < key) { // �ȸ��ڵ���������н��еݹ����
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key) { // �ȸ��ڵ�С�������н��в���
				return _InsertR(root->_left, key);
			}
			else {
				return false; // ����ʧ��
			}
		}

		bool _FindR(Node* root, const K& key)// �ڵݹ�İ汾��������Ҫ��д����������Ϊ������Ҫ����ͷ��㣬�����������ͷ�����˽�е��������޷����ʵ��ģ������Ҫ���Ǵ����Ӻ������д���
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

		 // ȱʡֵ�����ǳ���������ȫ�ֱ���
		
		void _InOrder(Node* root) // ��ǰ�������õ��ã�����ʹ��ȱʡ����ӦΪȱʡ��������ʽ��Node* root = _root ��Ϊû��thisָ���޷�����_root��_root��һ��������ȱʡ������Ҫ���ǳ���
		{
			if (root == nullptr)
				return;
		
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		// �����ر���Ҫע���һ����������Node*�����һ�����ã������Ļ��Ϳ�����������ɾ����ʱ���ڸú���ջ֡�д���root->_left����root->_right���������������Ȼ���ǲ�������Ҫɾ���Ľڵ㣬���������������������ö����������е�
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
				// ��ʼ׼��ɾ��
				// ��ڵ�Ϊ��
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// �ҽڵ�Ϊ��
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				else { // ���ҽڵ㶼��Ϊ�� 
					Node* maxleft = root->_left;
					while (maxleft->_right) {
						maxleft = maxleft->_right;
					}
					 
					swap(root->_key, maxleft->_key); // Ҫɾ���Ľڵ��������������ֵ

					//return _EraseR(root->_left, key); // ת��������ȥɾ��
					return _EraseR(maxleft, key); // maxleft��һ���ֲ�������ʹ�����ô���ᷢ������
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
			// ����
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
					// ɾ��
					// 1����Ϊ��
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

					} // 2����Ϊ��
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
						// ��������С�ڵ������Ҳ�������������ڵ����
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