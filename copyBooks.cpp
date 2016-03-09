
/*
LintCode: copy books
http://www.lintcode.com/zh-cn/problem/copy-books/
*/
// solution 1: binary search
/*
The key idea is to spread the books into people.
To get minimum necklace
*/ 

int copyBooks(vector<int> &pages, int k) {
	if(pages.size() <= k) {
		return *max_element(pages);
	}
	int sum = 0;
	for(int i=0; i<pages.size(); i++) {
		sum += pages[i];
	}

	int lo = sum/k; // every worker comes to the average workload
	int hi = sum; // make it one person

	return binarySearch(pages, k, lo, hi);
}

int binarySearch(vector<int> &pages, int k, int lo, int hi) {
	while(lo <= hi) {
		int mid = (lo+hi)/2;
		if(isValid(pages, mid, k)) {
			hi = mid-1;
		}
		else {
			lo = mid+1;
		}
	}
	return lo;
}

bool isValid(vector<int> &pages, int workerload, int k) {
	int cnt = 0;
	int curLoad = 0;

	int ind = 0;
	while(ind < pages.size()) {
		if(pages[ind] > workerload) {
			return false;
		}
		if(pages[ind] + curLoad > workerload) {

			cnt++;
			curLoad = 0;
		}
		curLoad += pages[ind];
		ind++;
	}
	if(curLoad > 0) {
		cnt++;
	}
	return cnt <= k;


}

// solution 2: dp
// This is kinda tricky
// think about the transition function

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
    }
};