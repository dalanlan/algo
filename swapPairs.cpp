
/*

LintCode 451: Swap pairs in the linked list

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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        
        ListNode *first=head, *sec=first->next, *tail;
        dummy->next = sec;
 
        tail = sec->next;
        sec->next = first;
        first->next = swapPairs(tail);
        
        return dummy->next;
        
    }