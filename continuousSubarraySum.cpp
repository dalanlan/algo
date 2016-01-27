
/*
LintCode : continuous subarray sum

http://www.lintcode.com/zh-cn/problem/continuous-subarray-sum/

*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        if(A.size() == 1) {
            return vector<int>(2, A[0]);
        }
        
        int res = A[0], maxx = A[0];
        int lo = 0, hi = 0, loR = 0, hiR = 0;
        for(int i=1; i< A.size(); i++) {
            if(maxx + A[i] > A[i]) {
                hi = i;
                maxx += A[i];
            }
            else {
                lo = i;
                hi = i;
                maxx = A[i];
            }
            
            if(maxx > res) {
                loR = lo;
                hiR = hi;
                res = maxx;
            }
            
        }
        return vector<int>{loR, hiR};
        
        
    }
};