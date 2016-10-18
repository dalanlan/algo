
/*
LeetCode: TRAPPING RAIN WATER
https://leetcode.com/problems/trapping-rain-water-ii/

*/


class Solution {
public:
    
    class Cell{
    public:    
        int row;
        int col; 
        int height;
        Cell(int r, int c, int h) {
            row = r;
            col = c;
            height = h;
        }
    };
    
    class Compare {
    public:
        bool operator()(const Cell *c1, const Cell *c2) const {
            return c1->height > c2->height;
        }
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int row = heightMap.size(), col = row == 0?0:heightMap[0].size();
        if(row == 0 || col == 0) {
            return 0;
        }
        
        vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
        
        // min-heap
        priority_queue<Cell*, vector<Cell*>, Compare> pq;
        int mmax = INT_MIN;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(!(i == 0 || j == 0 || i==row-1 || j==col-1)) {
                    continue;
                } 
                pq.push(new Cell(i, j, heightMap[i][j]));
                visited[i][j]=true;
            }
        }
        
      
        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        
        int res = 0;
        
        while(!pq.empty()) {
            Cell *cur = pq.top();
            pq.pop();
        
            mmax = max(mmax, cur->height);
            for(int i=0; i<4; i++) {
                int x = cur->row+dir[i].first;
                int y = cur->col+dir[i].second;
                if(x >= 0 && x < row && y>=0 && y < col && !visited[x][y]) {
              
                    res += max(0, mmax-heightMap[x][y]);
                    visited[x][y] = true;
                    pq.push(new Cell(x, y, heightMap[x][y]));
                }        
            }
        }
        return res;
        
       
        
    }
};

// solution 1: TLE
class Solution {
public:

    void color(vector<vector<int>> &cur, int i, int j, int row, int col) {
        if(i < 0 || i >= row || j < 0 || j >= col) {
            return;
        }
        if(cur[i][j] == 0) {
            cur[i][j] = 2;
            color(cur, i+1, j, row, col);
            color(cur, i-1, j, row, col);
            color(cur, i, j+1, row, col);
            color(cur, i, j-1, row, col);
        }
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int row = heightMap.size();
        int col = row==0?0:heightMap[0].size();
        if(row == 0 || col == 0) {
            return 0;
        }
        
        int mmax = INT_MIN, mmin = INT_MAX;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                mmax = max(mmax, heightMap[i][j]);
                mmin = min(mmin, heightMap[i][j]);
            }
        }
        
        int res = 0;
        
        for(int num = mmin; num <= mmax; num++) {
            vector<vector<int>> cur = vector<vector<int>>(row, vector<int>(col, num));
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(heightMap[i][j] > num) {
                        cur[i][j] = 1;
                    }
                    else {
                        cur[i][j] = 0;
                    }
                }
            }
            
            // do from outside fence
            for(int i=0; i<row; i++) {
                color(cur, i, 0, row, col);
                if(col-1 != 0) {
                    color(cur, i, col-1, row, col);
                }
            }
            
            for(int j=0; j<col; j++) {
                color(cur, 0, j, row, col);
                if(row-1 != 0) {
                    color(cur, row-1, j, row, col);
                }
            }
            
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(cur[i][j] == 0) {
                        res++;                
                    }
                }
            }
        }
        return res;
    }
};