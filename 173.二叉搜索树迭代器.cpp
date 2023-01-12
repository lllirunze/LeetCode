/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    int v[10005] = {0};
    int count = 0;  // 定义数组实际存储大小
    int cur = 0;    // 定义此时位置
    BSTIterator(TreeNode* root) {
        saveV(root, count);
    }

    void saveV(TreeNode* root, int &count){
        if(root->left == nullptr && root->right == nullptr){
            // 已经是根节点
            v[count] = root->val;
            count++;
        }
        else if(root->left == nullptr){
            // 只有右子树
            v[count] = root->val;
            count++;
            saveV(root->right, count);
        }
        else if(root->right == nullptr){
            // 只有左子树
            saveV(root->left, count);
            v[count] = root->val;
            count++;
        }
        else{
            // 左右子树都在
            saveV(root->left, count);
            v[count] = root->val;
            count++;
            saveV(root->right, count);
        }
        return;
    }
    
    int next() {
        cur++;
        return v[cur-1];
    }
    
    bool hasNext() {
        if(cur >= count) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

