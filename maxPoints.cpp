// Max points on a line
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
     int maxPoints(vector<Point>& points) {
        if(points.size() == 0 || points.size() == 1)
            return points.size();
        unordered_map<double,int> count;
        int ans = 0; 
        for(int i=0;i<points.size();i++) {
            count.clear();
            int dup = 0;
            int tmp = 1;
            for(int j=0;j<points.size();j++) {
                if (i == j)
                    continue;
                else{
                    
                    if(points[i].x == points[j].x) {
                        if(points[i].y == points[j].y) {
                            dup++;
                        }
                            
                        else {
                                count[INFINITY]++;
                        }
                        
                    }
                    else{
                        double tang = (double)(points[j].y - points[i].y)/(points[j].x-points[i].x);
                        
                            count[tang]++;
                    }
                    
                }
            }
            
 
            for(auto it = count.begin(); it != count.end();it++) {
                
                if(it->second + 1 > tmp) {
                    tmp = it->second + 1;
                }
                
            }
            if(ans < tmp + dup)
                ans = tmp + dup;
 
                
        }
        return ans;
        
    }


};