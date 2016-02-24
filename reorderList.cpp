
/*
LintCode: reorder list
http://www.lintcode.com/zh-cn/problem/reorder-list/
*/

// use function to merge two ListNode 
// that would never change the original ListNode head
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
     * @return: void
     */
    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void merge(ListNode *head, ListNode *right) {
        bool isLeft = true;
        ListNode *dummy = new ListNode(0);
        while(head && right) {
            if(isLeft) {
                dummy->next = head;
                head = head->next;
            }
            else {
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
            isLeft = !isLeft;
        }
        if(head) {
            dummy->next = head;
        }
        else {
            dummy->next = right;
        }
    }
    void reorderList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *right = reverse(slow->next);
        slow->next = NULL;
        merge(head, right);
        
    }
};


