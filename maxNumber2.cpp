
/*
321. Create Maximum Number
https://leetcode.com/problems/create-maximum-number/
*/
// Given a vector and an integer k, find out 
vector<int> maxNum(vector<int>& num, int k) {
	vector<int> res;
	int sz = num.size();
	for(int i=0; i<sz; i++) {
		while(!res.empty() && (sz-i+res.size()-1) >= k && res.back() < num[i]) {
			res.pop_back();
		}
		if(res.size() < k) {
		    res.push_back(num[i]);
		}
	}

	cout<<endl;
	return res;
}

vector<int> maxNum(vector<int>& num1, vector<int>& num2) {
	int pos1=0, pos2 = 0;
	vector<int> res;

	while(pos1 < num1.size() || pos2 < num2.size()) {
		if(isGreater(num1, pos1, num2, pos2)) {
			res.push_back(num1[pos1++]);
		}
		else {
			res.push_back(num2[pos2++]);
		}
	}
	return res;
}
bool isGreater(vector<int> &num1, int pos1, vector<int>& num2, int pos2) {
	// strict greater
	while(pos1 < num1.size() && pos2 < num2.size() && num1[pos1] == num2[pos2]) {
		pos1++;
		pos2++;
	}
	return num2.size() == pos2 || (pos1 < num1.size() &&num1[pos1] > num2[pos2]);
}

vector<int> maxNumber(vector<int> nums1, vector<int> nums2, int k) {
	vector<int> res;
	for(int i=max(0,k-(int)nums2.size()); i<=k && i<=nums1.size(); i++) {
		vector<int> cand1 = maxNum(nums1, i);
		vector<int> cand2 = maxNum(nums2, k-i);
		vector<int> cand = maxNum(cand1, cand2);
		if(isGreater(cand, 0, res, 0)) {
			res = cand;
		}
	}
	return res;
}