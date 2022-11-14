/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    vector<int> res;
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }
};
// @lc code=end

