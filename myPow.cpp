    // Pow(x, n)
    // Tags: Math, binary search

    // solution 1: bitset 

    double myPow(double x, int n) {
        bitset<32> bit(abs(n));
        
        double res = 1;
        
        for(int i=bit.size()-1; i>=0; i--) {
            res *= res;
            if(bit[i] == 1) {
                res *= x;
            }
        }
        if(n >= 0) {
            return res;
        }
        else {
            return 1/res;
        }
    }


    // Solution 2: bit operation 
    double myPow(double x, int n) {

        long m = n >= 0? n : -(long)n;
        double res = 1.0;
        while(m != 0) {
            if(m & 1 == 1) {
                res *= x;
            }
            x *= x;
            m>>=1;
        }
        return n >=0?res:(1/res);
    }