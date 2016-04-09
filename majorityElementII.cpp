vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(nums.size()==0)
        return res;
        
    int can1,can2,count1=0,count2=0;
    
    for(int i=0;i<nums.size();i++)
    {
        
        if(nums[i]==can1)
            count1++;
        else if(nums[i]==can2)
            count2++;
        else if(count1==0)
        {
            can1=nums[i];
            count1=1;
        }
        else if(count2==0)
        {
            can2=nums[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
        
            
    }
    if(count1 > 0)
    {
        count1=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == can1)
                count1++;
        if(count1 > nums.size()/3)
            res.push_back(can1);
    }
    if(count2 > 0)
    {
        count2=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == can2)
                count2++;
        if(count2 > nums.size()/3 && can1 !=can2)
            res.push_back(can2);
    }
    return res;
    }


    class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cnt1=0, cnt2=0;
        int can1=INT_MAX, can2=INT_MAX;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==can1) {
                cnt1++;
            }
            else if(nums[i]==can2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                can1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0) {
                can2 = nums[i];
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> rs;
        if(cnt1 != 0) {
            cnt1 = 0;
            for(int i=0; i<nums.size();i++) {
                if(nums[i] == can1) {
                    cnt1++;
                }
            }
            if(cnt1 > nums.size()/3) {
                rs.push_back(can1);
            }
        }
        if(cnt2 != 0) {
            cnt2 = 0;
            for(int i=0; i<nums.size();i++) {
                if(nums[i] == can2) {
                    cnt2++;
                }
            }
            if(cnt2 > nums.size()/3) {
                rs.push_back(can2);
            }
        }
        return rs;
    }
};