
/*
LintCode : Compare Strings

比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是大写字母.
*/


class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        unordered_map<char, int> myMap;
        for(int i=0;i<A.length();i++) {
            if(myMap.find(A[i]) == myMap.end()) {
                myMap[A[i]]=1;
            }
            else {
                myMap[A[i]]++;
            }
        }
        for(int i=0;i<B.length();i++) {
            if(myMap.find(B[i]) == myMap.end()) {
                return false;
            }
            else {
                myMap[B[i]]--;
                if(myMap[B[i]] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
