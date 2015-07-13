
//Intersection of two linked lists 
/*

- If the two linked lists have no intersection at all, return null.
- The linked lists must retain their original structure after the function returns.
- You may assume there are no cycles anywhere in the entire linked structure.
- Your code should preferably run in O(n) time and use only O(1) memory.

*/

/*
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};
*/

int getCount(ListNode *head)
{
	int count = 0;
	ListNode *p = head;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(headA == NULL || headB == NULL)
		return NULL;

	int countA = getCount(headA);
	int countB = getCount(headB);
	int diff = abs(countA-countB);

	ListNode *p,*q; // p: the bigger one; q: the smaller one
	if(countA>countB)
	{
		p = headA;
		q = headB;
	}	
	else
	{
		p = headB;
		q = headA;
	}	
	while(diff != 0)
	{
		p = p->next;
		diff--;
	}
	while(p && q)
	{
		if(p == q)
			return p;
		else
		{
			p = p ->next;
			q = q ->next;
		}
	}
	return NULL;

}
