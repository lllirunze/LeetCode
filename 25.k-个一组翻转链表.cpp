/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;
        int total = 0;
        if(!head) return head;
        ListNode* res = new ListNode(-1, head);
        ListNode* prev = res;
        ListNode* cur = prev->next;
        ListNode* tmp = prev->next;
        while(tmp){
            tmp = tmp->next;
            total++;
        }

        tmp = prev->next;
        while(true){
            if(count%k == 0){
                for(int i=0; i<k; i++){
                    prev = prev->next;
                }
                if(count+k > total){
                    break;
                }
                tmp = prev->next;
                cur = prev->next;
                count++;
                continue;
            }
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = tmp;
            tmp = prev->next;
            count++;
        }
        
        return res->next;
    }
};
// @lc code=end

