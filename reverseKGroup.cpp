

/*
LintCode: reverse nodes in k group
http://www.lintcode.com/zh-cn/problem/reverse-nodes-in-k-group/
LeetCode: reverse nodes in k group
https://leetcode.com/problems/reverse-nodes-in-k-group/

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 // solution 1: recursive
class Solution {
public:
     ListNode* reverseNode(ListNode *head) {
	
	ListNode *pre = NULL, *cur = head, *next = NULL;

	while(cur) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

ListNode* reverseKGroupreverseKGroup(ListNode* head, int k) {
	if(head == NULL || k<=1) {
		return head;
	}
	 

	ListNode* cur = head, *pre=head, *next;
	int m=1;
	
	while(m < k && cur) {
		m++;
		cur = cur->next;
	}
	if(cur) {
    	next = cur->next;
    	cur->next = NULL;
    	pre = reverseNode(head);
    	ListNode *tail = pre;
    	while(tail->next) {
    	    tail = tail->next;
    	}
    	tail->next = reverseKGroup(next, k);
	}

	
	return pre;
}
};

// solution 2:

ListNode* reverseKGroup(ListNode* head, int k) {
	if(head == NULL || k <= 1) {
		return head;
	}

	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	head = dummy;

	while(head->next) {
		head = reverseNextK(head, k);
	}
	return dummy->next;
}

ListNode* reverseNextK(ListNode* head, int k) {
	ListNode* next = head;
	for(int i=0; i<k; i++) {
		if(next->next) {
			next = next->next;
		}
		else {
			return next;
		}
	}

	ListNode *n1 = head->next;
	ListNode *tail = next->next;

	ListNode* cur = n1, *prev = head;
	ListNode* nextPoint = NULL;
	for(int i=0; i<k; i++) {
		nextPoint = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextPoint;
	}

	n1->next = cur; 
	head->next = prev;
	return n1;
}