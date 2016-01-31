/*
LintCode: count number of airplanes in the sky
http://www.lintcode.com/zh-cn/problem/number-of-airplanes-in-the-sky/#
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
   
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, int>> air;
        int count = 0;
        int ans = 0;
        // take advantage of pair thing 
        for(int i=0; i<airplanes.size(); i++) {
            air.push_back(make_pair(airplanes[i].start, 1));
            air.push_back(make_pair(airplanes[i].end, 0));
        }
        // sort is critical
        sort(air.begin(), air.end());
        for(int i=0; i<air.size(); i++) {
            if(air[i].second == 1) {
                count++;
            }
            else {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};