/*
LeetCode: 
149. maximum points on a line
https://leetcode.com/problems/max-points-on-a-line/
*/

double slope(Point &p1, Point &p2) {
	if(p1.x == p2.x)	{
		return INT_MAX;
	}
	if(p1.y == p2.y) {
		return 0.0;
	}
	return (double)(p1.y-p2.y) / (p1.x - p2.x);
}

int maxPoints(vector<Point>& points) {
	if(points.size() == 0) {
		return 0;
	}

	unordered_map<double, int> counter;

	int res = 0;
	for(int i=0; i<points.size(); i++) {
		counter.clear();
		// to take care of duplicates
		counter[INT_MIN] = 1;
		int dup = 0;

		for(int j=i+1; j<points.size(); j++) {
			if(points[i].x == points[j].x && points[i].y == points[j].y) {
				dup++;
			}
			else {
    			double slp = slope(points[i], points[j]);
    			if(counter.count(slp) == 0) {
    				counter[slp] = 2;
    			}
    			else {
    				counter[slp]++;
    			}
			}
		}

		for(auto &x: counter) {
			res = max(res, dup + x.second);
		}
	}
	return res;

}