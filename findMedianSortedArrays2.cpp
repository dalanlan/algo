
/*
LeetCode: Median of two sorted arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

// solution 1: AC; best one
// time complexity: O(min(sz1, sz2))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int sz1 = nums1.size();
	int sz2 = nums2.size();

	if(sz1 > sz2) {
		return findMedianSortedArrays(nums2, nums1);
	}
	int lo = 0, hi=sz1;
	int ln = ((sz1+sz2+1)>>1);
	
	int maxLeft = 0, minRight = 0;

	while(lo <= hi) {
		int i=((lo+hi)>>1), j=ln-i;

		if(i >0 && j < sz2 && nums1[i-1] > nums2[j]) {
			hi = i-1;
		}
		else if(j>0 && i< sz1 && nums2[j-1] > nums1[i]) {
			lo = i+1;
		}
		else {
			if(i == 0) {
				maxLeft = nums2[j-1];
			}
			else if(j == 0) {
				maxLeft = nums1[i-1];
			}
			else {
				maxLeft = max(nums1[i-1], nums2[j-1]);
			}

			if((sz1+sz2) %2) {
				return maxLeft;
			}

			if(i == sz1) {
				minRight = nums2[j];
			}
			else if (j == sz2) {
				minRight = nums1[i];
			}
			else {
				minRight = min(nums1[i], nums2[j]);
			}
			return (double)(maxLeft + minRight)/2.0;
		}
	}
	return 0.0;
}



// solution2: derived from find the kth element from two sorted arrays

double getKth(vector<int>& nums1, int sz1, int sta1, vector<int>& nums2, int sz2, int sta2, int k) {
	if(sz1 > sz2) {
		return getKth(nums2, sz2, sta2, nums1, sz1, sta1, k);
	}

	if(sz1 == 0) {
		return nums2[sta2+k-1];
	}

	if(k == 1) {
		return min(nums1[sta1], nums2[sta2]);
	}

	int i=min(sz1, k/2), j = min(sz2, k/2);
	if(nums1[sta1+i-1] > nums2[sta2+j-1]) {
		return getKth(nums1, sz1, sta1, nums2, sz2-j, sta2+j, k-j);
	}
	else {
		return getKth(nums1, sz1-i, sta1+i, nums2, sz2, sta2, k-i);
	}
	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int sz1 = nums1.size();
	int sz2 = nums2.size();

	int l = (sz1 + sz2 + 1)>>1;
	int r = (sz1 + sz2 + 2)>>1;

	return (getKth(nums1, sz1, 0, nums2, sz2, 0, l) + getKth(nums1, sz1, 0, nums2, sz2, 0, r))/2.0;
}