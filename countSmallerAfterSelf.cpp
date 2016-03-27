
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