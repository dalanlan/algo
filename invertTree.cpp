    void invert(TreeNode* root) {
        if(root == NULL)
            return;
        invert(root->left);
        invert(root->right);
        swap(root->left,root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
