
/*
LintCode : Remove duplicate elements from a sorted linked list
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) {
        	return head;
        }
        ListNode *cur=head, *next;

        while(cur) {
        	next = cur->next;
        	while(next != NULL && cur->val == next->val ) {
        		next = next->next;
        	} 
        	cur->next = next;
        	cur = next;
        }
        return head;
    }
};