
/*
Leetcode: russian doll envelops

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

// greedy
// priority_queue
// make_pair

// solution 1
// WA
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	int sz = envelopes.size();
    	if(sz < 2) {
    		return sz;
    	}
    	sort(envelopes.begin(), envelopes.end());

    	// greedy algorithm
    	// WA
    	int res = 1;
    	int in = 0, out = in+1;
    	while(out < sz) {
    		if(envelopes[out].first > envelopes[in].first && envelopes[out].second > envelopes[in].second) {
    			res++;
    			in = out;
    			out = in+1;
    		}
    		else {
    			out++;
    		}
    	}
    	return res;
    }
};

// dp
// AC
class Solution {
public:
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
	int sz = envelopes.size();
	if(sz < 2) {
		return sz;
	}
	sort(envelopes.begin(), envelopes.end());

	vector<int> dp(sz, 1);
	for(int i=1; i < envelopes.size();i++) {
		for(int j=0; j < i; j++) {
			if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int res = 0;
	for(int i=0; i<sz; i++) {
	    res = max(res, dp[i]);
	    
	}
	return res;
}
};
