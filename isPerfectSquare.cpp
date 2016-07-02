/*

Leetcode: valid perfect square
https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

*/

class Solution {
public:
    // a perfect square is a number with
    // odd factors.
    // TLE
    // bool isPerfectSquare(int num) {
    //     int counter = 0;
        
    //     for(int i=1; i <= num; i++) {
    //         if(num % i == 0) {
    //             counter+=2;
    //         }
    //     } 
    
    //     return counter%2 == 1;
    // }
    
    // TLE
    // bool isPerfectSquare(int num) {
    //     for(int i=1; i*i<=num; i++) {
    //         if(i*i == num) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    bool isPerfectSquare(int num) {
        long r = num;
        while(r*r > num) {
            r = (r+num/r)/2;
        }
        return r*r==num;
    }
     
};