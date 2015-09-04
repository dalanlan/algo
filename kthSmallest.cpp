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


