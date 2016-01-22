
/*
LintCode :Climb the stairs
http://www.lintcode.com/zh-cn/problem/climbing-stairs/

Simple dp
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        vector<int> path(n+1, 0);
        path[0] = 1;
        path[1] = 1;
        for(int i=2;i<=n;i++) {
            path[i] = path[i-1]+path[i-2];
        }
        return path[n];
    }
};
