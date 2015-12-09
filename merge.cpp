
//Merge Sorted Array

// directly copy nums2 into nums1, and then use quick sort.
// Two array has been sorted before.

void merge(vector<int>& nums1, int m, vector<int>& nums2,int n)
{
	int pos = m+n-1;
	int pos1 = m-1;
	int pos2 = n-1;
	while(pos1 >=0 && pos2 >=0)
	{
		if(nums1[pos1]>nums2[pos2])
		{
			nums1[pos] = nums1[pos1];
			pos1--;
		}	
		else
		{
			nums1[pos] = nums2[pos2];
			pos2--;
		}	
		pos--;
	}

	while(pos2 >=0)
	{	
		nums1[pos] = nums2[pos2];
		pos2--;
		pos--;
	}
	

}