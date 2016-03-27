
/*
Leetcode: palindrome linked list 
https://leetcode.com/problems/palindrome-linked-list/
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
    

bool isPalindrome(ListNode* head)
{
    if(head==NULL)
        return true;
	stack<ListNode*> stk;
	ListNode* tmp = head;
	while(tmp)
	{
		stk.push(new ListNode(tmp->val));
		tmp = tmp->next;
	}
	while(!stk.empty())
	{
	    if(stk.top()->val != head->val) {
	        return false;
	    }
		stk.pop();
		
		head = head->next;
	}
	
	
    return true;
	
}

};