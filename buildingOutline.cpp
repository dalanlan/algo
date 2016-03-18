
/*
LintCode: building outline
http://www.lintcode.com/en/problem/building-outline/
*/


class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> ans;
        if(buildings.size() == 0) {
            return ans;
        }
        // borrow the idea from skyline problem and
        // deal with the output format if neccessary
        
        vector<pair<int, int>> heights;
        for(auto b: buildings) {
            heights.push_back(make_pair(b[0], -b[2]));
            heights.push_back(make_pair(b[1], b[2]));
        }
        
        sort(heights.begin(), heights.end());
        
        vector<pair<int,int>> res;
        
        multiset<int> set;
        set.insert(0);
        int prev = 0;
        
        int start = -1;

        for(auto h:heights) {
            // start point
            if(h.second < 0) {
                set.insert(-h.second);
            }
            else {
                // end point
                set.erase(set.find(h.second));
            }
            
            int cur = *set.rbegin();
            if(prev != cur) {
            	if(cur > 0) {
            		ans.push_back(vector<int>{start, h.first, cur});
            	}
            	start = h.first;
            	prev = cur;
            }
            // solution 1
            int cur = *set.rbegin();
            if(prev != cur) {
                res.push_back(make_pair(h.first, cur));
                prev = cur;
            }
            // end solution 1
        }
       
       	// solution 1
        // deal with the output
        for(int i=0; i<res.size()-1; i++) {
            if(res[i].second == 0) {
                continue;
            }
            ans.push_back(vector<int>{res[i].first, res[i+1].first, res[i].second});    
        }
        // end solution 1
        return ans;
    }
};

 vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> ans;
        if(buildings.size() == 0) {
            return ans;
        }
        // borrow the idea from skyline problem and
        // deal with the output format if neccessary
        
        vector<pair<int, int>> heights;
        for(auto b: buildings) {
            heights.push_back(make_pair(b[0], -b[2]));
            heights.push_back(make_pair(b[1], b[2]));
        }
        
        sort(heights.begin(), heights.end());
        
        vector<pair<int,int>> res;
        
        multiset<int> set;
        set.insert(0);
        int prev = 0;
        
        int start = -1;

        for(auto h:heights) {
            // start point
            if(h.second < 0) {
                set.insert(-h.second);
            }
            else {
                // end point
                set.erase(set.find(h.second));
            }
            
            int cur = *set.rbegin();
            if(prev != cur) {
            	if(prev > 0) {
            		ans.push_back(vector<int>{start, h.first, prev});
            	}
            	start = h.first;
            	prev = cur;
            }
            
        }
       
       	
        return ans;
    }