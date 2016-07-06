
/*
LeetCode: valid number
https://leetcode.com/problems/valid-number/
*/

class Solution {
public:
    bool isNumber(string s) {
        bool dot = false;
        bool expr = false;
        bool numeric = false;
        bool numAfterE = true;
        
        
        int i=0;
        while(i<s.size() && s[i] == ' ') {
            i++;
        }
        int j=s.size()-1;
        while(j>=0 && s[j] == ' ') {
            j--;
        }
        int pos = i;
        while(i<=j) {
            
            if(!isdigit(s[i])) {
                if(s[i]== '.') {
                    if(dot || expr) { 
                        return false;
                    }
                    dot = true;
                }
                
                else if(s[i] == 'e') {
                    if(expr || !numeric) {
                        return false;
                    }
                        expr = true;
                        numAfterE = false;
                }
                
                else if(s[i] == '-' || s[i] == '+') {
                    if(i != pos && s[i-1] != 'e') {
                        return false;
                    }
                }
                   
                
                else {
                    return false;
                }
            }
            else {
            
                numeric = true;
                numAfterE = true;
            }
            i++;
        }
       
        return numeric && numAfterE;
    }
};