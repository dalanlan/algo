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