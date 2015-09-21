int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        if(row == 0)
            return res;
        int col = grid[0].size();
        
        vector<vector<int>> visited(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(visited[i][j] == 0 && grid[i][j] == '1')
                {
                    
                    bfs(grid,visited,i,j,row,col);
                    //cout<<i<<" "<<j<<endl;
                    res++;
                }
            }
        return res;
        
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, int row, int col){
        
        queue<pair<int,int>> que;
        que.push(make_pair(i,j));
        
        while(!que.empty())
        {
            int Xindex = que.front().first;
            int Yindex = que.front().second;
            que.pop();
           // cout<<Xindex<< " "<<Yindex<<endl;
            
            visited[Xindex][Yindex] = 1;
            if(Xindex -1 >=0)
                if(grid[Xindex-1][Yindex] == '1' && visited[Xindex-1][Yindex] == 0){
                    visited[Xindex][Yindex] = 1;
                    que.push(make_pair(Xindex-1,Yindex));
                } // up
                    
            if(Xindex + 1 <row)
                if(grid[Xindex+1][Yindex] == '1' && visited[Xindex+1][Yindex] == 0) // down
                {
                    visited[Xindex+1][Yindex] = 1;
                    que.push(make_pair(Xindex+1,Yindex));
                }
                
            if(Yindex -1 >=0)
                if(grid[Xindex][Yindex-1] == '1'&& visited[Xindex][Yindex-1]==0) // left
                {
                    visited[Xindex][Yindex-1] = 1; 
                    que.push(make_pair(Xindex,Yindex-1));
                }
            if(Yindex +1 <col)
                if(grid[Xindex][Yindex+1] == '1' && visited[Xindex][Yindex+1] == 0) // right
                {
                    visited[Xindex][Yindex+1] = 1;
                    que.push(make_pair(Xindex,Yindex+1));
                    
                }
          
        }
    }