
/*
LintCode: majority number iii
http://www.lintcode.com/zh-cn/problem/majority-number-iii/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    // int majorityNumber(vector<int> nums, int k) {
    //     // write your code here
        
       
    // }
    int majorityNumber(vector<int> nums, int k) {
	// pair: nums, count
	unordered_map<int, int> myMap;
	int i=0;
	
	while(i < nums.size() && myMap.size() < k) {
		if(myMap.find(nums[i]) != myMap.end()) {
			myMap[nums[i]]++;
		}
		else {
			myMap[nums[i]] = 1;
		}
		i++;
	}

	while(i < nums.size()) {
		if(myMap.find(nums[i]) != myMap.end()) {
			myMap[nums[i]]++;
		}
		else {
			vector<int> removeKey;
			if(myMap.size() == k) {
			    for(auto &x: myMap) {
			        x.second--;
				    if(x.second == 0) {
					    removeKey.push_back(x.first);
				    }
			    }
			}
		
			for(int j=0; j<removeKey.size(); j++) {
				myMap.erase(removeKey[j]);
			}
			myMap[nums[i]]=1;
		}
		i++;
	}

	for(auto &x:myMap) {
	    x.second = 0;
	}
	for(int k=0; k<nums.size();k++) {
	    if(myMap.find(nums[k]) != myMap.end()) {
	        myMap[nums[k]]++;
	    }
	}
	
	int maxKey, maxCount=-1;
	for(auto &x: myMap) {
		if(maxCount < x.second) {
			maxCount = x.second;
			maxKey = x.first;
		}
	}
	return maxKey;
}
};