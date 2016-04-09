
/*Lintcode: digit counts
http://www.lintcode.com/zh-cn/problem/digit-counts/
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        
        int base = 1;
        
        int count = 0;
        
        while(n/base>0) {
            int higher = n/(base*10);
            int cur = n/base%10;
            //int cur = n%(base*10)/base;
            int lower = n%base;
            if(cur > k) {
                count += (higher+1)*base;
            }
            else if (cur == k) {
                count += higher*base + lower + 1;
            }
            else {
                count += higher*base;
            }
            base *= 10;
        }
        if(k == 0){
            if (n == 0) {
                return 1;
            }
            else if(n>=10) {
                count -= 10;
            }
            else {
                count -= n+1;
            }
        }
        
        return count;
    }
};