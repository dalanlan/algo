 int singleNumber(vector<int>& nums) 
{
 
 int one = 0, two = 0, not_three= 0;
 
 for(int i =0;i<nums.size();i++)
 {
     two |= one&nums[i]; //order matters; two first, and one latter
     one ^= nums[i];
     
     
     not_three = ~(one & two);
     one &= not_three;
     two &= not_three;
 }
 return one;



}


 int singleNumber(vector<int>& nums) 
{

    int count[32]={0};
    int res=0;
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<nums.size();j++)
            if((nums[j]>>i) & 1)
                count[i]++;
                
        res |= (count[i]%3)<<i;    // Every bit
    }
    return res;
}


// Original idea: http://www.careercup.com/question?id=7902674
