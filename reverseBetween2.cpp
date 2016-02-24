
/*
LintCode: reverse linked list ii 
http://www.lintcode.com/zh-cn/problem/reverse-linked-list-ii/
*/

// find the pre pointer, which is important
// more importantly, introduce a dummy head to save the work.
/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == NULL || m == n) {
        return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
	ListNode *slow = dummy, *fast;
	int tmpM = m;
	
	while(--m > 0) {
		slow = slow->next;
	}
	fast = slow;
	n -= tmpM-1;
	while(n--) {
		fast = fast->next;
	}
	ListNode *tail = fast->next;
	fast->next = NULL;
	ListNode *mid = slow->next;
	slow->next = reverse(slow->next);
	
	mid->next = tail;
	return dummy->next;
}
ListNode *reverse(ListNode *head) {
	ListNode *pre=NULL, *cur = head, *next= NULL;
	while(cur) {
		next = cur->next;
		cur->next= pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
};
