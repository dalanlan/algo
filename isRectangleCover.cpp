
/*
LeetCode: perfect rectangle
*/
class Solution {
public:
    
    bool insert(unordered_map<int, unordered_map<int, int>> &counter, int val, int x, int y) {
        int &v = counter[x][y];
        if(v & val) {
            return false;
        }
        v |= val;
        return true;
    }
    
    bool isRectangleCoverisRectangleCover(vector<vector<int>>& rectangles) {
        int maxx = INT_MIN;
        int minx = INT_MAX;
        
        int maxy = INT_MIN;
        int miny = INT_MAX;
        
        unordered_map<int, unordered_map<int, int>> counter;
        for(auto &rect: rectangles) {
            minx = min(minx, rect[0]);
            miny = min(miny, rect[1]);
            
            maxx = max(maxx, rect[2]);
            maxy = max(maxy, rect[3]);
            
            // bottom left
            if(!insert(counter, 1, rect[0], rect[1])) return false;
            // top right
            if(!insert(counter, 2, rect[2], rect[3])) return false;
            // bottom right
            if(!insert(counter, 4, rect[0], rect[3])) return false;
            //top left
            if(!insert(counter, 8, rect[2], rect[1])) return false;
            
            
            
        }
        
        // checking
        vector<bool> scan(16, false);
        scan[9]=scan[5]=scan[10]=scan[6]=scan[15]=true;
        for(auto  &x:counter) {
            int valx = x.first;
            
            for(auto &y: x.second) {
                int valy = y.first;
                int mask = y.second;
                
                if((valx != minx && valx != maxx) || (valy != miny && valy != maxy)) {
                    if(!scan[mask]) {
                        // cout<<valx <<", "<<valy<<": "<< mask<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
        
        
    }
};