/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Remove Linked List Elements
    ListNode* removeElements(ListNode* head, int val) {
         ListNode *pre=NULL, *cur,*next;

        if(head == NULL)
        	return head;
        	
        // To deal with head pointer
        while(head -> val == val &&head->next != NULL)
        {
        	head = head->next;
        }	
        if(head->val==val)
        	return NULL;
        	
        cur = head;
        while(cur)
        {
        	next = cur->next;
        	if(cur->val == val)
	            pre->next = next;
        	
        	else
        	    pre = cur;
        	cur = next;
        }
        return head;
    }
   