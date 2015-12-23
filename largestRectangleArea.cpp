// largest rectangle in histogram 

// might TLE : very simple and straight
int largestRectangleArea(vector<int>& height) {
	int res = 0, h;
	for(int i=0;i<height.size();i++) {
		h = height[i];
		
		for(int j=i; j >= 0; j--) {
			h = min(h, height[j]); 
			res = max(res, (i-j+1)*h);
		}
	}
	return res;
        
}

// prone
// I doubt it;

