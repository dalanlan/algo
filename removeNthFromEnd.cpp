

//Remove Nth Node From End of List

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL)
		return head;

	ListNode* pFast=head, *pSlow=head, *pre;

	while(n!=0)
	{	
		pFast= pFast->next;
		n--;
	}
	while(pFast != NULL)
	{
		pFast = pFast->next;
		pre = pSlow;
		pSlow = pSlow ->next;

	}
	if(pSlow == head)
		head = head->next;
		return head;

	if(pSlow->next == NULL)
		delete(pSlow);
	else{
		pre->next = pSlow->next;
		delete(pSlow);
	} 
	return head;
}