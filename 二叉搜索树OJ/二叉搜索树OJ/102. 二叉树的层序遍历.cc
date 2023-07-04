//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
//https ://leetcode.cn/problems/binary-tree-level-order-traversal/
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
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int levelSize = 0;
        vector<vector<int>> ivv;
        if (root) // 判断根节点是否为空
        {
            q.push(root);
            levelSize = q.size();
        }

        while (!q.empty()) // 判断是否树是否走完
        {
            vector<int> iv; // 记录当前的层上的数值
            while (levelSize--)// 按照levelSize的控制分层输出
            {
                TreeNode* front = q.front();
                q.pop();
                iv.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            levelSize = q.size();
            ivv.push_back(iv);
        }
        return ivv;
    }
};