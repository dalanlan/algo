
/*
LintCode : permutation sequence 

*/

    string getPermutation(int n, int k) {
    
        vector<int> nums;
        for(int i=1; i<=n; i++) {
            nums.push_back(i);
        }
        vector<int> fact;
        int tmp = 1;
        fact.push_back(tmp);
        // 0!~(n-1)!
        // fact[0] = 0!
        // fact[n-1] = (n-1)!
        for(int i=1; i<n; i++) {
            tmp *= i;
            fact.push_back(tmp);
        }
        
        k--;
        string res;
        int index;
        for(int i=1; i<=n; i++) {
            // fact[n-1]???
            index = k/fact[n-i];
            res += nums[index]+'0';
            nums.erase(nums.begin() + index);
            k -= index*fact[n-i];
        }
        return res;
        
    }