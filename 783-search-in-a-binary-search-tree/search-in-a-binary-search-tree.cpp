class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return NULL;
        else if (root->val == val)
            return root;
        else if (val < root->val)
            return searchBST(root->left, val);            
        else  /* val > root->val */
            return searchBST(root->right, val);
    }
};