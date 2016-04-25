
/*
LeetCode: reorder List
https://leetcode.com/problems/reorder-list/
*/


// solution 1: recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // TLE
 // recursive
class Solution {
public:
    ListNode* reorder(ListNode* head) {
        if(!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *tailPrev = head;
        while(tailPrev->next->next) {
            tailPrev = tailPrev->next;
        }
        ListNode *tail = tailPrev->next;
        tailPrev->next = NULL;
        tail->next = reorder(head->next);
        head->next = tail;
        return head;
    }
    void reorderList(ListNode* head) {
        reorder(head);
    }
};
