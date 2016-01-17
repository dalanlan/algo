
/*
Lintcode 174: remove the nth node from the end, return
the head pointer

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
     * @param n: An integer.
     * @return: The head of linked list.
     */
        ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here

        ListNode* fast = head, *slow = head;
        
        while(fast != NULL && n >= 0) {
        	fast = fast->next;
        	n--;
        }
        while(fast != NULL) {
        	fast = fast->next;
        	slow = slow->next;
        }

        if(slow == head) {
            head = head->next;
            return head;
        }
        if(slow->next != NULL) {
            slow->next = slow->next->next;
        }

  		return head;

    }
};


