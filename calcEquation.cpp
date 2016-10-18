
/*
LeetCode: evaluate division
https://leetcode.com/problems/evaluate-division/
*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int sz = equations.size();
            
        unordered_map<string, unordered_map<string, double>> assign;
        
        for(int i=0; i<sz; i++) {
            string prev = equations[i].first;
            string latt = equations[i].second;
            
            assign[prev][latt] = values[i];
            assign[latt][prev] = 1.0/values[i];
        }
        
        int qry = queries.size();
        vector<double> ans(qry, -1.0);
        for(int i=0; i<qry; i++) {
            unordered_set<string> st;
            double rs = dfs(queries[i].first, queries[i].second, assign, st);
            ans[i] = rs?rs:-1.0;
        }
        return ans;
        
            
    }
    
    double dfs(string prev, string latt, unordered_map<string, unordered_map<string, double>> &assign, unordered_set<string> &st) {
        string key = prev+":"+latt;
        if(st.count(key)) {
            return NULL;
        }
        if(assign.count(prev) == 0 || assign.count(latt) == 0) {
            return NULL;
        }
        if(prev == latt) {
            return 1.0;
        }
        if(assign[prev].count(latt)) {
            return assign[prev][latt];
        }
        
        st.insert(key);
        for(auto rec : assign[prev]) {
            double rs= dfs(rec.first, latt, assign, st);
            if(rs) {
                return rs*rec.second;
            }        
        
        }
        st.erase(key);
        return NULL;
        
        
    }
};