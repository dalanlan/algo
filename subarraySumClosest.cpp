
/*
LintCode: subarray sum closest
http://www.lintcode.com/zh-cn/problem/subarray-sum-closest/
*/

// solution 1: borrow the idea from 
// find out the subarray sum equals zero 
vector<int> subarraySumClosest(vector<int> nums) {
	// sum -> index
	map<int, int> myMap;
	vector<int> res;
	if(nums.size() == 0) {
		return res;
	}

	int sum = 0;
	for(int i=0; i<nums.size(); i++) {
		sum += nums[i];
		if(myMap.find(sum) != myMap.end()) {
			res.push_back(myMap[sum]+1);
			res.push_back(i);
			return res;
		}
		else {
			myMap[sum]=i;
		}
	}

	int diff = INT_MAX;
	int start=0, end = 0;
	map<int, int>::iterator it;
	map<int, int>::iterator next_it;
	for(it = myMap.begin(); it != myMap.end(); it++) {
	    next_it = next(it);
	    if(next_it == myMap.end()) {
	        break;
	    }

		if(diff >= abs(it->first - next_it->first) ) {
			diff = abs(it->first - next_it->first);
			start = min(it->second, next_it->second) +1;
			end = max(it->second, next_it->second);
		}
	}
	res.push_back(start);
	res.push_back(end);
	return res;
}

//solution 2: use vector of pair

    vector<int> subarraySumClosest(vector<int> nums) {
        
        vector<int> res;
        if(nums.size() == 0) {
            return res;
        }
        
        vector<pair<int, int>> sum;
        int calSum = 0;
        for(int i=0; i<nums.size(); i++) {
            calSum += nums[i];
            sum.push_back(pair<int,int>(calSum, i));
        }
        // sort the vector
        // sort by first, and then second
        sort(sum.begin(), sum.end());
        
        int diff = INT_MAX;
        int start = 0, end = 0;
        int tmp;
        for(int i=0; i<sum.size()-1; i++) {
            tmp=abs(sum[i].first -sum[i+1].first);
            if(diff >= tmp) {
                diff=tmp;
                start=min(sum[i].second, sum[i+1].second)+1;
                end=max(sum[i].second, sum[i+1].second);
            }    
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }