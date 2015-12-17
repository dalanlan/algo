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