

//Same Tree 
//Check if they are equal or not.

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if( !p && !q )
		return true;
	if(p && !q)
		return false;
	if( !p && q)
		return false;

	if(p->val == q->val)
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	else return true;
}