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
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        vector<int> v;
        while (cur || !st.empty())
        {
            // 左路节点
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            // 栈中取到左路节点，左路节点的左子树访问完了，开始访问右子树
            TreeNode* top = st.top();

            // 右为空，或者右子树已经被访问过了(上一个节点为右子树)，可以访问根节点
            if (top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                // 访问左路节点的右子树
                cur = top->right;
            }

        }
        return v;
    }
};