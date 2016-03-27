
/*
LeetCode:serialize and deserialize binary tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "[]";
        }
        string res="[" + to_string(root->val);
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(!tmp->left) {
                res += ",#";
            }
            else {
                res += ","+to_string(tmp->left->val);
                q.push(tmp->left);
            }
            if(!tmp->right) {
                res += ",#";
            }
            else {
                res += ","+to_string(tmp->right->val);
                q.push(tmp->right);
            }
            
        }
        // get rid of extra "#"
        int pos = res.length()-1;
        while(pos >= 0 && res[pos] == '#') {
            pos -= 2;
        }
        res = res.substr(0, pos+1);
        res+="]";
        return res;
    }
    
    vector<string> split(string data, char deli) {
        vector<string> res;
        string token;
        stringstream ss(data);
        
        while(getline(ss, token, deli)) {
            res.push_back(token);
        }
        
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") {
            return NULL;
        }
        string daTa = data.substr(1, data.length()-2);
        
        vector<string> res = split(daTa, ',');
        
        TreeNode* root = new TreeNode(stoi(res[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        int count = 1;
        int sz = res.size();
        
        while(!q.empty() && count<sz) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if(count<sz&&res[count] != "#") {
                tmp->left = new TreeNode(stoi(res[count]));
                q.push(tmp->left);
            }
            count++;
            
            if(count<sz&&res[count] != "#") {
                tmp->right = new TreeNode(stoi(res[count]));
                q.push(tmp->right);
            }
            count++;
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));