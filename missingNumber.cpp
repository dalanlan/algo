int missingNumber(vector<int>& nums) {
    int max_num = nums.size(), sum = 0, expected = 0;
    
    for (int i=0;i<nums.size();i++)
    {
        sum += nums[i];
    }
    expected = (max_num+1)*max_num/2;
    return expected-sum;

    
}

int missingNumber(vector<int>& nums) {
    int res = 0;
    for(int i=0;i<=nums.size();i++)
        res ^= i;
    for(int i=0;i<nums.size();i++)
    {
        res ^= nums[i];
    }
    return res;
}