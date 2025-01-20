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

#include<bits/stdc++.h>

TreeNode* createBinaryTree(vector<int> nums, int left, int right) {
    if(left > right) return NULL;

    int mid = (left + right) / 2;

    TreeNode *rootNode = new TreeNode(nums[mid]);
    TreeNode *leftNode = createBinaryTree(nums, left, mid - 1);
    TreeNode *rightNode = createBinaryTree(nums, mid + 1, right);

    rootNode->left = leftNode;
    rootNode->right = rightNode;

    return rootNode;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;

        TreeNode* root = createBinaryTree(nums, left, right);

        return root;

    }
};