// Sqrt(x)
// Compute and return the square root of x

// Overflow problem

    int mySqrt(int x) {
        int lo = 0, hi = x, mid;
        long com;
        
        while(lo < hi - 1) {
            mid = lo + (hi-lo)/2;
            com = (long)mid*mid;
            if(com == (long)x) {
                return mid;
            }
            else if(com < (long)x) {
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        if(hi*hi <= x) {
            return hi;
        }
        else 
            return lo;
    }