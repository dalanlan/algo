// solution 1: timeout 
// dfs
int count=0;
void dfs(TreeNode* root)
{
    if(root!=NULL)
        count++;
    if(root->left)
        dfs(root->left);
    if(root->right)
        dfs(root->right);
}
int countNodes(TreeNode* root) {
    if(root==NULL)
        return count;
    dfs(root);
    
    return count;
}
    
// solution 2: AC
// recursive: finally you will get a full binary tree 
int countNodes(TreeNode* root) {

    if(root==NULL)
        return 0;
    int hl=0,hr=0;
    TreeNode *left= root,*right=root;
    while(left){hl++;left=left->left;}
    while(right){hr++;right=right->right;}
    if(hl==hr)
        return (1<<hl)-1;
    else
        return 1+countNodes(root->left)+countNodes(root->right);

}