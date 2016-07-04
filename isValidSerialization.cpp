   
   /*
   LeetCode: verify preorder serialization of a binary tree
   https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
   */

    // solution 1: stack
   // https://leetcode.com/discuss/83825/simple-python-solution-using-stack-with-explanation
    vector<string> split(string preorder, char del) {
        vector<string> res;
        stringstream ss(preorder);
        string token;
        while(getline(ss, token, del)) {
            res.push_back(token);
        }
        return res;
    }
    

    bool endWithTwoHash(vector<string>& stk, int count) {
        if(count<2) {
            return false;
        }
        int sz = stk.size();
        return stk[sz-1] == "#" && stk[sz-2] == "#";
        
    }
    
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder, ',');
        vector<string> stk;
        int count=0;
        for(string node : nodes) {
            stk.push_back(node);
            count++;
            
            while(endWithTwoHash(stk, count)) {
                stk.pop_back();
                stk.pop_back();
                if(stk.empty()) {
                    return false;
                }
                stk.pop_back();
                stk.push_back("#");
                count-=2;
            }
        }
        return stk.size() == 1 && stk[0] == "#";
        
    }

    // solution 2: degree
    // https://leetcode.com/discuss/83824/7-lines-easy-java-solution
    bool isValidSerialization(string preorder) {
        
        vector<string> nodes = split(preorder, ',');
        int diff = 1;
        // when a new node comes, we decrease diff by 1
        // root -> will be 0
        // whenever it's not a leaf node, 
        // we increase it by 2
        for(string nod: nodes) {
            if(--diff < 0) {
                return false;
            }
            if(nod != "#") {
                diff += 2;
            }
            
        }
        return diff == 0;
    }