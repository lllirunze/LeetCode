/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res = new ListNode();
        ListNode *tmp = res;
        while(list1 || list2){
            if(list1 == nullptr){
                tmp->next = list2;
                break;
            }
            else if(list2 == nullptr){
                tmp->next = list1;
                break;
            }
            else{
                if(list1->val < list2->val){
                    tmp->next = new ListNode(list1->val);
                    tmp = tmp->next;
                    list1 = list1->next;
                }
                else{
                    tmp->next = new ListNode(list2->val);
                    tmp = tmp->next;
                    list2 = list2->next;
                }
            }
        }
        return res->next;
    }
};
// @lc code=end

