
/*
LintCode: subsets ii 
subset with duplicates
*/


// solution 1: recursive
// back-tracing

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void subset(vector<int> &num, vector<vector<int> > &res, vector<int> &path, int index) {       
        res.push_back(path);
        for(int i=index; i<num.size(); i++) {
            if(i > index && num[i] == num[i-1]) {
                continue;
            }
            path.push_back(num[i]);
            subset(num, res, path, i+1);
            path.pop_back();
        }
        
        
    }
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> num(S);
        sort(num.begin(), num.end());
        // This may be prohibited 'cause it's const
        //sort(S.begin(), S.end());
        
        vector<vector<int> > res;
        vector<int> path;
        subset(num, res, path, 0);
        return res;
    }
};
