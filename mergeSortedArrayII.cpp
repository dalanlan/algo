
/*
LintCode: merge sorted array ii
http://www.lintcode.com/zh-cn/problem/merge-sorted-array-ii/
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int i=0, j=0;
        int aLen = A.size(), bLen = B.size();
        
        vector<int> res;
        while(i < aLen && j < bLen) {
            if(A[i] <= B[j]) {
                res.push_back(A[i]);
                i++;
            }
            else {
                res.push_back(B[j]);
                j++;
            }
        }
        while(i < aLen) {
            res.push_back(A[i++]);
        }
        while(j < bLen) {
            res.push_back(B[j++]);
        }
        return res;
    }
};