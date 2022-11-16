/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        int res = -1000;
        int acc = dfs(root,res);
        return max(acc,res);
    }

    int dfs(TreeNode* root, int& res) {
        if (!root) return -1000;
        int l = dfs(root->left,res);
        int r = dfs(root->right,res);
        res = max(res, l); // case 5
        res = max(res, r); // case 6
        res = max(res, l+r+root->val); // case 1
        int acc = root->val; // case 4
        acc = max(acc,root->val+l); // case 2
        acc = max(acc,root->val+r); // case 3
        return acc;
    }
};
// @lc code=end

