/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if((!head) || (!head->next)) return false;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur && cur->next){
            if(pre == cur) return true;
            pre = pre->next;
            cur = cur->next->next;
        }
        return false;
    }
};
// @lc code=end

