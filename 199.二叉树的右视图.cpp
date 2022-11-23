/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> tree;
        tree.push(root);
        while (!tree.empty()) {
            int size = tree.size();
            int cur = tree.front() -> val;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = tree.front();
                cur = tmp -> val;
                tree.pop();
                if (tmp -> left) {
                    tree.push(tmp -> left);
                }
                if (tmp -> right) {
                    tree.push(tmp -> right);
                }
            }
            res.emplace_back(cur);
        }
        return res;
    }
};
// @lc code=end

