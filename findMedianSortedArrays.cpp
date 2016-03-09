
/*
LintCode: median of two sorted arrays
http://www.lintcode.com/zh-cn/problem/median-of-two-sorted-arrays/
*/

// solution 3: merge sort
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        vector<int> res;
        int sizeA = A.size();
        int sizeB = B.size();
        
        if(sizeA == 0 && sizeB == 0) {
            return INT_MIN;
        }
        if(sizeA == 0) {
            return sizeB%2?B[sizeB/2]:(((double)B[sizeB/2]+(double)B[sizeB/2-1])/2);
        }
        
        if(sizeB == 0) {
            return sizeA%2?A[sizeA/2]:(((double)A[sizeA/2]+(double)A[sizeA/2-1])/2);
        }
        
        int i=0, j=0;
        while(i < sizeA && j < sizeB) {
            if(A[i] <= B[j]) {
                res.push_back(A[i]);
                i++;
            }
            else {
                res.push_back(B[j]);
                j++;
            }
        }
        while(i < sizeA) {
            res.push_back(A[i++]);
        }
        while(j < sizeB) {
            res.push_back(B[j++]);
        }
        
        int sz = res.size();
        
        return (sz%2)?res[sz/2]:((double)res[sz/2] + (double)res[sz/2-1])/2;
    }

// solution 2: binary search 

double findMedianSortedArrays(vector<int> A, vector<int> B) {
	int szA = A.size();
	int szB = B.size();
	if(szA > szB) {
		return findMedianSortedArrays(B, A);
	}

	int lo = 0, hi = szA;
	int halfLen = (szA + szB + 1)/2;

	while(lo <= hi) {
		int i = (lo + hi)/2;
		int j = halfLen-i;

		
		if(i>0 && j < szB && A[i-1] > B[j]) {
			hi = i-1;
		}
		else if (j>0 && i < szA && B[j-i] > A[i]) {
			lo = i+1;
		}
		else {
			// bingo!
			int maxLeft;
			if(i == 0) {
				maxLeft = B[j-1];
			}
			else if(j == 0) {
				maxLeft = A[i-1];
			}
			else {
				maxLeft = max(A[i-1], B[j-1]);
			}
			if((szA+szB)%2) {
				return maxLeft;
			}
			int minRight;
			if(i==szA) {
				minRight = B[j];
			}
			else if(j == szB) {
				minRight = A[i];
			}
			else {
				minRight = min(A[i], B[j]);
			}
			return (maxLeft + minRight)/2.0;

		}
	}
}


// solution 1: two priority_queue
// stupid solution
// (m+n)*O(log(m+n))
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int sizeA = A.size();
        int sizeB = B.size();
        
        if(sizeA == 0 && sizeB == 0) {
            return INT_MIN;
        }
        if(sizeA == 0) {
            return sizeB%2?B[sizeB/2]:(((double)B[sizeB/2]+(double)B[sizeB/2-1])/2);
        }
        
        if(sizeB == 0) {
            return sizeA%2?A[sizeA/2]:(((double)A[sizeA/2]+(double)A[sizeA/2-1])/2);
        }
        
        // max-heap 
        priority_queue<int> maxPQ;
        // min-heap 
        priority_queue<int, vector<int>, greater<int>> minPQ;
        
        maxPQ.push(min(A[0], B[0]));
        minPQ.push(max(A[0], B[0]));
        // A, B is sorted
        
        for(int i=1; i<=sizeA/2; i++) {
            maxPQ.push(A[i]);
        }
        for(int i=sizeA/2+1; i<sizeA; i++) {
            minPQ.push(A[i]);
        }
        
        
        
        // for(int i=1; i<sizeA; i++) {
        //     int maxHead = maxPQ.top(); // less
        //     int minHead = minPQ.top(); // greater
        //     if(A[i] <= maxHead) {
        //         if(maxPQ.size() <= minPQ.size()) {
        //             maxPQ.push(A[i]);
        //         }
        //         else {
        //             maxPQ.pop();
        //             minPQ.push(maxHead);
        //             maxPQ.push(A[i]);
        //         }
        //     }
        //     else if(A[i] >= minHead) {
        //         if(minPQ.size() <= maxPQ.size()) {
        //             minPQ.push(A[i]);
        //         }
        //         else {
        //             minPQ.pop();
        //             minPQ.push(A[i]);
        //             maxPQ.push(minHead);
        //         }
        //     }
        //     else {
        //         if(minPQ.size() <= maxPQ.size()) {
        //             minPQ.push(A[i]);
        //         }
        //         else {
        //             maxPQ.push(A[i]);
        //         }
        //     }
        // }
        
        
        for(int i=1; i<sizeB; i++) {
            int maxHead = maxPQ.top(); // less
            int minHead = minPQ.top(); // greater
            if(B[i] <= maxHead) {
                if(maxPQ.size() <= minPQ.size()) {
                    maxPQ.push(B[i]);
                }
                else {
                    maxPQ.pop();
                    minPQ.push(maxHead);
                    maxPQ.push(B[i]);
                }
            }
            else if(B[i] >= minHead) {
                if(minPQ.size() <= maxPQ.size()) {
                    minPQ.push(B[i]);
                }
                else {
                    minPQ.pop();
                    minPQ.push(B[i]);
                    maxPQ.push(minHead);
                }
            }
            else {
                if(minPQ.size() <= maxPQ.size()) {
                    minPQ.push(B[i]);
                }
                else {
                    maxPQ.push(B[i]);
                }
            }
        }
        
        int szMinPQ = minPQ.size();
        int szMaxPQ = maxPQ.size();
        if((sizeA+sizeB)%2) {
            //odd
            return szMinPQ>szMaxPQ?minPQ.top():maxPQ.top();
        }
        else {
            
            return ((double)minPQ.top()+(double)maxPQ.top())/2;
        }
    }
};
