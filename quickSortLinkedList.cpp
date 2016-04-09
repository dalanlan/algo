
/*

GeeksforGeeks: quick sort on singly linked list
http://www.geeksforgeeks.org/quicksort-on-singly-linked-list/

A complete and brilliant idea 
*/



struct node {
	int data;
	struct node *next;
};

struct node *getTail(struct node *cur) {
	while(cur && cur->next) {
		cur = cur->next;
	}
	return cur;
}

struct node *partition(struct node *head, struct node *end, 
		           struct node **newHead, struct node **newEnd) {
	struct node *pivot = end;
	struct node *prev = NULL, *cur = head, *tail = end;

	while(cur != pivot) {
		if(cur->data < pivot->data) {
			if((*newHead) == NULL) {
				(*newHead) = cur;
			}
			prev = cur;
			cur = cur->next;
		}
		else {
			if(prev) {
				prev ->next = cur->next;
			}
			cur->next = NULL;
			tail ->next = cur;
			tail = cur;
			cur = prev->next;
		}
	}	        
	if((*newHead) == NULL) {
		(*newHead) = pivot;
	}

	*newEnd = tail;
	return pivot;
}

struct node *quickSortRecur(struct node *head, struct node *end) {
	if(!head || head == end) {
		return head;
	}

	node *newHead = NULL, *newEnd = NULL;
	struct node *pivot = partition(head, end, &newHead, &newEnd);

	if(newHead != pivot) {
		struct node *tmp = newHead;
		while(tmp->next != pivot) {
			tmp = tmp->next;
		}
		tmp->next = NULL;
		newHead = quickSortRecur(newHead, tmp);
	}

	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;

}

