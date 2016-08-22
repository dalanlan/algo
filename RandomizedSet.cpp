
/*
Leetcode: Insert Delete GetRandom
https://leetcode.com/problems/insert-delete-getrandom-o1/
*/



class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
       
    }
    vector<int> num;
    unordered_map<int, int> _map;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(_map.count(val) == 0) {
            _map[val] = num.size();
            num.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(_map.count(val) != 0) {
            int indx = _map[val];
            if(indx != num.size()-1) {
                swap(num[indx], num[num.size()-1]);
                _map[num[indx]] = indx;
            }
            _map.erase(val);
            num.pop_back();
            return true;
            
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return num[rand()%num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
