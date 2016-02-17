
/*
lintcode: gas station
http://www.lintcode.com/zh-cn/problem/gas-station/
*/
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    
    bool canComplete(vector<int> &gas, vector<int> &cost, int index) {
        int remain = 0;
        int sz = gas.size();
        for(int i=index; i<index+sz; i++) {
            remain += gas[i%sz];
            remain -= cost[i%sz];
            if(remain < 0) {
                return false;
            }
        }
        return true;
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        
        // pick one choice
        for(int i=0; i<gas.size(); i++) {
            if(gas[i] >= cost[i]) {
                if(canComplete(gas, cost, i)) {
                    return i;
                }
            }
        }
        return -1;
    }
};


    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size() == 0 || cost.size() == 0) {
            return -1;
        }
        int sum = 0, total = 0, index = 0;
        
        for(int i=0; i<gas.size(); i++) {
            sum += gas[i]-cost[i];
            total += gas[i] - cost[i];
            if(sum < 0) {
                index = i+1;
                sum = 0;
            }
        }
        return total>=0?index:-1;
    }