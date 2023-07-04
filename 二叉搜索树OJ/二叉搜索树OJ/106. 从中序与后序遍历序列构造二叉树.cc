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
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
class Solution {
public:

    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& prei, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[prei]);
        // 分割出左右子区间
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (inorder[rooti] == postorder[prei])
                break;
            else
                rooti++;
        }
        --prei;
        // [inbegin, rooti - 1][rooti + 1, inend]
        root->right = _buildTree(inorder, postorder, prei, rooti + 1, inend);
        root->left = _buildTree(inorder, postorder, prei, inbegin, rooti - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return _buildTree(inorder, postorder, i, 0, postorder.size() - 1);
    }
};