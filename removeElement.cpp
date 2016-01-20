
/*
LintCode 172: Remove the integer which equals the
given value.

LeetCpde 27. Remove Element

Given an array and an integer, remove all of the elements
which equal to the given value, return the length of the 
new array.
*/

// This is a stupid solution
int removeElement(vector<int> &A, int elem) {
	int count=A.size();
	for(vector<int>::iterator it = A.begin(); it!=A.end();it++) {
		if(*it == elem) {
			A.erase(it);
			count--;
			it--;
		}
	}
	return count;
}

int removeElement(vector<int> &A, int elem) {
	int pre = 0; 
	for(int i=0; i<A.size(); i++) {
		if(A[i] != elem) {
			A[pre++] = A[i];
		}
	}
	return pre;

}