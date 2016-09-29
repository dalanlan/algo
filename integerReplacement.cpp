
/*
LeetCode: integer replacement
https://leetcode.com/problems/integer-replacement/
*/

class Solution {
public:
    

/*
step 1: if n is even, half it
step 2: if n == 3 or n - 1 has less 1s than n+1, decrese n
step 3: otherwise increase n

*/
    
    
    int integerReplacement(int n) {
        int cnt = 0;
        if(n == INT_MAX) {
        return 32;
        
        }
        while(n != 1) {
            // bitset<32> foo(n-1);
            // bitset<32> bar(n+1);
            
            if((n&1) == 0) {
                n >>= 1;
                
            }
            else if(n == 3 || __builtin_popcount(n-1) < __builtin_popcount(n+1) ) {
                n--;
            }
            else {
                n++;
            }
            cnt++;
        }
        return cnt;
    }
};


// solution 2: focus on the last two digits
 
int integerReplacement(int n) {
    int cnt = 0;
    if(n == INT_MAX) {
        return 32;
        
    }
    while(n != 1) {
        // cout<<n<<endl;
        if((n & 1) == 0) {
            n >>= 1;
        }
        else if (n == 3 || ((n >> 1) & 1) == 0) {
            n--;
        }
        else {
            n++;
        }
        cnt++;
    }
    return cnt;
}

int integerReplacement(int n) {
    int cnt = 0;
     
    if(n == INT_MAX) {
        return 32;
    }
    while(n != 1) {
        if(n & 1) {
            if(n!=3 && (n+1)%4 == 0) {
                n++;
            }
            else {
                n--;
            }
        }
        else {
            n >>= 1;
        }
        cnt++;
    }
    return cnt;
}
