
/*
LeetCode 148: Sort List
Sort a linked list in O(nlogn) time using constant
space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // merge sort
 ListNode* sortList(ListNode* head) {
 	 if(head == NULL || head->next == NULL) {
 	 	return head;
 	 }

 	 //merge sort is tricky
 	 ListNode *fast=head->next->next, *slow=head;
 	 while(fast != NULL && fast->next != NULL) {
 	 	 fast = fast->next->next;
 	 	 slow = slow->next; 
 	 }

 	 // first right 
 	 ListNode *rt = sortList(slow->next);
 	 // make sure we cut the cord
 	 slow->next = NULL;
 	 // next left
 	 ListNode *lf = sortList(head);
 	 return merge(lf, rt);


 }

 ListNode* merge(ListNode* head1, ListNode* head2) {
 	ListNode *l3=NULL, *head3;

 	while(head1 != NULL && head2 != NULL) {
 		if(head1->val < head2->val) {
 			if(l3 == NULL) {
 				l3 = head1;
 				head3 = l3;
 			} 
 			else {
 				l3->next = head1;
 				l3 = l3->next;
 			}

 			head1 = head1->next;
 		}
 			
 		else {
 			if(l3 == NULL) {
 				l3 = head2;
 				head3 = l3;
 			}
 			else {
 				l3->next = head2;
 				l3 = l3->next;
 			}
 			head2 = head2->next;
 		}

 	}
 	if(head1 != NULL) {
 		l3->next = head1;
 	}
 	while(head2 != NULL) {
 		l3->next = l2;
 	}
 	return head3;
 }

 // solution 2: rewrite merge part

 ListNode *merge(ListNode *head1, ListNode *head2) {
 	ListNode *dummy = new ListNode(0);
 	ListNode *node = dummy;

 	while(head1 && head2) {
 		if(head1->val < head2->val) {
 			node->next = head1;
 			head1 = head1->next;
 		}
 		else {
 			node->next = head2;
 			head2 = head2->next;
 		}
 		node = node->next;
 	}
 	if(head1) {
 		node->next = head1;
 	}
 	if(head2) {
 		node->next = head2;
 	}
 	return dummy->next;
 }