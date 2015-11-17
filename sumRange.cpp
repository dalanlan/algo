// Range Sum Query 
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            return;
       
        sum.push_back(nums[0]);
        for(int i=1; i< nums.size(); i++) {
            sum.push_back(sum[i-1]+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(sum.size() != 0) {
        if(i > 0)
            return (sum[j]-sum[i-1]);
        else if(i == 0)
            return sum[j];
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);