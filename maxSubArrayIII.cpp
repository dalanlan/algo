
/*
LintCode: maximum subarray iii

*/

/*
The idea is borrowed from buy-ans-sell-stock-iv
classical dp

trick: initialization is what matters
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int sz = nums.size();
        if(sz < k) {
            return INT_MIN;
        }
        // localMax[i][j]: find out j subarray sum max in first ith (len), including i-1th element
        // globalMax[i][j]: find out j subarray sum max in first ith (len), may escape i-1th element
        
        vector<vector<int> > localMax = vector<vector<int>> (sz+1, vector<int>(k+1, INT_MIN/2));
        vector<vector<int> > globalMax = vector<vector<int>> (sz+1, vector<int>(k+1, INT_MIN/2));
        
        for(int i=0; i<=sz; i++) {
            localMax[i][0] = 0;
            globalMax[i][0] = 0;
        }
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=k; j++) {
                localMax[i][j] = max(localMax[i-1][j]+nums[i-1], globalMax[i-1][j-1]+nums[i-1]);
                globalMax[i][j] = max(localMax[i][j], globalMax[i-1][j]);
            }
        }
        return globalMax[sz][k];
    }
};

