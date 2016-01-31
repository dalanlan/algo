/*
LintCode: palindrome linked list
http://www.lintcode.com/zh-cn/problem/palindrome-linked-list/
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
     * @return a boolean
     */
    ListNode* reverse(ListNode* head) {
        ListNode *pre=NULL, *cur=head, *next;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode *fast = head->next->next, *slow = head;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *rt = reverse(slow->next);
        slow->next = NULL;
        fast = head;
        while(fast && rt) {
            if(fast->val != rt->val) {
                return false;
            }
            fast = fast->next;
            rt = rt->next;
        }
        return true;
    }
};