
/*
LintCode: find mininum in rotated sorted array
http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int lo=0, hi=num.size()-1, mid;
        while(lo < hi) {
            mid = (lo+hi)/2;
            if(num[mid] < num[hi]) {
                hi = mid;
            }
            else if(num[mid] > num[hi]) {
                lo = mid+1;
            }
            else {
                hi--;
            }
        }
        return num[lo];
    }
};