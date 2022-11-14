/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    int trans(TreeNode* root){
        if(!root) return 101;
        else return root->val;
    }
    bool judgeTree(TreeNode* leftTree, TreeNode* rightTree){
        if(trans(leftTree) == trans(rightTree)){
            // 左右节点相等
            if(trans(leftTree) == 101){
                // 根节点
                return true;
            }
            else{
                return judgeTree(leftTree->left, rightTree->right) && judgeTree(leftTree->right, rightTree->left);
            }
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return judgeTree(root->left, root->right);
    }
};
// @lc code=end

