// Detect and Remove Loop in a Linked List
// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/


struct node{
	int data;
	struct node* next;
};

/* Detect and remove loop in the list.
Return 1 if there is a loop, otherwise returns 0.
*/
int detectAndRemoveLoop(struct node *list){
	struct node *slow = list,*fast = list;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		// loop exists;
		if(slow == fast)
		{
			removeLoop(slow,list);
			return 1;
		}
	}
	return 0;

}

void removeLoop(struct node *slow,struct node *list){
	struct node *tmp = slow, *head = list;
	while( tmp != head ){
		tmp = tmp->next;
		head = head->next;
	}
	tmp->next = NULL;
}