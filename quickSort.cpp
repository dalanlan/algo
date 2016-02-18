// Two way quickSort
// O(nlogn) on average, O(n^2) in the worst case


// original: 10, 2, 1, 7, 3, 7, 4, 8, 9

// round 1: 4, 2, 1, 7, 3, 7, 10, 8, 9
// >< 

void quickSort(int lo, int hi, int arr[]) {
	
	int pivot = arr[lo+(hi-lo)/2];

	int l=lo, r=hi;

	while(l<=r) {
		while(arr[l] < pivot && l<r) {
			l++;
		}
		while(arr[r] > pivot && r > l) {
			r--;
		}
		if(l < r) {
			swap(arr[l], arr[r]);
			l++;
			r--;
		}
	}

	if(lo < r) quickSort(lo, r, arr);
	if(l < hi) quickSort(l, hi, arr);
}

