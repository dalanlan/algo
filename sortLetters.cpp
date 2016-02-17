
/*
LintCode: sort letters by case
http://www.lintcode.com/zh-cn/problem/sort-letters-by-case/
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int lo=0, hi=letters.length()-1;
        while(lo < hi) {
            while(letters[lo] >= 97) lo++;
            while(letters[hi] <= 90) hi--;
            if(lo < hi) {
                swap(letters[lo], letters[hi]);
                
            }
        }
    }
};
