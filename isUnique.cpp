
/*
LintCode: unique characters
http://www.lintcode.com/zh-cn/problem/unique-characters/

*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
     
     //1. use a map
     //2. in-place sort and compare
     //3. Use prime number mapping
     
    bool isUnique(string &str) {
        unordered_map<char, int> myMap;
        for(int i=0;i<str.length();i++) {
            if(myMap.find(str[i]) == myMap.end()) {
                myMap[str[i]]=i;
            }
            else {
                return false;
            }
        }
        return true;
    }
};