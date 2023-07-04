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
 // ˼·һ��
         // ת���������ཻ����
 // ˼·����
         // ��������������һ������������һ����������
// ˼·����
        // DFS���p��q��·���ŵ������У�ת����·���ཻ������
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

        // p����q�Ǹ�
        if (p == root || q == root)
            return root;

        bool pInLeft = IsInTree(root->left, p);
        bool pInRight = IsInTree(root->right, p);

        bool qInLeft = IsInTree(root->left, q);
        bool qInRight = IsInTree(root->right, q);

        // һ������������һ������������root���ǹ�������
        // ������ת���������⣬����������ȥѰ�ҹ�������
        // �����ң�ת���������⣬����������ȥѰ�ҹ�������
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