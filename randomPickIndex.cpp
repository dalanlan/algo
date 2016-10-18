
/*
LeetCode: Random pick index
https://leetcode.com/problems/random-pick-index/
*/

/*
To those who don't understand why it works. Consider the example in the OJ
{1,2,3,3,3} with target 3, you want to select 2,3,4 with a probability of 1/3 each.

2 : It's probability of selection is 1 * (1/2) * (2/3) = 1/3
3 : It's probability of selection is (1/2) * (2/3) = 1/3
4 : It's probability of selection is just 1/3

So they are each randomly selected.
*/

    vector<int> v;
    int sz;
    Solution(vector<int> nums) {
        v = nums;
        sz = nums.size();
    }
    
    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for(int i=0; i<sz; i++) {
            if(v[i]!=target) {
                continue;
            }
            cnt++;
            if(rand()%cnt == 0) {
                res = i;
            }
        }
        return res;
    }