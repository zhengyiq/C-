/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        while (cur || !st.empty())
        {
            // ��·�ڵ�
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            // ջ��ȡ����·�ڵ㣬��·�ڵ���������������ˣ���ʼ����������
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            // ������·�ڵ��������
            cur = top->right;
        }
        return v;
    }
};