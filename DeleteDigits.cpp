
/*
LintCode: delete digits
http://www.lintcode.com/zh-cn/problem/delete-digits/
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // use a stack
        // solution: from left to right, 
        // when s[i] >= s[i+1] 
        // delete it
        int len = A.length();
        if(k == 0) {
            return A;
        }
        if(k == len) {
            return "";
        }
        
        stack<char> s;
        int count = 0;
        for(int i=0; i<len; i++) {
            char cur = A[i];
            while(count < k && !s.empty() && cur < s.top()) {
                s.pop();
                count++;
            }
            
            if(s.size() < len-k) {
                s.push(cur);
            }
        }
        
        string ans;
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        int pos =0;
        while(ans[pos] == '0') {
            pos++;
        }
        ans = ans.substr(pos);
        return ans;
        
    }
};
