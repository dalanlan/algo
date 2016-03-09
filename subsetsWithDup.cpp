
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


// solution 2: iterative

vector<vector<int> > subsetsWithDup(const vector<int> &S) {
    vector<vector<int> > res;
    res.push_back(vector<int>{});
    int sz = S.size();
    if(sz == 0) {
        return res;
    }
    vector<int> num(S);
    sort(num.begin(), num.end());

    int start=0, i=start;

    while(i<sz) {
        while(i+1<sz && num[i] == num[i+1]) {
            i++;
        }

        vector<vector<int> > nextRes(res);
        for(auto &r: nextRes) {
            vector<int> ele(r);

            for(int j=start; j<=i; j++) {
                ele.push_back(num[j]);
                res.push_back(ele);
            }
        }
        start = i+1;
        i=start;
    }
    return res;
}