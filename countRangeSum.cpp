/*
Leetcode: count of range sum
https://leetcode.com/problems/count-of-range-sum/
*/


class BinaryTreeNode {
    public:
    int val;
    int equal;   // equal
    int less;    // less
    int greater; // greater
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int v) {
        val = v;
        equal = 1;
        less = greater = 0;
        left = right = NULL;
    }
     
};
    void insert(BinaryTreeNode *root, int v) {
        if(!root) {
            root = new BinaryTreeNode(v);
            
        }
        else {
            if(root->val == v) {
                root->equal++;
         
            }
            else if(root->val > v) {
                root->less++;
                insert(root->left, v);
            }
            else {
                root->greater++;
                insert(root->right, v);
            }
        }
    }
    int countLarger(BinaryTreeNode *root, int upper) {
        if(!root) {
            return 0;
        }
        if(root->val > upper) {
            return countLarger(root->left, upper) + root->equal + root->greater;
        }
        if(root->val == upper) {
            return root->greater;
        }
        return countLarger(root->right, upper);
        
    }
    int countSmaller(BinaryTreeNode *root, int lower) {
        if(!root) {
            return 0;
        }
        
        if(root->val == lower) {
            return root->less;
        }
        if (root->val > lower) {
            return countSmaller(root->left, lower);
        }
        
        return root->less + root->equal + countSmaller(root->right, lower);
        
    }
    int countRangeSum(BinaryTreeNode* root, int lower, int upper) {
        int total = root->equal + root->less + root->greater;
        int less = countSmaller(root, lower);
        int greater = countLarger(root, upper);
        return total - less - greater;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) {
            return 0;
        }
        // foreach sum[i], find out  lower <= sum[i]-sum[?] <= upper, aka. sum[?]+lower <= sum[i] <= upper + sum[?], that is
        // s[i]-upper<= sum[?] <= lower - s[i]
        int res = 0;
    
        // nums[0] = sum[1]-sum[0];
        // nums[i] = sum[i+1] - sum[i];
        vector<int> sum{0};
        for(int i=0; i<nums.size(); i++) {
            sum.push_back(sum[i]+nums[i]);
        }
        for(int s:sum) {
            cout<<s<<endl;
        }
        
        BinaryTreeNode* root = new BinaryTreeNode(sum[0]);
        for(int i=1; i<sum.size(); i++) {
            res += countRangeSum(root,sum[i]-upper, lower-sum[i]);
            insert(root, sum[i]);
        }
        
        return res;
    }