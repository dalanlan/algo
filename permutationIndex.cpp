
/*
LintCode: permutation index
http://www.lintcode.com/zh-cn/problem/permutation-index/
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int sz = A.size();
        
        // fact = (n-1)!
        long fact = 1;
        for(int i=1;i<sz;i++) {
            fact *= i;
        }
        int init = sz-1;
        long long res = 0;
        for(int i=0; i<sz; i++) {
            int count =1;
            for(int j=i+1; j<sz; j++) {
                if(A[i] >= A[j]) {
                    count++;
                }
            }
            res += fact*(count-1);
            if(init != 0) {
                fact /= init;
                init--;
            }
        }
        res ++;
        return res;
        
    }
};