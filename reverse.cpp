

/*
LintCode :reverse linked list
http://www.lintcode.com/zh-cn/problem/reverse-linked-list/

*/


/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        
        ListNode *pre=NULL, *cur=head, *next;

        while(cur) {
        	next = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = next;
        }
        return pre;
    }
};
