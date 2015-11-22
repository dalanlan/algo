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

// Let me try stupid BFS 