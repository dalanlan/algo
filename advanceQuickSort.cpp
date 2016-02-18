
/*
Two way quick sort

http://algs4.cs.princeton.edu/23quicksort/Quick.java.html
*/


void sort(int[] a) {
	shuffle(a);
	sort(a, 0, a.length-1);
}

void sort(int[] a, int lo, int hi) {
	// partition

	if(lo >= hi) {
		return;
	}
	int j = partition(a, lo,  hi);
	sort(a, lo, j-1);
	sort(a, j+1, hi);

}
int partition(int[] a, int lo, int hi) {
	int pivot = a[lo];
	int l = lo, r = hi+1;

	while(true) {
		while(a[++l] < pivot) {
			if(l == hi) {
				break;
			}
		}
		while(a[--r] > pivot) {
			if(r == lo) {
				break;
			}
		}
		if(l >= r) {
			break;
		}
		swap(a[l], a[r]);
	}
	swap(a[lo], a[r]);
	return r;
}

/*
3-way quick sort
http://algs4.cs.princeton.edu/23quicksort/Quick3way.java.html
*/

void sort(int[] a) {
	shuffle(a);
	sort(a, 0, a.length()-1);
}

void sort(int[] a, int lo, int hi) {
	if(lo >= hi) {
		return;
	}
	int lt = lo, gt = hi;
	int pivot = a[lo];
	int i=lo;

	while(i <= gt) {
		if(a[i] < pivot) {
			swap(a[lt++], a[i++]);
		}
		else if(a[i] > pivot) {
			swap(a[i], a[gt--]);
		}
		else {
			i++;
		}
	}
	sort(a, lo, lt-1);
	sort(a, gt+1, hi);
	

}