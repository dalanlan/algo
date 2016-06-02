/*
leetcode: count of range sum
https://leetcode.com/problems/count-of-range-sum/

Given an integer array nums, return the number of range sums that 
lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums 
between indices i and j (i ≤ j), inclusive.

*/

class Solution {
public:

class BinaryTreeNode {
    public:
    long val;
    
    int equal;   // equal
    int less;    // less
    int greater; // greater
    
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(long v) {
        val = v;
        equal = 1;
        less = greater = 0;
        left = right = NULL;
    }
     
};
    BinaryTreeNode* insert(BinaryTreeNode *root, long v) {
        if(!root) {
            root = new BinaryTreeNode(v);
            
        }
        else {
            if(root->val == v) {
                root->equal++;
        
            }
            else if(root->val > v) {
                root->less++;
                root->left = insert(root->left, v);
            }
            else {
                root->greater++;
                root->right = insert(root->right, v);
            }
        }
        return root;
    }
    int countLarger(BinaryTreeNode *root, long val) {
        if(!root) {
            return 0;
        }
        if(root->val > val) {
            return countLarger(root->left, val) + root->equal + root->greater;
        }
        if(root->val == val) {
            return root->greater;
        }
        return countLarger(root->right, val);
        
    }
    int countSmaller(BinaryTreeNode *root, long val) {
        if(!root) {
            return 0;
        }
        
        if(root->val == val) {
            return root->less;
        }
        if (root->val > val) {
            return countSmaller(root->left, val);
        }
        
        return root->less + root->equal + countSmaller(root->right, val);
        
    }
    
    
    // deal with overflow tricks
    int countRangeSum(BinaryTreeNode* root, long lower, long upper) {
        int total = root->equal + root->less + root->greater;
        int less = countSmaller(root, lower);
        int greater = countLarger(root, upper);
        
        return total - less - greater;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) {
            return 0;
        }
        // foreach sum[i], find out  lower <= sum[i]-sum[?] <= upper, 
        // aka. sum[?]+lower <= sum[i] <= upper + sum[?], that is
        // s[i]-upper<= sum[?] <=  s[i] - lower, find out the sum of number of s[?]
        int res = 0;
    
        // nums[0] = sum[1]-sum[0];
        // nums[i] = sum[i+1] - sum[i];
        vector<long> sum{0};
        for(int i=0; i<nums.size(); i++) {
            sum.push_back(sum[i]+nums[i]);
        }
        
        
        BinaryTreeNode* root = new BinaryTreeNode(sum[0]);
        for(int i=1; i<sum.size(); i++) {
            res += countRangeSum(root,sum[i]-upper, sum[i]-lower);
            insert(root, sum[i]);
        }
        
        return res;
    }
};