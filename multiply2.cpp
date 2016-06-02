
/*
Leetcode: sparse matrix multiplication

Problem Description:

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

*/

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	if(A.size()==0 || B.size()==0 || A[0].size() == 0 || B[0].size() == 0) {
		return {{}};
	}

	int rowA = A.size();
	int colA = A[0].size();
	int rowB = B.size();
	int colB = B[0].size();

	// res: rowA * colB
	vector<vector<int>> res(rowA, vector<int>(colB, 0));

	for(int i=0; i<rowA; i++) {
		for(int j=0; j<colA; j++) {
			if(A[i][j]) {
				for(int k=0; k<colB; k++) {
					res[i][k] += A[i][j] * B[j][k];
				}
			}
		}
	}
	return res;


}