
/*
Lintcode: the smallest difference
http://www.lintcode.com/zh-cn/problem/the-smallest-difference/
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int p1=0, p2=0;
        int res=INT_MAX;
        while(p1 < A.size() && p2 < B.size()){
            res = min(res, abs(A[p1]-B[p2]));
            if(res == 0) {
                return res;
            }
            if(A[p1] < B[p2]) p1++;
            else p2++;
        }
        while(p1 < A.size()) {
            res = min(res, abs(A[p1++]-B[p2]));
            if(res == 0) {
                return res;
            }
        }
        while(p2 < B.size()) {
            res = min(res, abs(A[p1]-B[p2++]));
            if(res == 0) {
                return res;
            }
        }
        return res;
    }
};

    int smallestDifference(vector<int> &A, vector<int> &B) {
	sort(B.begin(), B.end());
	int res = INT_MAX;
	for(int i=0; i < A.size(); i++) {
		int diff = lower_bound(B.begin(), B.end(), A[i])- B.begin();
		res = min(res, abs(A[i]-B[diff]));
		if(diff > 0) {
			res = min(res, abs(A[i]-B[diff-1]));
		}
		if(diff < B.size()-1) {
			res = min(res, abs(A[i]-B[diff+1]));
		}
	}
	return res;
}