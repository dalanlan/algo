// inorder traversal 
    int cur=0;
	vector<int> res;
   
    
    BSTIterator(TreeNode *root) {
		stack<TreeNode*> stk;
        TreeNode* tmp = root;

        while(tmp != NULL || !stk.empty()) {
        	if(tmp != NULL) {
        		stk.push(tmp);
        		tmp = tmp->left;
        	}
        	else {
        		tmp = stk.top();
        		stk.pop();
        		res.push_back(tmp->val);
        		tmp = tmp->right;
        	}
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur< res.size();
    }

    /** @return the next smallest number */
    int next() {
        return res[cur++];
    }