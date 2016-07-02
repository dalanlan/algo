
/*
LeetCode: Two Numbers
https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
*/

// Runtime Error
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
	if(!l1 && !l2 && carry == 0) {
		returun NULL;
	}
	int val = carry;
	val += l1 == NULL?0:l1->val + l2 == NULL?0:l2->val;

	ListNode* root = new ListNode(val%10);
	root->next = addTwoNumbers(!l1?NULL:l1->next, !l2?NULL:l2->next, val/10);
	return root;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	return addTwoNumbers(l1, l2, 0);
}