
/*
LeetCode 203. Remove Linked List Elements
Remove all the elements from a linked list of 
integers that have value `val`.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
  		while(head != NULL && head->val == val) {
  			head = head->next;
  		}      
  		if(head == NULL || head->next == NULL) {
  			return head;
  		}

  		// head != NULL && head->next !=NULL
  		ListNode *pre, *cur=head, *next;
  		while(cur) {

  			next = cur->next;
  			if(cur->val == val) {
  				pre->next = next;
  			} 
  			else {
  				pre = cur;
  			}
  			cur = next;

  		}
  		return head;
    }
};