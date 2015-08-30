#include <iostream>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {

    vector<int> final;
   
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        res ^= nums[i];
    }
    int pos=0;
    while(!(res>>pos & 1))
        pos++;
        
    int res1 = 0,res2 = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] >> pos & 1)
            res1 ^= nums[i];
        else
            res2 ^= nums[i];
    }
    final.push_back(res1);
    final.push_back(res2);
    return final;
    
}