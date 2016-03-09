
/*
LintCode: expression tree build
http://www.lintcode.com/zh-cn/problem/expression-tree-build/
*/

/*
borrow idea from https://lefttree.gitbooks.io/leetcode/content/dataStructure/maxTree.html
https://lefttree.gitbooks.io/leetcode/content/dataStructure/expressionTreeBuild.html
*/

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    class TreeNode {
        public:
	string s;
	int val;
	ExpressionTreeNode *node;
	// do we need this or not?
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v, string ss) {
		s = ss;
		val = v;

		node = new ExpressionTreeNode(ss);
		left = right = NULL;
	}
};

int getBase (string s, int base) {
	if(s == "+" || s == "-") {
		return base+1;
	}
	if(s == "*" || s == "/") {
		return base+2;
	}
	return INT_MAX;
}
TreeNode* buildTree(vector<string> &expression) {
	if(expression.size() == 0) {
		return NULL;
	}
	stack<TreeNode*> stk;
	int base = 0;

	for(int i=0; i<expression.size(); i++) {
		string cur = expression[i];
		if(cur == "(") {
			base += 10;
			continue;
		}
		else if(cur == ")") {
			base -= 10;
			continue;
		}
		else {
			int val = getBase(cur, base);
			TreeNode *tmp = new TreeNode(val, cur);
			while(!stk.empty() && val <= stk.top()->val) {
				tmp->left = stk.top();
				stk.pop();
			}
			if(!stk.empty()) {
				stk.top()->right = tmp;
			}
			stk.push(tmp);

		}
	}
    if(stk.empty()) {
        return NULL;
    }
	while(stk.size() > 1) {
		stk.pop();
	}
	return stk.top();
}

ExpressionTreeNode* copyNode(TreeNode* root) {
	if(root == NULL) {
		return NULL;
	}
	root->node->left = copyNode(root->left);
	root->node->right = copyNode(root->right);
	return root->node;
}
ExpressionTreeNode* build(vector<string> &expression) {
	
	TreeNode* root = buildTree(expression);
	return copyNode(root);
}
};