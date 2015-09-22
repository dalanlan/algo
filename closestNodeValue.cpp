TreeNode* closestNode(TreeNode* root, double target)
    {
        TreeNode* pNode = NULL,*lClosest =NULL,*rClosest=NULL;
        
        double diff = abs(root->val - target);
        double lDiff=0,rDiff=0;
        
        if(root->val > target && root->left)
        {
            lClosest = closestNode(root->left,target);
            lDiff = abs(lClosest->val-target);
        }
        if(root->val < target && root->right)
        {
            rClosest = closestNode(root->right,target);
            rDiff = abs(rClosest->val-target);
        }
        if(lClosest != NULL || rClosest != NULL)
        {
            if(lClosest != NULL && rClosest != NULL)
            {
                if(lDiff<rDiff && lDiff < diff)
                    pNode = lClosest;
                if(rDiff<lDiff && rDiff < diff)
                    pNode = rClosest;
                else
                    pNode = root;
            }
            else if(lClosest != NULL)
            {
                if(lDiff < diff)
                    pNode = lClosest;
                else
                    pNode = root;
            }
            else if(rClosest != NULL)
            {
                if(rDiff < diff)
                    pNode = rClosest;
                else
                    pNode = root;
            }
           
        }
        else
            pNode = root;
            
        return pNode;
    }
    int closestValue(TreeNode* root, double target) {
    return closestNode(root,target)->val;
    }