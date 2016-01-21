
/*

LintCode 82: Single number

Given [1,2,2,1,3,4,3], return 4;

*/
class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
    	int res=0;
    	for(int i=0;i<A.size();i++) {
    		res ^= A[i];
    	}
    	return res;
    }
};
