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
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        while (cur || !st.empty())
        {
            while (cur)
            {
                // ��ʼ����һ����
                // ��·�ڵ�
                // ��·�ڵ��������
                st.push(cur);
                v.push_back(cur->val);
                cur = cur->left;
            }

            // ��ʼ����������
            TreeNode* top = st.top();
            st.pop();

            // ���������������
            cur = top->right;
        }
        return v;
    }
};