
/*
LintCode: count of smaller number before itself ii
http://www.lintcode.com/zh-cn/problem/count-of-smaller-number-before-itself/
*/

// solution 2: binary search tree
// cannot tell why it's true
class BSTNode {
public:
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;

	BSTNode(int v) {
		val = v;
		count = 0;
		left = right = NULL;
	}
};
    BSTNode* root=NULL;

	void update(int val) {
		if(root == NULL) {
			root = new BSTNode(val);
			return;
		}
  	
		BSTNode* cur = root;
		while(cur) {
		    if(cur->val > val) {
		        cur->count++;
		        if(cur->left==NULL) {
		            cur->left = new BSTNode(val);
		            break;
		        }
		        else {
		            cur = cur->left;
		        }
		    }
		    
		    else {
		        if(cur->right==NULL) {
		            cur->right = new BSTNode(val);
		        
		            break;
		        }
		        else {
		            cur = cur->right;
		        }
		    }
		}

	}

	int query(int val) {
		if(root == NULL) {
			return 0;
		}
		int count = 0;
		BSTNode* cur = root;
		while(cur) {
			if(cur->val == val) {
				count += cur->count;
				break;
				
			}
			else if(cur->val > val) {
				// search its left subtree
				cur = cur->left;
			}
			else {
				// search its right subtree
				count += 1+cur->count;
				cur = cur->right;
			}
		}
		return count;
	}


	 vector<int> countOfSmallerNumberII(vector<int> &A) {
	 	vector<int> res;
	 	if(A.size() == 0) {
	 		return res;
	 	}
        
	 	//res.push_back(0);
	 	for(int i=0; i<A.size(); i++) {
	 		update(A[i]);
	 		res.push_back(query(A[i]));
	 	}
	 	
	 	return res;
	}
// solution 1: segment tree
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
     
    class SegmentTreeNode {
        public: 
            int start;
            int end;
            int count;
            
            SegmentTreeNode *left;
            SegmentTreeNode *right;
            SegmentTreeNode(int s, int e, int c) {
                start = s;
                end = e;
                count = c;
                
                left = right = NULL;
            }
    };
     
    // build up a tree from 0~10,000
    // lo = 0, hi = 10,000
    // count: initialize to 0
    SegmentTreeNode* build(int lo, int hi) {
        if(lo > hi) {
            return NULL;
        }
        if(lo == hi) {
            return new SegmentTreeNode(lo, hi, 0);
        }
        
        int mid = (lo+hi)/2;
        SegmentTreeNode *cur = new SegmentTreeNode(lo, hi, 0);
        cur->left = build(lo, mid);
        cur->right = build(mid+1, hi);
        return cur;
    }
    
    void insert(SegmentTreeNode* root, int ind, int val) {
        if(!root) {
            return;
        }
        
        int s = root->start;
        int e = root->end;
        
        if(ind == s && ind == e) {
            root->count+=val;
            return;
        }
        if(ind < s || ind > e) {
            return;
        }
        
        int mid = (s+e)/2;
        if(ind <= mid) {
            insert(root->left, ind, val);
        }
        else {
            insert(root->right, ind, val);
        }
        root->count = root->left->count+root->right->count;
    }
    
    int query(SegmentTreeNode* root, int lo, int hi) {
        if(root == NULL) {
            return 0;
        }
        if(lo > hi) {
            return 0;
        }
        int s = root->start;
        int e = root->end;
        if(e <= hi && lo <= s) {
            return root->count;
        }
        
        if(s > hi || e < lo) {
            return 0;
        }
        
        int mid = (s+e)/2;
        int left=0, right=0;
        if(lo <= mid) {
            if(hi > mid) {
                left = query(root->left, lo, mid);
            }
            else {
                left = query(root->left, lo, hi);
            }
        }
        if(hi > mid) {
            if(lo < mid) {
                right = query(root->right, mid+1, hi);
            }
            else {
                right = query(root->right, lo, hi);
            }
        }
        return left + right;
        
    }
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> res;
        if(A.size() == 0) {
            return res;
        }
        SegmentTreeNode* root = build(0, 10000);
        
        for(int i=0; i<A.size(); i++) {
            insert(root, A[i], 1);
            if(A[i] > 0) {
                res.push_back(query(root, 0, A[i]-1));
            }
            else {
                res.push_back(0);
            }
        }
        return res;
        
    }
};