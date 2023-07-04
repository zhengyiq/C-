/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
 * };
 */
 // 思路一：
         // 转换成链表相交问题
 // 思路二：
         // 公共祖先特征：一个在左子树，一个在右子树
// 思路三：
        // DFS求出p和q的路径放到容器中，转换成路径相交的问题
class Solution {
public:

    bool IsInTree(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
            return false;
        if (root == x)
            return true;
        return IsInTree(root->left, x) || IsInTree(root->right, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        // p或者q是根
        if (p == root || q == root)
            return root;

        bool pInLeft = IsInTree(root->left, p);
        bool pInRight = IsInTree(root->right, p);

        bool qInLeft = IsInTree(root->left, q);
        bool qInRight = IsInTree(root->right, q);

        // 一个在左子树，一个在右子树，root就是公共祖先
        // 都在左，转换成子问题，在左子树中去寻找公共祖先
        // 都在右，转换成子问题，在右子树中去寻找公共祖先
        if ((pInLeft && qInRight) || (qInLeft && pInRight))
            return root;
        else if (pInLeft & qInLeft)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};


class Solution {
public:
    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;

        path.push(root);
        if (root == x)
            return true;

        if (GetPath(root->left, x, path))
            return true;

        if (GetPath(root->right, x, path))
            return true;

        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath, qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }
        return qPath.top();
    }
};