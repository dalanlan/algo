vector<string> binaryTreePaths(TreeNode* root) 
{
    
    vector<string> res;
    string path="";
    
    if(root == NULL)
        return res;
    dfs(res, path, root);
    return res;
}

void dfs(vector<string> &res, string path, TreeNode* root)
{
    if(path.empty())
        path += to_string(root->val);
    else
        path += "->"+to_string(root->val);
        
    if (root->left == NULL && root->right == NULL)
        res.push_back(path);
    

    if (root->left)
        dfs(res,path,root->left);
    if (root->right)
        dfs(res,path,root->right);
}

// Thanks to Xingyu Chen 
// (O^---------------^O)