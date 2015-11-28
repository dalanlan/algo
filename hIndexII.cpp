// H index II
// Given that the index is sorted

// Have no idea what this is

    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        
        int lo = 0, hi = sz-1, mid;
        int res = 0;
        while(lo <= hi) {
            mid = lo + (hi - lo)/2;
            if(citations[mid] >= sz - mid) {
                res = sz - mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return res;
    }
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        int lo = 0, hi = sz - 1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo)/2;
            if(citations[mid] < sz - mid) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return sz - lo;
    }