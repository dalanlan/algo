
/*
sort algorithm: heap && heap sort
*/

// max-heap: the value of the root is greater than 
// its left subtree and its right subtree

// min-heap: the value of the root is less than
// its left subtree and its right subtree

class Heap {
	public:
		vector<int> nodes;
		bool isMaxHeap;
		int sz;
		Heap(int cap, bool isMax) {
			nodes = vector<int> (cap, 0);
			isMaxHeap = isMax;
			sz = 0; // valid number
		}	

		Heap(vector<int>& A, bool isMax) {
			nodes(A);
			isMaxHeap = isMax;
			sz = A.size();
			for(int i=A.size()/2-1; i>=0; i--) {
				shiftDown(i);
			}
		}

		void shiftDown(int i) {
			int left = i*2+1;
			int right = i*2+1;

			while(left < sz || right < sz) {
				if(isMaxHeap) {
					int leftVal = left<sz?nodes[left]:INT_MIN;
					int rightVal = right<sz?nodes[right]:INT_MIN;
					int next = leftVal >= rightVal?left:right;

					if(nodes[i] < nodes[next]) {
						swap(nodes[i], nodes[next]);
						i=next;
						left = 2*i+1;
						right = 2*i+2;
					}
					else {
						break;
					}
				}
				else {
					int leftVal = left<sz?nodes[left]:INT_MAX;
					int rightVal = right<sz?nodes[right]:INT_MAX;
					int next = leftVal <= rightVal?left:right;

					if(nodes[i] > nodes[next]) {
						swap(nodes[i], nodes[next]);
						i=next;
						left=2*i+1;
						right=2*i+2;
					}
					else {
						break;
					}
				}
				
			}
		}

		int popHeapRoot() {
			int rootVal = nodes[0];
			swap(nodes[0], nodes[sz-1]);
			sz--;
			if(sz>0) {
				shiftDown(0);
			}
			return rootVal;
		}
};