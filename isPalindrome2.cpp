
/*
LeetCode: palindrome number
https://leetcode.com/problems/palindrome-number/
*/

// reverse till half
// take care of those numbers which mod 10 equals 0
    bool isPalindrome(int x) {
        if(x < 0 || (x>0 && x%10==0)) {
            return false;
        }
        int sum = 0;
        while(x > sum) {
            sum = sum*10+x%10;
            x/=10;
        }
        return sum==x||x==sum/10;
    }