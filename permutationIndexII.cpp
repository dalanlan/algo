
/*
LintCode: permutation index ii
http://www.lintcode.com/zh-cn/problem/permutation-index-ii/

*/

//http://www.cnblogs.com/EdwardLiu/p/5104409.html

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int sz = A.size();

        long long res = 0;
        long long fact = 1;
        long long multi = 1;
        if(sz == 0) {
            return res;
        }
        unordered_map<int,int> map;
        for(int i=sz-1; i>=0; i--) {
             if(map.count(A[i])) {
                 map[A[i]]++;
                 multi *= map[A[i]];
             }
             else {
                 map[A[i]] = 1;
             }
            
            
            int count = 0;
            for(int j=i+1; j<sz; j++) {
                if(A[i] > A[j]) {
                    count++;
                }
            }
            res += fact*count/multi;
            fact *= sz-i;
        }
        return ++res;
        
        
    }
};


// solution 2: a shorted version 
    long long permutationIndexII(vector<int>& A) {
        
        long long fact = 1;
        int multi = 1;
        
        long long res = 0;
        
        unordered_map<int, int> map;
        
        for(int i=A.size()-1; i>=0; i--) {
            map[A[i]]++;
            multi*=map[A[i]];
            int count = 0;
            for(int j=i+1; j<A.size(); j++) {
                if(A[i] > A[j]) {
                    count++;
                }
            }
            res += fact*count/multi;
                fact *= A.size()-i;
        }
            return ++res;

    }