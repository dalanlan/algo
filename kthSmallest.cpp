// solution 1
// global var vector<int>
vector<int> data;
int kthSmallest(TreeNode* root, int k) 
{
    
    if(data.size()==k)
        return data[k-1];
        
    if(root->left)
        kthSmallest(root->left,k);
    
    data.push_back(root->val);
    
        
    if(root->right)
        kthSmallest(root->right,k);
        
    return data[k-1];
    
}


// solution 2
// global var res,order
int res, order=0;

void dfs(TreeNode* root,int k)
{
    if(root->left)
        dfs(root->left,k);
    order++;
    if(order == k)
    {
        res = root->val;
        return;
    }
    if(root->right)
        dfs(root->right,k);
}

int kthSmallest(TreeNode* root, int k)
{
    dfs(root,k);
    return res;
}


// solution 3: flatten solution 
// I think my mind is kinda messy

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
void flatten(vector<int>& res, TreeNode* root) {
    
    TreeNode* tmp = root;
    stack<TreeNode*> stk;
    while(!stk.empty() || tmp) {
        if(tmp) {
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
    
    return;
    
}
// flatten into a vector 
// and find out the kth index
int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    flatten(res, root);
    return res[k-1];
}
};

