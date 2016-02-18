
/*
LintCode: update bits
http://www.lintcode.com/zh-cn/problem/update-bits/
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask =((1 << i)-1);
        
        mask |= (j == 31)?0:~((1<<(j+1)) -1);
        return n&mask | (m << i);
    }
};