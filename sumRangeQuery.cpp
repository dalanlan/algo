// Range Sum Query
// The trick is that we need to update the value 
// every now and then
// Tags: Segment Tree, Binary Indexed Tree


// My solution: Time Exceed 
    vector<int> sum;
    vector<int> tmp;
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            return;
        sum.push_back(nums[0]); // sums[0] = nums[0]
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            sum.push_back(sum[i-1] + nums[i]);
            tmp.push_back(nums[i]);
        }
        
    }

    void update(int i, int val) {
        for(int index=i;index<sum.size();index++) {
            sum[index] += val-tmp[i]; // 
        }
        tmp[i] = val;
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return sum[j];
        return sum[j]-sum[i-1];
    }


// AC 
// https://leetcode.com/discuss/70520/java-organized-segment-tree-solution-which-easy-understand
// struct treeNode
struct treeNode {
    int start;
    int end;
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int s, int e):start(s),end(e){}
};

treeNode* root;

treeNode* constructTree(vector<int>& nums, int start, int end) {
    if(nums.size() == 0 || start > end) {
        return NULL;
    }
    treeNode* root = new treeNode(start, end);
    if(start == end) {
        root->val = nums[start];
        return root;
    }
    int mid = start + (end-start)/2;
    root->left = constructTree(nums, start, mid);
    root->right = constructTree(nums, mid+1, end);
    root->val = root->left->val + root->right->val;
    return root;
}

NumArray(vector<int>& nums) {
    root = constructTree(nums, 0, nums.size()-1);
}

void updateUtil(treeNode* root, int i, int val) {
    if(root->start == root->end) {
        root->val = val;
        return;
    }

    int mid = root->start + (root->end - root->start)/2;
    if(i <= mid) {
        updateUtil(root->left, i, val);
    }
    else {
        updateUtil(root->right, i, val);
    }
    root->val = root->left->val + root->right->val;

}

void update(int i, int val) {
    updateUtil(root, i, val);    
}

int sumRangeUtil(treeNode* root, int i, int j) {
    if(root->start == i && root->end == j) {
        return root->val;
    }
    int mid = root->start + (root->end - root->start)/2;
    if(j <= mid) {
        return sumRangeUtil(root->left, i, j);
    }
    if(i >= mid + 1) {
        return sumRangeUtil(root->right, i, j);
    }
    return sumRangeUtil(root->left, i, mid) + sumRangeUtil(root->right, mid+1, j);


}
int sumRange(int i, int j){
    return sumRangeUtil(root, i, j);    
}

// AC 2???
// Segment tree: http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
// Using array to store node sum
// It can wait

int sum[];
NumArray(vector<int>& nums) {
}

void update(int i, int val) {

}
int sumRange(int i, int j) {

}