
/*
LintCode: heapify
http://www.lintcode.com/zh-cn/problem/heapify/
*/

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for(int i=A.size()/2-1; i>=0; i--) {
            shiftDown(i, A);
        }
    }
    
    void shiftDown(int index, vector<int> &A) {
        int sz = A.size();
        int left = 2*index+1;
        int right = 2*index+2;
        
        while(left < sz || right < sz) {
            int leftVal = left<sz?A[left]:INT_MAX;
            int rightVal = right<sz?A[right]:INT_MAX;
        
            int next = (leftVal <= rightVal?left:right);
            if(A[index] > A[next]) {
                swap(A[index], A[next]);
                index = next;
                left = index*2+1;
                right = index*2+2;
            }
            else {
                break;
            }
        }
        
    }
};