
/*
GeeksforGeeks Practice 
Maximum sum increasing subsequence
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++) {
	    int N;
	    cin >> N;
	    vector<int> num(N, 0);
	    for(int j=0; j<N; j++) {
	        cin >> num[j];
	    }
	    
	    int res = 0;
	    vector<int> dp(N, 0);
	    for(int p=0; p<N; p++) {
	        dp[p] = num[p];
	        res = max(res, dp[p]);
	    }
	    for(int p=1; p<N; p++) {
	        for(int q=0; q<p; q++) {
	            if(num[q] < num[p]) {
	                dp[p] = max(dp[p], dp[q] + num[p]);
	                res = max(res, dp[p]);
	            }
	        }
	    }
	    cout<<res<<endl;
	    
	}
	
	return 0;
}