/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* ite = head;
        while (ite) { // 用next连接
            Node* n = new Node(ite->val, ite->next, nullptr);
            Node* c = ite->next;
            ite->next = n;
            ite = c;
        }
        ite = head;
        while (ite) { // 连接random
            if (ite->random) ite->next->random = ite->random->next;
            ite = ite->next->next;
        }
        ite = head;
        Node* ret = head->next;
        while (ite->next) { // 有丝分裂(大雾)
            Node* c = ite->next;
            ite->next = ite->next->next;
            ite = c;
        }
        return ret;
    }
};
// @lc code=end

