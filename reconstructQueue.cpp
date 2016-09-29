
/*
LeetCode: Queue Reconstruction By Height
https://leetcode.com/problems/queue-reconstruction-by-height/
*/

class Solution {
public:
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int sz = people.size();
        int cnt = 0;
        vector<int> vis(sz, false);
        
        vector<pair<int,int>> res(sz, {0,0});
        
        while( cnt < sz) {
            int height = INT_MAX;
            int ind = -1;
            
            for(int i=0; i<sz; i++) {
                if(people[i].first < height) {
                    height = people[i].first;
                    ind = i;
                }
            }
            
            int pos = people[ind].second;
            int j = 0;
            while(pos > 0) {
                if(j < sz && (vis[j] == false || vis[j] && res[j].first >= people[ind].first)) {
                    pos--;
                }
                j++;
            }
            while( j < sz && vis[j]) {j++;}
 
        
            res[j] = people[ind];
            vis[j] = true;
            people[ind].first = INT_MAX;
            cnt++;
            
            
        }
        return res;
    }
};



    vector<pair<int,int>> reconstructQueue(vector<pair<int, int>>& people) {
	sort(people.begin(), people.end(), [](pair<int,int> p1, pair<int, int> p2) {
		return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
	});

	vector<pair<int,int>> res; 
	for(auto pe : people) {
		res.insert(res.begin() + pe.second, pe);
	}
	return res;
	
}