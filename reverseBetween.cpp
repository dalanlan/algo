
/*
LeetCode 92: Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/
Reverse a linked list from position m to n.
Do it in-place and in one-pass.

*/

ListNode* reverseLinkedList(ListNode* head) {
	ListNode *pre=NULL, *cur=head,*next = NULL;
	while(cur) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}


ListNode* reverseBetween(ListNode* head, int m, int n) {
	// m<=n
	if(head == NULL || m == n) {
		return head;
	}

	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *pre=dummy, *begin=head, *end, *tail;
	while (m > 1 && begin != NULL) {
		pre = begin;
		begin = begin->next;
		m--;
		n--;
	}
	end = begin;
	while(n>1 && end != NULL) {
		end = end->next;
		n--;
	}

	tail = end->next;
    	end->next=NULL;
    
	pre->next=reverseLinkedList(begin);
	begin->next=tail;
	return dummy->next;

}