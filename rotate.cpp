
/*
LintCode: rotate image
http://www.jiuzhang.com/solutions/rotate-image/
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        
        int count = 0;
        int n=matrix.size();
        if(n == 0) {
            return;
        }
        
        // while(count < n/2) {
        //     for(int i=count; i<n-1-count; i++) {
        //         int num = matrix[count][i];
            
        //         matrix[count][i] = matrix[n-1-i-count][count];
        //         matrix[n-1-i-count][count] = matrix[n-count-1][n-count-1-i];
        //         matrix[n-count-1][n-count-1-i] = matrix[i][n-count-1];
        //         matrix[i][n-count-1] = num;
        //     }
        //     count++;
        // }
        
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<(n+1)/2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
        return;
    }
};