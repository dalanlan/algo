
/*
LintCode 204 :Singleton
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution *instance = new Solution();
        return instance;
    }
    // copy construction function
    Solution(const Solution &s) = delete;
    // operation override
    Solution& operator=(const Solution &s) = delete;
private:
    Solution(){}
    ~Solution(){}
};