
/*
Didi online test: 
find out how many combination sums to the target number 

Allow duplicate in the combination from different indexes

*/

#include <iostream>
#include <vector>
    
using namespace std;

vector<long long> dp(2000, 0);
int main() {
	int n, sum;
    
    cin >> n>>sum;
    vector<int> num(n, 0);
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    for(int i=0; i<num.size(); i++) {
    	for(int j=sum-num[i]; j>=0; j--) {
  			if(dp[j]>0) {
  				dp[j+num[i]]+=dp[j];
  			}
    		
   		
  		}
  		dp[num[i]]++;
    }
    
    cout << dp[sum]<<endl;
    return 0;
}