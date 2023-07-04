//����������ĸ��ڵ� root ���������ǰ������ķ�ʽ����������ת��Ϊһ�������ź�������ɵ��ַ��������ع�������ַ�����
//
//�սڵ�ʹ��һ�Կ����Ŷ� "()" ��ʾ��ת������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/construct-string-from-binary-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
    string tree2str(TreeNode* root) {
        if (root == nullptr)
            return "";

        string str = to_string(root->val);

        if (root->left || root->right) // ��������Ϊ�����������ǿ�ʱ����Ҫ��ӡ
        {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        }

        if (root->right) // ����������Ϊ��ʱ��Ҫ��ӡ
        {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }
};