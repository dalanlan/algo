// Range Sum Query 2D -- immutable

vector<int> sum;  //sum[row*col + col] = [row][col]
    int row;
    int col;
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        if(row == 0)
            return;
        col = matrix[0].size();
        sum.push_back(0);
    
        for(int i=0; i<row; i++) {
            for(int j=0;j<col;j++) {
                sum.push_back(sum[i*col+j]+matrix[i][j]); // matrix[0][0]~sum[1]
            }
        }    
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1; i<=row2;i++){
            res+=sum[i*col+col2+1]-sum[i*col+col1];
        }
        return res;
    }