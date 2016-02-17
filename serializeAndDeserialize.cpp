
/*
LintCode: binary tree serialization
http://www.lintcode.com/zh-cn/problem/binary-tree-serialization/
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        
        string res;
        if(root == NULL) {
            return "{}";
        }
        queue<TreeNode*> q;
        q.push(root);
        res += "{"+to_string(root->val);
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            
            if(tmp->left) {
                q.push(tmp->left);
                res += ","+to_string(tmp->left->val);
            }
            else {
                res += ",#";
            }
            if(tmp->right) {
                q.push(tmp->right);
                res += ","+to_string(tmp->right->val);
            }
            else {
                res += ",#";
            }
        }
        //cout<<res<<endl;
        int pos = res.length()-1;
        while(pos >= 0 && res[pos]=='#') {
            pos-=2;
        }
        res = res.substr(0, pos+1);
        res += "}";
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    
    vector<string> split(string data, char del) {
        vector<string> res;
        string tok;
        stringstream ss(data);
        while(getline(ss, tok, del)) {
            res.push_back(tok);
        }
        return res;
    }
    
    TreeNode *deserialize(string data) {
        // write your code here
        if(data == "{}") {
            return NULL;
        }
        vector<string> res = split(data.substr(1, data.length()-2), ',');
        TreeNode *root=new TreeNode(stoi(res[0]));
        
        // bool isLeft = true;
        queue<TreeNode*> q;
        q.push(root);
    
        int count = 1;
        int sz = res.size(); 
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if(count < sz) {
                if(res[count] == "#") {
                    tmp->left = NULL;    
                }
                else {
                    tmp->left = new TreeNode(stoi(res[count]));
                    q.push(tmp->left);
                }
                count++;
            }
            if(count < sz) {
                if(res[count] == "#") {
                    tmp->right = NULL;
                }
                else {
                    tmp->right = new TreeNode(stoi(res[count]));
                    q.push(tmp->right);
                }
                count++;
            }
            
        }
        return root;