// Permutation Sequence

/*
The set[1,2,3,...,n] contains a total of n!
unique permutations.

By listing and labeling all of the permutations in order, 
we get the following sequence(ie, for n=3):

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.
*/

// Memory Limit Exceeded
 void permute(string& init, vector<string>& resVect, int index, int k) {
	if(index == init.length()-1) {
		resVect.push_back(init);
	}
	else {
	for(int i=index; i<init.length(); i++) {
		swap(init[i],init[index]);
		//cout<<"init:"<<init<<endl;
		permute(init, resVect, index+1, k);
		swap(init[i],init[index]);
	}
	}
}
string getPermutation(int n,int k) {
	string init;
	for(int i=1;i<=n;i++) {
		init += i+'0';
	}
    vector<string> resVect;
	permute(init, resVect, 0, k);
	sort(resVect.begin(), resVect.end());
	return resVect[k-1];
}

// AC 
// in a math way
string getPermutation(int n,int k) {
	string perm;

	// 1,2, ..., n
	vector<int> nums;
	for(int i=1; i<=n; i++) {
		nums.push_back(i); 
	}

	//0! ~ (n-1)!
	vector<int> factorial; 
	int multi = 1;
	factorial.push_back(1); // 0!=1;
	for(int i=1; i<n; i++) { // 1!~(n-1)!	
		multi *= i;
		factorial.push_back(multi); 
	}

	k--; 
	int index;

	for(int i=1; i <= n; i++) {
		index = k/factorial[n-i];
		perm += nums[index]+'0';
		nums.erase(nums.begin() + index);
		k -= index*factorial[n-i];
	}

	return perm;


}