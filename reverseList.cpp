// Reverse a single-linked list.
/*
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),  next(NULL){}
};

*/

//iterative solution
ListNode* reverseList(ListNode* head) 
{
	ListNode * pre=NULL, *cur=head;

	while(cur){
		ListNode *next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}

	return pre;

}

//try me
ListNode* reverseList(ListNode *head)
{
	ListNode * pre = NULL, *cur = head;
	while(cur)
	{
		ListNode * next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;

	}
	return pre;
}

// recursive solution
 void reverseListNode(ListNode* p, ListNode* q)
{
    if(q->next != NULL)
        reverseListNode(p->next,q->next);
    q->next = p;
    return;
    
}

ListNode* reverseList(ListNode* head) 
{
	if(head == NULL || head -> next ==NULL)
		return head;
    ListNode* tail =head;
    while(tail->next!= NULL)
        tail = tail->next;
	ListNode* p = head;
	ListNode* q=  p->next;
	reverseListNode(p,q);
	head->next = NULL;
	
	return tail;
	
}


