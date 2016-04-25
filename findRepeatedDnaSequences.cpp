
/*
LeetCode: repeated dns sequences
https://leetcode.com/problems/repeated-dna-sequences/
*/

// solution 1:hashmap
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        if(s.length() < 10) {
            return res;
        }
        for(int i=0; i<=s.length()-10; i++){
            string candidate = s.substr(i, 10);
            if(map.count(candidate) == 0) {
                map[candidate] = 1;
            }
            else {
                
                if(map[candidate]!=-1) {
                    res.push_back(candidate);
                    map[candidate] = -1;
                }
            }
        }
        return res;
    }

    // solution 2: bit manipulation?
    