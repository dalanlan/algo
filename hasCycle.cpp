
/*
LintCode: Determine if a linked list has a cycle

http://www.lintcode.com/zh-cn/problem/linked-list-cycle/

Fast pointer and slow pointer, chasing each other
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
        	return false;
        }

        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow) {
        		return true;
        	}
        }
        return false;  
    }
};



