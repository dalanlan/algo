vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(nums.size()==0)
        return res;
        
    int can1=nums[0],can2=0,count1=1,count2=0;
    
    for(int i=1;i<nums.size();i++)
    {
        
        if(nums[i]==can1)
            count1++;
        else if(nums[i]==can2 && can1 != can2)
            count2++;
        else if(count1==0)
        {
            can1=nums[i];
            count1=1;
        }
        else if(count2<=0 && can1 != can2)
        {
            can2=nums[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
        
            
    }
    
        count1=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == can1)
                count1++;
        if(count1 > nums.size()/3)
            res.push_back(can1);
    
    
        count2=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == can2)
                count2++;
        if(count2 > nums.size()/3 && can1 !=can2)
            res.push_back(can2);
    
    return res;
    }