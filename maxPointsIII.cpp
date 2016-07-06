
/*
LeetCode: Max points on a line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

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
    // int maxPoints(vector<Point>& points) {
        
    // }
    
// dont deal with duplicates
double slope(Point &p1, Point &p2) {
	if(p1.x == p2.x) {
		return INT_MAX;
	}
	if(p1.y == p2.y) {
		return 0.0;
	}
	return (double)(p1.y-p2.y)/(p1.x-p2.x);
}

// two nested loops
// traverse all through

// take care of the dup 
// in the inner loop
int maxPoints(vector<Point>& points) {
	if(points.size() == 0) {
	   return 0;
	}
	unordered_map<double,int> counter;

	int res = 1;
	for(int i=0; i<points.size(); i++) {
		// clear the known records
		counter.clear();
		int dup = 0;
		counter[INT_MIN]=1;
		for(int j = i+1; j<points.size(); j++) {
			if(points[i].x == points[j].x && points[i].y == points[j].y) {
				// take care of the dup situations
				dup++;
			}
			else {
				// deal with the corner cases
				double slp = slope(points[i], points[j]);
				if(counter.count(slp) != 0) {
					counter[slp]++;
				}
				else {
					counter[slp] = 2;
				}
			}
		}
		for(auto &x : counter) {
			if(dup + x.second > res) {
				res = dup + x.second;
			}
		}
	}
	return res;

}
};