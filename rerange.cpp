
/*
LintCode: interleaving positive and negative numbers
给出一个含有正整数和负整数的数组，重新排列成一个正负数交错的数组。
http://www.lintcode.com/zh-cn/problem/interleaving-positive-and-negative-numbers/
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int pos=0, neg=0;

        for(int i=0; i<A.size(); i++) {
        	if(A[i] > 0) {
        		pos++;
        	}
        	else {
        		neg++;
        	}
        }

        int posIndex=0, negIndex=1;
        if(neg > pos) {
        	negIndex = 0;
        	posIndex = 1;
        }

        
       	while(posIndex < A.size() && negIndex < A.size()) {
       		while(posIndex < A.size() && A[posIndex] > 0) {
       			posIndex += 2;
       		}
       		while(negIndex < A.size() && A[negIndex] < 0) {
       			negIndex += 2;
       		}
       		if(posIndex < A.size() && negIndex < A.size()) {
       			swap(A[posIndex], A[negIndex]);
       			posIndex+=2;
       		    negIndex+=2;
       		}
       		
       	}
       	

    }
};