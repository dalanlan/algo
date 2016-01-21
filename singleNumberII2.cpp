
/*
LintCode : Single Number II
Given [1,1,2,3,3,3,2,2,4,1], return 4
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int count[32] = {0};

        int res = 0;

        for(int i=0; i<32; i++) {
        	for(int j=0; j<A.size(); j++) {
        		if(A[j]>>i & 1) {
        			count[i]++;
        		}
        	}
        	res |= ((count[i]%3)&1)<<i;
        }
        return res;

    }
};

int singleNumberII(vector<int> &A) {
	int ones=0;
	int twos=0;
	int not_three = 0;
	for(int i=0; i<A.size(); i++) {
		twos |= ones&A[i];
		ones ^= A[i];

		not_three = ~(ones & twos);
		ones &= not_three;
		twos &= not_three;
	}
	return ones;
}