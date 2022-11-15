/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return  pre_order(0, inorder.size()-1, 0, inorder.size()-1, inorder, postorder);
    }
    TreeNode* pre_order(int leftin, int rightin, int leftpost, int rightpost, vector<int>& in, vector<int>& post){
        if (leftin > rightin) return NULL;
        TreeNode *root = new TreeNode(post[rightpost]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != post[rightpost]) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftin, rootin - 1, leftpost, leftpost + left - 1, in, post);
        root->right = pre_order(rootin + 1, rightin, leftpost + left, rightpost - 1, in, post);
        return root;
    }
};
// @lc code=end

