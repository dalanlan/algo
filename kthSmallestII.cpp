
/*
LintCode: kth smallest number in sorted matrix
http://www.lintcode.com/zh-cn/problem/kth-smallest-number-in-sorted-matrix/
tag: priority_queue, heap, matrix
*/


class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        // priority_queue: default max-heap
        int row=matrix.size();
        if(row == 0) {
            return INT_MAX;
        }
        int col=matrix[0].size();
        if(row*col < k) {
            return INT_MAX;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                pq.push(matrix[i][j]);
            }
        }
        while(k>1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};


class Node {
public:
    int row;
    int col;
    int value;
    Node(int r, int c, int v) {
        row = r;
        col = c;
        value = v;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    struct Compare {
      bool operator()(Node const *n1, Node const *n2) const {
          return n1->value > n2->value;
      }  
    };
    
    void set(int i, int j, vector<vector<bool>> &visited, priority_queue<Node*, vector<Node*>, Compare> &pq, vector<vector<int>> &matrix, int row, int col) {
            if(i>= row || j >= col || visited[i][j]) {
                return;
            }
            visited[i][j] = true;
            pq.push(new Node(i,j,matrix[i][j]));
    }
     
    
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        
        int row=matrix.size();
        if(row == 0) {
            return INT_MAX;
        }
        int col=matrix[0].size();
        if(row*col < k) {
            return INT_MAX;
        }
        priority_queue<Node*, vector<Node*>, Compare> pq;
        pq.push(new Node(0,0,matrix[0][0]));
        
        vector<vector<bool>> visited=vector<vector<bool>>(row+1, vector<bool>(col+1, false));
        visited[0][0] = true;
        int ans;
        int r;
        int c;
        for(int i=0; i<k;i++) {
            
            Node* tmp = pq.top();
            pq.pop();
            ans = tmp->value;
            r=tmp->row;
            c=tmp->col;
            
            set(r+1, c, visited, pq, matrix, row, col);
            set(r, c+1, visited, pq, matrix, row, col);
        }
        return ans;
    }
    
};