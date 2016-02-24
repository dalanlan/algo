
/*
LintCode: longest consecutive sequence
http://www.lintcode.com/zh-cn/problem/longest-consecutive-sequence/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_set<int> mySet;
        for(int i=0; i<num.size(); i++) {
            mySet.insert(num[i]);
        }
        
        int longest = 0;
        for(int i=0; i<num.size(); i++) {
            int down = num[i]-1;
            while(mySet.find(down) != mySet.end()) {
                mySet.erase(down);
                down--;
            }
            int up = num[i]+1;
            while(mySet.find(up) != mySet.end()) {
                mySet.erase(up);
                up++;
            }
            mySet.erase(num[i]);
            longest = max(longest, up-down-1);
        }
        return longest;
    }
};


// solution 2: rewrite solution 1

    int longestConsecutive(vector<int> &num) {
	unordered_set<int> mySet(num.begin(), num.end());

	int res = 0;
	while(mySet.size() >0) {
		int v = *mySet.begin();
		int tmp=v;
		int count = 0;
		while(mySet.erase(--v)) {
			count++;
		}
		while(mySet.erase(tmp++)) {
			count++;
		}
		res = max(res, count);
	}
	return res;
	
}


// solution 3: use a map

int longestConsecutive(vector<int> &num) {

	unordered_map<int, int> myMap;
	int res = 0;
	for(int i=0; i<num.size(); i++) {
		if(myMap.find(num[i]) != myMap.end()) {
			continue;
		}
		myMap[num[i]]=1;
		int low=num[i], high = num[i];
		if(myMap.find(num[i]-1) != myMap.end()) {
			low = num[i] - myMap[num[i]-1];
		}
		if(myMap.find(num[i]+1) != myMap.end()) {
			high = num[i] + myMap[num[i]+1];
		}
		int count = high - low + 1;
		myMap[low] = count;
		myMap[high] = count;
		res = max(res, count);

	}
	return res;
 }