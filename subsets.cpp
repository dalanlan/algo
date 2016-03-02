
/*
LintCode: subset

*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void subset(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, int index) {
        
        // empty set
        res.push_back(path);
        
        for(int i=index; i<nums.size(); i++) {
            path.push_back(nums[i]);
            subset(res, path, nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &nums) {
    	
    	vector<vector<int>> res;
    	if(nums.size() == 0) {
    	    res.push_back(vector<int> {});
            return res;
    	}
    	sort(nums.begin(), nums.end());
    	vector<int> path;
        subset(res, path, nums, 0);
    	
    	return res;
    	
};