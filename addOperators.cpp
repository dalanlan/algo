/*

Leetcode:
https://leetcode.com/problems/expression-add-operators/

Given a string that contains only digits 0-9 and a target value,
return all possibilities to add binary operators (not unary) +, -, or * 
between the digits so they evaluate to the target value.


*/

class Solution {
public:

    
    void addOperators(vector<string>& res, string path, string num, int target, long now, int index, long lastTry) {
        if(index == num.length()) {
            if(target == now) {
                res.push_back(path);
            }    
        }
        else {
            for(int i=index; i<num.length(); i++) {
                if(i != index && num[index] == '0') {
                    break;
                }
                string tmp = num.substr(index,i-index+1);
                long cur = stol(tmp);
                
                if(index == 0) {
                    addOperators(res, to_string(cur), num, target, cur, i+1, cur);
                }
                else {
                    addOperators(res, path + "+" + tmp, num, target, now+cur, i+1, cur);
                    addOperators(res, path + "-" + tmp, num, target, now-cur, i+1, -cur);
                    addOperators(res, path + "*" + tmp, num, target, now - lastTry + lastTry*cur, i+1, lastTry*cur);
                }
                
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) {
            return res;
        }
        
        addOperators(res, "", num, target, 0, 0, 0);
        
        return res;
    }
};