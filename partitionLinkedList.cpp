
/*
Leetcode: partition List
https://leetcode.com/problems/partition-list/
*/


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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return head;
        }
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        
        ListNode* less = dummy1, *greater = dummy2;
        ListNode* cur = head;
        while(cur) {
            if(cur->val < x) {
                less->next = cur;
                less = less->next;
            }
            else {
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }
        greater->next = NULL;
        
        if(less != dummy1 && greater != dummy2) {
            less->next = dummy2->next;
            return dummy1->next;
        }
        if(less != dummy1) {
            less->next = NULL;
            return dummy1->next;
        }
        return dummy2->next;
    }
};