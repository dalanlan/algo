// remove linked list elements
// 452. Lintcode


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /**
 * @param head a ListNode
 * @param val an integer
 * @return a ListNode
 */

ListNode *removeElements(ListNode* head, int val) {
	while(head != NULL && head->val == val) {
		head = head->next;
	}
	if(head == NULL) {
		return head;
	}

	ListNode *cur = head, *prev=NULL, *next;

	while(cur) {
		next = cur->next;

		if(cur->val == val) {
			prev->next = next;
		}
		else {
			prev = cur;
		}
		cur = next;
	}
	return head;
}