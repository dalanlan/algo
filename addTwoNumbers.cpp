// Add Two Numbers

/*
You are given two linked list representing two non-negative
numbers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and 
return it as a linked list
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
	if(l1 == NULL && l2 == NULL && carry == 0) {
		return NULL;
	}
	int val = carry;
	val += (l1 != NULL? l1->val:0) + (l2 != NULL? l2->val:0);
	
	ListNode* head = new ListNode(val%10);
	head->next = addTwoNumbers(l1 == NULL? NULL :l1->next, l2 == NULL? NULL:l2->next, val/10);
	return head;

}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	return addTwoNumbers(l1, l2, 0);
}