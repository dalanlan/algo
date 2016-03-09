
/*
LintCode: linked list cycle ii
http://www.lintcode.com/zh-cn/problem/linked-list-cycle-ii/
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        
        // no cycle
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *fast = head, *slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                break;
            }
        }
        if(!fast || !fast->next) {
            // no cycle
            return NULL;
        }
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


