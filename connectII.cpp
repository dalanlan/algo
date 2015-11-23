// Populating Next Right pointers in each node II

// The given binary is not a perfect one


// I have no idea how we can do this via DFS
// WA
void connect(TreeLinkNode* root) {
	if(!root || (!root->left && !root->right)) {
		return;
	}

	TreeLinkNode* mid = root;
	TreeLinkNode* cur = root;

	while(cur->left || cur->right ) {
		if(cur->left) {
			cur->left->next = cur->right?cur->right:NULL;
		}
		if(cur->right) {
			cur->right->next = cur->next?cur-next->left:NULL;
		}
		cur = cur->next;
		if(!cur) {
			if(mid->left) {
				mid = mid->left;
			}
			else if(mid->right) {
				mid = mid->right;
			}
			cur = mid;
		}

	}
}

// Let me try BFS / level order traversal
// Ref
// https://leetcode.com/discuss/67291/java-solution-with-constant-space
// https://leetcode.com/discuss/65526/ac-python-o-1-space-solution-12-lines-and-easy-to-understand

  void connect(TreeLinkNode* root) {
	TreeLinkNode* dummy = new TreeLinkNode(0);
	TreeLinkNode* pre = dummy;
    
	while(root != NULL){
		if(root->left != NULL) {
			pre->next = root->left;
			pre = pre->next;
		}
		if(root->right != NULL) {
			pre->next = root->right;
			pre = pre->next;
		}
		root = root->next;
		if(root == NULL) {
			pre = dummy;
			root = dummy->next;
			dummy->next = NULL;
		}
	}
}