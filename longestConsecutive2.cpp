
/*
2016/04/23
Leetcode: longest consecutive sequence
https://leetcode.com/problems/longest-consecutive-sequence/
*/

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        
        for(int n:nums) {
            if(map.count(n) > 0) {
                continue;
            }
            
            int left = map.count(n-1)>0?map[n-1]:0;
            int right = map.count(n+1)>0?map[n+1]:0;
            
            int count = left+right+1;
            res = max(res, count);
            map[n] = count;
            map[n-left] = count;
            map[n+right] = count;
        }
        return res;
    }

    // solution 2:
    // extremely short and clean
        int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> m;
        int r = 0;
        for (int i : num) {
            if (m[i]) continue;
            r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        }
        
    return r;
}