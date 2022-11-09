/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* anchor = new ListNode(-1, head);

        ListNode* prev = anchor;
        ListNode* cur = anchor ->next;

        while(cur && cur->next){
            prev->next = cur->next;
            cur->next=cur->next->next;
            prev->next->next = cur;
            prev = cur;
            cur = prev->next;
        }

        return anchor->next;
    }
};
// @lc code=end

