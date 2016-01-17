
/*
Lintcode 158: determine whether two strings
are anagram of each other.
*/


// solution 1: O(logn) with sorting
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s==t);
    }
};

// solution 2: map
bool anagram(string s, string t) {
	// char, count
	unordered_map<char, int> myMap;
	int len = s.length();
	if(len != t.length()) {
		return false;
	}

	for(int i=0; i<len; i++) {
		if(myMap.find(s[i]) == myMap.end()) {
			myMap[s[i]] = 1;
		}
		else {
			myMap[s[i]]++;
		}
	}
	for(int i=0; i<len; i++) {
		if(myMap.find(t[i]) == myMap.end()) {
			return false;
		}
		else {
			myMap[t[i]]--;
		}
	}
	for(auto& m:myMap) {
		if(m.second != 0) {
			return false;
		}
	}
	return true;

}