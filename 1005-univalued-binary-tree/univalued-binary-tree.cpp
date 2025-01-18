/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        if (!root)
            return false;

        bool flag = true;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* parent = que.front();
            que.pop();

            if ((parent->left && parent->val != parent->left->val) ||
                (parent->right && parent->val != parent->right->val)) {
                flag = false;
                break;
            }

            if (parent->left)
                que.push(parent->left);
            if (parent->right)
                que.push(parent->right);
        }

        return flag;
    }
};