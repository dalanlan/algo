
/*
Lintcode 96: part a linked list

Given a linked list and an integer x, divide the linked list
into two parts.

样例
给定链表 1->4->3->2->5->2->null，并且 x=3
返回 1->2->2->4->3->5->null

*/

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
     * @param x: an integer
     * @return: a ListNode 
     */
ListNode *partition(ListNode *head, int x) {
        ListNode *lowH=NULL,*lowT=NULL, *highH=NULL, *highT=NULL;
        ListNode *cur= head;
        while(cur) {
        	if(cur->val < x) {
        		if(lowH == NULL) {
        			lowH = cur;
        			lowT = lowH;
        		}
        		else {
        			lowT->next = cur;
        			lowT = lowT->next;
        		}
        	}
        	else {
        		if(highH == NULL) {
        			highH = cur;
        			highT = highH;
        		}
        		else {
        			highT->next = cur;
        			highT = highT->next;
        		}
        	}
        	cur = cur->next;
        }
        if(lowT != NULL) {
            lowT->next = NULL;
        }
        if(highT != NULL) {
            highT->next = NULL;
        }
        if(lowH && highH) {
        	lowT->next = highH;
        	return lowH;
        }
        if(lowH) {
        	return lowH;
        }
        if(highH) {
        	return highH;
        }
        return NULL;
    }


// solution 2: rewrite 
// use a dummy pointer

ListNode *partition(ListNode *head, int x) {
	ListNode *dummyLeft = new ListNode(0);
	ListNode *dummyRight = new ListNode(0);

	ListNode *left=dummyLeft, *right=dummyRight;
	while(head) {
		if(head->val < x) {
			left->next = head;
			left = left->next;
		}
		else {
			right->next = head;
			right = right->next;
		}
		head = head->next;
	}
	left->next=dummyRight->next;
	right->next=NULL;
	return dummyLeft->next;
}