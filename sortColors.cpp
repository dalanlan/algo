
/*
LeetCode 75. Sort colors
Given an array with n objects colored red, white or blue, sort them
so that objects of the same color are adjacent, with the colors 
in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color 
red, white and blue respectively.
*/

void sortColors(vector<int>& nums) {
	for(int i=0;i<nums.size();i++) {
		if(nums[i] == 2) {
			continue;
		}
		if(nums[i] == 1) {
			int j=i;
			while((nums[j-1] == 2) && (j-1 >= 0)) j--;
			if(j >= 0) swap(nums[i], nums[j]);
		}
		if(nums[i] == 0) {
			int j=i;
			while((nums[j-1] >= 1) && (j-1 >= 0)) j--;
			if(j >= 0 && i != j) {
				swap(nums[i], nums[j]);
				i--;
			}
		}
	}
	return;
}

// someone's solution 
void sortColors(vector<int>& nums) {
	int zero=0, l=0, r=nums.size()-1;

	while(l<=r) {

		if(nums[l] == 0) {
			swap(nums[zero++], nums[l++]);
		}
		else if(nums[l] == 2) {
			swap(nums[l], nums[r--]);
		}
		else {
			l++;
		}
	}
	return;
}

// nth_element
// negative, zero, positive 
void sortColors(vector<int>& nums) {
	int neg=0, l=0, r=nums.size()-1;;
	while(l <= r) {
		if(nums[l] < 0) {
			swap(nums[l++], nums[neg++]);
		}
		else if(nums[l] == 0) {
			l++;
		}
		else {
			swap(nums[l], nums[r--]);
		}
	}
	return;
}


// solution: see you again
class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code her
        
        int lo=0, l=0, r=nums.size()-1;
        while(l <= r) {
            if(nums[l] == 0) {
                swap(nums[lo++], nums[l++]);
            }
            else if(nums[l] == 1) {
                l++;
            }
            else {
                swap(nums[l], nums[r--]);
            }
        }
    }
};