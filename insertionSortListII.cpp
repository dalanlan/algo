
/*
Lintcode 173: adopt insert sort into a linked list
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre, *cur=head, *next=NULL;

        while(cur) {
        	pre = dummy;
        	while(pre->next != NULL && pre->next->val <= cur->val)	{
        		pre=pre->next;
        	}
        	next = cur->next;

        	cur->next = pre->next;
        	pre->next = cur;
        	cur = next;
        }	
        return dummy->next;
    }
};