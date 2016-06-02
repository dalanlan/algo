
/*
Leetcode: count of smaller numbers after self
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/

class Solution {
public:
    class binaryTreeNode {
        public:
        int val;
        int count;
        binaryTreeNode* left;
        binaryTreeNode* right;
        binaryTreeNode(int v) {
            val = v;
            count = 0;
            left = right = NULL;
        }
    }; 
    binaryTreeNode *root = NULL;
    
    void insert(int v) {
        if(root == NULL) {
            root = new binaryTreeNode(v);
            return;
        }
        binaryTreeNode *cur = root;
        while(cur) {
            // put it on the left subtree
            if(cur->val > v) {
                cur->count++;
                if(!cur->left) {
                    cur->left = new binaryTreeNode(v);
                    return;
                }
                else {
                    cur = cur->left;
                }
            }
            // put it on the right subtree
            else {
                if(!cur->right) {
                    cur->right = new binaryTreeNode(v);
                    return;
                }
                else {
                    cur = cur->right;
                }
            }
        }
    }
    int query(int v) {
        int c = 0;
        binaryTreeNode *cur = root;
        
        while(cur) {
            if(cur->val == v) {
                c += cur->count;
                break;
            }
            else if(cur->val > v) {
                cur = cur->left;
            }
            else {
                c+=1+cur->count;
                cur = cur->right;
            }
        }
        return c;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0) {
            return res;
        }
        res.push_back(0);
        for(int i=nums.size()-2; i>=0; i--) {
            insert(nums[i+1]);
            res.insert(res.begin(),query(nums[i]));
        }
        return res;
    }
};
// segment tree is fine though, not so very right exactly


/* solution new : http://www.cnblogs.com/grandyang/p/5078490.html

*/

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp;
        vector<int> res(nums.size(), 0);
        
        for(int i=nums.size()-1; i>=0; i--) {
            int lo = 0, hi = tmp.size();
            while(lo < hi) {
                int mid = (lo+hi)/2;
            
                if(nums[i] > tmp[mid]) {
                    lo = mid+1;
                }
                else {
                    hi = mid;
                }
            }
            res[i] = hi;
            tmp.insert(tmp.begin()+hi, nums[i]);
        }
        return res;
    }


// solution 1p: just rewrite the code

class Solution {
public:

    class BinaryTreeNode {
        public:
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        int val;
        int count;
        BinaryTreeNode(int v) {
            val = v;
            count = 0;
            left = right = NULL;
        }
        
    };
    BinaryTreeNode *root=NULL;
    
    void insert(int v) {
        if(!root) {
            root = new BinaryTreeNode(v);
        }
        else {
            BinaryTreeNode *cur = root;
            while(cur) {
                if(v < cur->val) {
                    cur->count++;
                    if(cur->left) {
                        cur = cur->left;
                    }
                    else {
                        cur->left = new BinaryTreeNode(v);
                        break;
                    }
                }
                else {
                    if(!cur->right) {
                        cur->right = new BinaryTreeNode(v);
                        break;
                    }
                    else {
                        cur = cur->right;
                    }
                }
            }
        }
    }
    
    int query(int v) {
        int res = 0;
        BinaryTreeNode *cur = root;
        while(cur) {
            if(v > cur->val) {
                res += 1+cur->count;
                cur = cur->right;
            }
            else if(v == cur->val) {
                res += cur->count;
                break;
            }
            else {
                cur = cur->left;
            }
        }
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<int> res = {0};
        
        for(int i=nums.size()-2; i>=0; i--) {
            insert(nums[i+1]);
            res.insert(res.begin(), query(nums[i]));
        }
        return res;
    }
};


// solution X: another solution

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> tmp;
        for(int i=nums.size()-1; i>=0; i--) {
            int d = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), nums[i]));
            res[i] = d;
            tmp.insert(tmp.begin()+d, nums[i]);
        }
        return res;
    }