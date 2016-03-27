
/*
Leetcode: counting bits
https://leetcode.com/problems/counting-bits
*/
 
    // solution 1
    vector<int> countBits(int num) {
        
        vector<int> res(num+1, 0);
        
        for(int i=1; i<=num; i++) {
            res[i] = res[i>>1] + i%2;
        }
        return res;
        
    }

    // solution 2 
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1; i<=num; i++) {
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }

    //  solution 3 
    // int count(int num) {
    //     // calculate number of 1's in the binary representation
    //     int count=0;
    //     while(num) {
    //         num &= num-1;
    //         count++;
    //     }
    //     return count;
    // }
    // vector<int> countBits(int num) {
    //     vector<int> res;
    //     for(int i=0; i<=num; i++) {
    //         res.push_back(count(i));
    //     }
    //     return res;
    // }