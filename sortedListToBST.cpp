
// Convert sorted list to binary search tree
// Given a singly linked list where elements are sorted
// in ascending order, convert it to a height balanced 
// BST 


// singly-linked lsit
/* 
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
};
*/

// binary tree node 
/*
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
*/

// Use fast&slow pointer

ListNode* mid(ListNode* head, ListNode* tail) {
	if(head == NULL) {
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head;

	while(slow != tail && slow->next != tail && fast->next != tail && fast->next->next != tail) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

TreeNode* helper(ListNode* head, ListNode* tail) {
    if(head == NULL || head == tail) {
        return NULL;
    }
	ListNode* midNode = mid(head, tail);
	TreeNode* root = new TreeNode(midNode->val);
	root->left = helper(head, midNode);
	root->right = helper(midNode->next, tail); 

	return root;
}
TreeNode* sortedListToBST(ListNode* head) {
	TreeNode* root = helper(head, NULL);
	return root;
}