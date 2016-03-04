
/*
LeetCode 324: Wiggle sort II
Given an unsorted array nums, reorder it such that 
nums[0] < nums[1] > nums[2] < nums[3] ...

Follow-up: can you do it in O(n) time or/and in place
with O(1) extra space?

*/

// roughly speaking we put the smaller half of the 
// numbers on the even indexes and larger half on the 
// odd indexes
// The tricky part is we dont allow adj equal
// in place solution  

/* A good explanation
 https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof

 We call median M, then let's say with n numbers, floor(n/2) times M 
 makes no trouble. 
*/

/*
func nth_element
STL中的nth_element()方法的使用 通过调用nth_element(start, start+n, end) 方法
可以使第n大元素处于第n位置（从0开始,其位置是下标为 n的元素），并且比这个元素小的元素
都排在这个元素之前，比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的.

Rearranges the elements in the range [first,last), in such a way that the element at 
the nth position is the element that would be in that position in a sorted sequence.
The other elements are left without any specific order, except that none of the 
elements preceding nth are greater than it, and none of the elements following it are less.
*/

/*
int main() {
	vector<int> myVector;
	for(int i=0; i<10; i++) {
		myVector.push_back(i);
	}
	random_shuffle(myVector.begin(), myVector.end());

	nth_element(myVector.begin(), myVector.begin()+5, myVector.end());

	for(vector<int>::iterator it=myVector.begin(); it!= myVector.end(); it++) {
		cout<<*it<<' ';
	}
	cout<<endl;
	return 0;
} 
*/

// solution 1: A very neat idea
// Cost time & space via sort and a duplicated array
// say we have 
void wiggleSort(vector<int>& nums) {
	vector<int> rep(nums);
	sort(rep.begin(), rep.end());

	int sz = nums.size(), m=sz|1;
	for(int i=0; i<sz; i++) {
		nums[(1+2*i)%m] = rep[i];
	}
}


// solution 2: once we dont want sort, 
// we just use nth_element to figure out the median.
// and then use virtual indexing.

void wiggleSort(vector<int>& nums) {
	vector<int> rep(nums);
	int sz = nums.size();
	auto mid = rep.begin() + sz/2;
	nth_element(rep, rep.begin(), mid, rep.end());

	int m = sz|1;
	for(int i=0; i<sz;i++) {
		nums[(2*i+1)%m] = rep[i];
	}
}