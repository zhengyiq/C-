//给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
//
//空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/construct-string-from-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

        if (root->left || root->right) // 当左子树为空且右子树非空时才需要打印
        {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        }

        if (root->right) // 当右子树不为空时需要打印
        {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }
};