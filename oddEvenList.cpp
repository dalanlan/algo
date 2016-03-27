
/*
Leetcode: odd even linked list
https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *odd=head, *even = head->next, *evenHead=even;

        while(even && even->next) {
            // solution 1
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even= even->next;
            // solution 2
            // odd->next = odd->next->next;
            // even->next = even->next->next;
            // odd = odd->next;
            // even = even->next;
        }
        odd->next=evenHead;
        return head;
    }
};