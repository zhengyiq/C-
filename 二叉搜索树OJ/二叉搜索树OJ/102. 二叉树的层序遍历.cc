//����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��
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
        if (root) // �жϸ��ڵ��Ƿ�Ϊ��
        {
            q.push(root);
            levelSize = q.size();
        }

        while (!q.empty()) // �ж��Ƿ����Ƿ�����
        {
            vector<int> iv; // ��¼��ǰ�Ĳ��ϵ���ֵ
            while (levelSize--)// ����levelSize�Ŀ��Ʒֲ����
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