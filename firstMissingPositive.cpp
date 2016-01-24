
/*
LintCode : find first missing positive integer

Given an unordered array of integers, find out the
first missing positive index.
http://www.lintcode.com/zh-cn/problem/first-missing-positive/
*/


class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        unordered_map<int, int> myMap;

        for(int i=0; i<A.size(); i++) {
        	//val, index
        	myMap[A[i]] = i;
        }
        for(int i=1; i<A.size();i++) {
        	if(myMap.find(i) == myMap.end()) {
        		return i;
        	}
        }
        return A.size()+1;
    }
};


int firstMissingPositive(vector<int> A) {
	// i+1 == A[i]
	// A[i] == A[A[i]-1]

	int sz = A.size();
	for(int i=0; i<sz; i++) {
		while(A[i] != i+1 && A[i] >0 && A[i] <=sz) {
			if (A[i] == A[A[i]-1]) {
				break;
			}
			swap(A[i], A[A[i]-1]);
		}
	}
	for(int i=0; i<sz; i++) {
		if(A[i] != i+1) {
			return i+1;
		}
	}
	return sz+1;

}