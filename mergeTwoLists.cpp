
/*
Lintcode: merge two sorted lists
http://www.lintcode.com/zh-cn/problem/merge-two-sorted-lists/
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

 // solution 1:recursive 
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        ListNode *head;
        if(l1->val <= l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

// solution 2: iterative

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *dummy = new ListNode(0);
	ListNode *last=dummy;
	while(l1 != NULL && l2 != NULL) {
		if(l1->val <= l2->val) {
			last->next = l1;
			l1 = l1->next;
		}
		else{
			last->next = l2;
			l2 = l2->next;
		}
		last = last->next;
	}
	if(l1 != NULL) {
		last->next=l1;
	}
	if(l2 != NULL) {
		last->next=l2;
	}
	return dummy->next;
}

