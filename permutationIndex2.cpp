
/*
LintCode: permutation index
http://www.lintcode.com/zh-cn/problem/permutation-index/
*/

     long long permutationIndex(vector<int>& A) {
         int sz = A.size();
         
         long long fact = 1;
         long long res = 0;
         for(int i=sz-1; i>=0; i--) {
             int count = 0;
             for(int j=i+1; j<sz; j++) {
                 if(A[i] > A[j]) {
                     count++;
                 }
             }
             res += fact*count;
             fact *= sz-i;
         }
         return ++res;
     }