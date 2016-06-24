// Populating Next Right Pointers in Each Node

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

// BFS 
// Using index to decide whether it points to NULL
void connect(TreeLinkNode* root) {
	if(root == NULL) {
		return;
	}
	queue<pair<TreeLinkNode*,int>> q;
	q.push(make_pair(root,1));
	int depth = 1;

	while(!q.empty()) {
		pair<TreeLinkNode*, int> tmp = q.front();
		q.pop();

		TreeLinkNode* node = tmp.first;
		int index = tmp.second;
		
		if(node->left) {
			q.push(make_pair(node->left, 2*index));
		}
		if(node->right) {
			q.push(make_pair(node->right, 2*index+1));
		}

		if(log2(index+1) == depth) {
			depth++;
			node->next = NULL;
		}
		else {
			node->next = q.front().first;
		}

	}

}


// Other solution

void connect(TreeLinkNode* root) {
	if(root == NULL || root->left == NULL) {
		return;
	}
	TreeLinkNode* tmp = root;
	TreeLinkNode* cur = root;
   
	while(cur->left != NULL) {
		cur->left->next = cur->right;
		cur->right->next = cur->next?cur->next->left:NULL;
		cur = cur->next;
		if(cur == NULL) {
		    tmp=tmp->left;
			cur=tmp;
		}
	}
}
// smart bfs 
void connect(TreeLinkNode* root) {
	TreeLinkNode* dummy = new TreeLinkNode(0);
	TreeLinkNode* pre = dummy;

	while(root != NULL) {
		if(root->left) {
			pre->next = root->left;
			pre = pre->next;
		}
		if(root->right) {
			pre->next = root->right;
			pre = pre->next;
		}
		root = root->next;
		if(root == NULL) {
			pre = dummy;
			root = pre->next;
			dummy->next = NULL;
		}
	}
}


// easy bfs
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

 // defintely work for `populate next right pointers in each node ii`
 // https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // bfs???
        if(!root) {
            return;
        }
        queue<TreeLinkNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i < sz; i++) {
                TreeLinkNode* tmp = q.front();
                q.pop();
                if(i == sz-1) {
                    tmp->next = NULL;
                }
                else {
                    tmp->next = q.front();
                }
                
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
        return;
        
    }
};
