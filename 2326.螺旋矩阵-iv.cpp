/*
 * @lc app=leetcode.cn id=2326 lang=cpp
 *
 * [2326] 螺旋矩阵 IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res;
        for(int i=0; i<m; i++){
            vector<int> tmp(n, -1);
            res.push_back(tmp);
        }
        // direction = 0(right), 1(down), 2(left), 3(up)
        int direction = 0;
        int up_boundary = 0, down_boundary = m-1, left_boundary = 0, right_boundary = n-1;
        int i = 0, j = 0;
        while(head){
            res[i][j] = head->val;
            head = head->next;
            if(direction == 0){
                if(j == right_boundary){
                    direction++;
                    i++;
                    up_boundary++;
                }
                else j++;
            }
            else if(direction == 1){
                if(i == down_boundary){
                    direction++;
                    j--;
                    right_boundary--;
                }
                else i++;
            }
            else if(direction == 2){
                if(j == left_boundary){
                    direction++;
                    i--;
                    down_boundary--;
                }
                else j--;
            }
            else{
                if(i == up_boundary){
                    direction = 0;
                    j++;
                    left_boundary++;
                }
                else i--;
            }
        }
        return res;
    }
};
// @lc code=end

