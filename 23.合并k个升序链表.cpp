/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

    ListNode* divideMerge(vector<ListNode*>& lists, int left, int right){
        if(right == left){
            // 只有一个链表
            return lists[left];
        }
        else if(right-left == 1){
            // 有2个链表
            return mergeTwoLists(lists[left], lists[right]);
        }
        else{
            // 继续分而治之
            int mid = (left+right)/2;
            return mergeTwoLists(divideMerge(lists, left, mid-1), divideMerge(lists, mid, right));
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int right = lists.size();
        int left = 0;
        ListNode *res = new ListNode();
        if(right == 0) return res->next;
        res = divideMerge(lists, left, right-1);
        return res;
    }
};
// @lc code=end

