

//Minimum Depth of  Binary Tree

//BFS

bool isLeaf(TreeNode *root)
{
	return (root->left==NULL && root->right ==NULL);
}
int minDepth(TreeNode* root) 
{
	int depth = 0;
	queue<TreeNode*> v;

	v.push_back(root);

	while(!v.empty())
	{	
		TreeNode* tmp = v.front();
		if(isLeaf(tmp))
			return depth+1;

		else{
			if(tmp->left !=NULL) v.push_back(tmp->left);
			if(tmp->right != NULL) v.push_back(tmp->right);

			depth++;
			v.pop_front();
		}
	}


}


// WA: [1,2,3,4,5];
//Expected: 2 ?? 
// How come 
