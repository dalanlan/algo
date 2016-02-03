
/*
LintCode: letter combinations of a phone number
http://www.lintcode.com/zh-cn/problem/letter-combinations-of-a-phone-number/#
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
     
    void helper(vector<string> &res, unordered_map<char, vector<string>> &myMap, string path, string s, int index) {
        // s.length() or s.length()-1?
        if(index == s.length()) {
            res.push_back(path);
        }
        else {
        //for(auto &x: myMap[s[index]]) {
           for(int i=0; i<myMap[s[index]].size(); i++)
                helper(res, myMap, path+myMap[s[index]][i], s, index+1);
            }
        }
    
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        
        unordered_map<char, vector<string>> myMap;
        myMap['1']=vector<string>{};
        myMap['2']=vector<string>{"a","b","c"};
        myMap['3']=vector<string>{"d","e","f"};
        myMap['4']=vector<string>{"g","h","i"};
        myMap['5']=vector<string>{"j","k","l"};
        myMap['6']=vector<string>{"m","n","o"};
        myMap['7']=vector<string>{"p","q","r","s"};
        myMap['8']=vector<string>{"t","u","v"};
        myMap['9']=vector<string>{"w","x","y","z"};
        myMap['0']=vector<string>{};
        
        string path;
        helper(res, myMap, path, digits, 0);
        return res;
    }
};