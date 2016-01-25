
/*
LintCode : sort linked list 
http://www.lintcode.com/zh-cn/problem/sort-list/

time complexity: O(nlogn) 
space complexity: O(1)
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
        	return head;
        } 

        ListNode *fast=head->next->next, *slow = head;
        while(fast && fast->next){
        	fast = fast->next->nex;
        	slow = slow->next;
        }
        ListNode *rt = sortList(slow->next);
        slow->next=NULL;
        ListNode *lf = sortList(head);
        return merge(lf, rt);

    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
    	ListNode *head=NULL, *tail = NULL;
    	while(l1 && l2) {
    		if(l1->val < l2->val) {
    			if(head == NULL) {
    				head = l1;
    				tail = head;
    			}
    			else {
    				tail->next = l1; 
    				tail = tail->next;
    			}
    			l1 = l1->next;
    		}
    		else {
    			if(head == NULL) {
    				head = l2;
    				tail = head;
    			}
    			else {
    				tail->next = l2; 
    				tail = tail->next;
    			}
    			l2 = l2->next;
    		}
    	}
    	if(l1 != NULL) {
    		tail->next=l1;
    	}
    	if(l2 != NULL) {
    		tail->next=l2;
    	}
    	return head;
    }
};


