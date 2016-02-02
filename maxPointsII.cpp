/*
LintCode : max points on a line 
http://www.lintcode.com/zh-cn/problem/max-points-on-a-line/
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
     
    
    double slope(Point &p1, Point &p2) {
        if(p1.x == p2.x) {
            return INT_MAX;
        }
        if(p1.y == p2.y) {
            return 0.0;
        }
        return (double)(p1.y-p2.y)/(p1.x-p2.x);
        
    }
    
    int maxPoints(vector<Point>& points) {

        if(points.size() == 0) {
            return 0;
        }
        int res = 1;
        int dup;
        unordered_map<double, int> myMap;
        
        for(int i=0; i<points.size(); i++) {
            myMap.clear();
            dup = 0;
            myMap[INT_MIN]=1;
            for(int j=i+1; j<points.size(); j++) {
                // dup
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }
                double slop = slope(points[i], points[j]);
                if(myMap.find(slop) != myMap.end()) {
                    myMap[slop]++;
                }
                else {
                    myMap[slop] = 2;
                }
            }
            for(auto &x: myMap) {
                if(dup + x.second > res) {
                    res = dup + x.second;
                }
            }
        }
        return res;
    }
};